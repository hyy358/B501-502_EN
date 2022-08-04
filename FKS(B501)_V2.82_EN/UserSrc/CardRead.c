#include "Driver.h"
#include "RfidCard.h"
#include "stdio.h"


uint8_t CardRt = 0;
uint8_t CardGetBit = 0;
uint8_t CardBitCount = 0;
uint8_t CardChCount = 0;
uint16_t CardCh = 0;
//bool sth = false;
uint8_t RfidCardBuf[20];
uint8_t CardCode[RFID_CARD_LEN];
bool CardReadOK = false;
bool CardGetOk = false;
uint32_t CodeOld = 0;
uint8_t CodeCheckTs = 0;
uint32_t CodeIn = 0;
uint16_t CardInTime = 1000;
uint16_t CardRaw[20];
uint8_t WgTimeOut = 0;
uint32_t WG_code = 0;
uint32_t WG_bitcnt = 0;
void CardReadInit(void)
{
	CardRt = 0;
	CardGetBit = 0;
	CardCh = 0;
	CardBitCount = 0;
	CardChCount = 0;
	CardReadOK = false;
	CardGetOk = false;
}

void CardMsTask(void)
{
	if(CardInTime)
	{
		if(--CardInTime == 0)
		{
			CodeOld = 0;
			CodeCheckTs = 0;
			CodeIn = 0;
		}
	}
}

bool WG_wait = false;
bool WG_ok = false;
//时序判断
void WG_Read26(void)
{
	
	if((WG_wait == true) && ((RFID_DAT0 != 1) || (RFID_DAT1 != 1)) )  //总线待机判断
	{
		return;
	}
	WG_wait = false;                           //设置标志位判断读到卡进入奇偶校验
	
	if((RFID_DAT0 == 1) && (RFID_DAT1 == 1) )  //判断数据线0,1状态
	{
		return;
	}
	
	WG_code <<= 1;
	if((RFID_DAT0 == 0)&&(RFID_DAT1 == 1))       //状态0
	{
		
	}
	else if((RFID_DAT0 == 1)&&(RFID_DAT1 == 0))  //状态1
	{
		WG_code |= 1;
	}
	WgTimeOut = 200;
	WG_bitcnt++;
	WG_wait = true;

		if(WG_bitcnt == 26)
			{
				WG_bitcnt = 0;			
				//printf("CardRead: %lx\r\n",WG_code);
				WG_ok = true;
				CardReadOK = true;
			}
}

//奇偶校验
void WG_Send26(void)
{
	
	uint8_t one_num = 0;
	uint8_t even = 0; //偶检验
	uint8_t odd = 0; //奇检验 
	uint32_t check_temp,i;
	uint32_t code_temp;
//	uint32_t *wData;
	
//	if(NULL == WG_code)
//	{
//		return ;
//	}
	if(CardGetOk)
	{
		return;
	}
	if(WG_ok == true)
	{
	
		check_temp = ((WG_code >> 1) & 0x000FFF);      //取2-13位 偶校验 
		for(i = 0;i < 12; i++)
		{
			if(check_temp & 0x01)	
			one_num++;
			check_temp >>= 1;
		}

		if(one_num % 2 ==0)
		even = 1;
		else even = 0;

		one_num = 0;
		check_temp = ((WG_code >> 13) & 0x000FFF);      //取14-25位 奇校验 
		for(i = 0;i < 12;i++)
		{
			if(check_temp & 0x01)		
			one_num++;
			check_temp >>= 1;
		}
		
		if(one_num % 2 == 0 )
		odd = 0;
		else odd = 1;

		
		if((odd == ((WG_code >> 25) &0x01)) && (even == (WG_code & 0x01)))
		{
			code_temp = ((WG_code >> 1) & 0xFFFFFF);
			printf("CardRead: %lu\r\n",code_temp);
			CardCode[0] = (code_temp>>16)&0xFF;
			CardCode[1] = (code_temp>>8)&0xFF;
			CardCode[2] = (code_temp)&0xFF;
			CardCode[3] = 0;
			CardGetOk = true;
		}
		
		WG_ok = false;
	}
	
}

void WgReset(void)
{
	WG_code = 0;
	WG_bitcnt = 0;
	WG_ok = false;
	WgTimeOut = 0;
}

void WgWdg(void)
{
	if(WgTimeOut)
	{
		if(--WgTimeOut == 0)
		{
			WgReset();
		}
	}
}

//bool errflg = false;
//void CheckRfidCard(void)
//{
//	uint8_t i,n,k;
//	uint8_t j = 0;
//	uint32_t num;
//	uint8_t tmp;
//	uint8_t chk;
//	
//	CardInTime = 1000;
////	printf("==================\r\n");
////	for(i=0;i<4;i++)
////	{
////		printf("%04X,\r\n",CardRaw[i]);
////	}
//	i=0;
//	while(((CardRaw[0]&0x8000) == 0) && (i<16))
//	{
//		i++;
//		CardRaw[0] <<= 1;
//	}
//	if(i == 16)
//	{
//		return;
//	}
//	n = i;
//	for(i=0;i<3;i++)
//	{
//		CardRaw[i] |= CardRaw[i+1]>>(16-n);
//		CardRaw[i+1] <<= n;
//	}
//		
//	for(k=0;k<3;k++)
//	{
//		errflg = false;

//		if((k>0) && (n > 0))
//		{
//			for(i=3;i>0;i--)
//			{
//				CardRaw[i] >>= 1;
//				CardRaw[i] |= ((CardRaw[i-1]<<15)&0x8000);
//			}
//			CardRaw[0] >>= 1;
//			n--;
//		}

//		RfidCardBuf[0] = (CardRaw[0] >> 11)&0x1F;
//		RfidCardBuf[1] = (CardRaw[0] >> 6)&0x1F;
//		RfidCardBuf[2] = (CardRaw[0] >> 1)&0x1F;
//		RfidCardBuf[3] = (CardRaw[0] << 4)&0x1F;
//		
//		RfidCardBuf[3] |= (CardRaw[1] >> 12)&0x0F;
//		RfidCardBuf[4] = (CardRaw[1] >> 7)&0x1F;
//		RfidCardBuf[5] = (CardRaw[1] >> 2)&0x1F;
//		RfidCardBuf[6] = (CardRaw[1] << 3)&0x1F;
//		
//		RfidCardBuf[6] |= (CardRaw[2] >> 13)&0x0F;
//		RfidCardBuf[7] = (CardRaw[2] >> 8)&0x1F;
//		RfidCardBuf[8] = (CardRaw[2] >> 3)&0x1F;
//		RfidCardBuf[9] = (CardRaw[2] << 2)&0x1F;
//		RfidCardBuf[9] |= (CardRaw[2] >> 14)&0x0F;


//		for(i=0;i<CARD_BUF_LEN;i++)
//		{
//			tmp = (RfidCardBuf[i]>>1)&0x0F;
//			for(j=0,chk = 0;j<4;j++)
//			{
//				if((tmp & 0x01) == 0x01)
//				{
//					chk++;
//				}
//				tmp >>= 1;
//			}
//			//printf("%b02X,%bd\r\n",RfidCardBuf[i],chk);
//			chk %= 2;
//			//chk <<= 4;
//			
//			if((i%2) == 0)
//			{
//				CardCode[i/2] = (RfidCardBuf[i]<<3)&0xF0;
//			}
//			else
//			{
//				CardCode[i/2] |= (RfidCardBuf[i]>>1)&0x0F;
//			}
//				
//			if(((RfidCardBuf[i]&0x01) != chk) && (i<6))//((i/2) < (CARD_BUF_LEN/2-1)))
//			{
//				errflg = true;
//				break;
//			}		
//		}
//		if(!errflg)
//		{
//			num = CardCode[0];
//			num <<= 8;
//			num |= CardCode[1];
//			num <<= 8;
//			num |= CardCode[2];
//			num <<= 8;
//			num |= CardCode[3];
//			
//			if((CodeOld == num) && (num != 0) && (num != 0xFFFFFFFF))
//			{
//				if(++CodeCheckTs == 1)
//				{
//					CodeCheckTs = 1;
//					CardGetOk = true;//(CodeIn!=CodeOld);
//					CodeIn = CodeOld;
//					printf("CardNo:%lu\r\n",(num>>8));
//					printf("CardRead:");
//					for(i=0;i<j;i++)
//					{
//						printf("%b02X",CardCode[i]);
//					}
//					printf("\r\n");
//					return;
//				}
//			}
//			else
//			{
//				CodeOld = num;
//				CodeCheckTs = 0;
//			}
//			return;
//		}
//	}
//}

//#define CARD_TL_MIN 17
//#define CARD_TL_MAX 35
//#define CARD_TH_MIN 40
//#define CARD_TH_MAX 65
//#define CARD_LEN 16
//void CardIrq(void)
//{
//	
//	if(CardReadOK)
//	{
//		return;
//	}

//	if((CardRt >= CARD_TL_MIN) && (CardRt <= CARD_TL_MAX))
//	{
//		CardGetBit++;
//		if(((CardGetBit == 1) && (RFID_DAT == 0))
//			|| ((CardGetBit == 2) && (RFID_DAT == 1)))
//		{
//			CardGetBit = 0;
//			CardBitCount = 0;
//			return;
//		}

//		if((CardGetBit > CARD_LEN) && (CardGetBit%2) == 1)//位跳变
//		{
//			CardCh <<= 1;
//			if(RFID_DAT == 0)//上升沿为1
//			{
//				CardCh |= 0x01;
//			}
//			if(++CardBitCount == 16)
//			{
//				CardBitCount = 0;
//				CardRaw[CardChCount++] = CardCh;
//				if(CardChCount >= 5)
//				{
//					CardReadOK = true;
//				}
//			}
//		}
//	}
//	else if((CardRt >= CARD_TH_MIN) && (CardRt <= CARD_TH_MAX))
//	{	
//		if(CardGetBit <= CARD_LEN)//未接收到完整起始位
//		{
//			CardGetBit = 0;
//			CardBitCount = 0;
//			return;
//		}
//		
//		CardGetBit+=2;
//		if((CardGetBit%2) == 1)//位跳变
//		{
//			CardCh <<= 1;
//			if(RFID_DAT == 0)//上升沿为1
//			{
//				CardCh |= 0x01;
//			}
//			if(++CardBitCount == 16)
//			{
//				CardBitCount = 0;
//				CardRaw[CardChCount++] = CardCh;
//				if(CardChCount >= 5)
//				{
//					CardReadOK = true;
//				}
//			}
//		}
//	}
//	else//位错误
//	{
//		CardGetBit = 0;
//		CardBitCount = 0;
//	}
//}
