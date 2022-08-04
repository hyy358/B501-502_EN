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
uint8_t CardCode[5];
bool CardReadOK = false;
bool CardGetOk = false;
uint32_t CodeOld = 0;
uint8_t CodeCheckTs = 0;
uint32_t CodeIn = 0;
uint16_t CardInTime = 1000;
uint16_t CardRaw[20];
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
/*
void CheckRfidCardX(void)
{
	uint8_t i;
	uint8_t j = 0;
	uint32_t num;
	uint8_t tmp;
	uint8_t chk;
	
	CardInTime = 1000;
	
	//printf("CardBuf:");

	for(i=0;i<CARD_BUF_LEN;i++)
	{
	//	printf("%b02X",RfidCardBuf[i]);
		tmp = RfidCardBuf[i];
		for(j=0,chk = 0;j<4;j++)
		{
			if((tmp & 0x80) == 0x80)
			{
				chk++;
			}
			tmp <<= 1;
		}
		printf("%b02X,%bd\r\n",RfidCardBuf[i],chk);
		chk %= 2;
		chk <<= 3;
		if((i%2) == 0)
		{
			CardCode[i/2] = RfidCardBuf[i]&0xF0;
		}
		else
		{
			CardCode[i/2] |= RfidCardBuf[i]>>4;
		}
			
		if(((RfidCardBuf[i]&0x08) != chk) && ((i/2) < (CARD_BUF_LEN/2-1)))
		{
			CodeOld = 0;
			CodeCheckTs = 0;
			printf("\r\n");
			return;
		}		
	}
printf("\r\n");

	num = CardCode[0];
	num <<= 8;
	num |= CardCode[1];
	num <<= 8;
	num |= CardCode[2];
	num <<= 8;
	num |= CardCode[3];

	//if((CodeOld == num))// && (num != 0) && (num != 0xFFFFFFFF))
	{
		//if(++CodeCheckTs == 1)
		{
			CardGetOk = true;
			printf("CardRead:");
			for(i=0;i<j;i++)
			{
				printf("%b02X",CardCode[i]);
			}
			printf("\r\n");
			printf("CardNo:%lu\r\n",(num>>8));
		}
	}
//	else
	{
		CodeOld = num;
		CodeCheckTs = 0;
	}
}

void CardIrqX(void)
{
	if(CardReadOK)
	{
		return;
	}
	//printf("%bu, ",CardRt);return;
	if((CardRt >= 14) && (CardRt <= 35))
	{
		CardGetBit++;
		if((CardGetBit == 1) && (RFID_DAT == 1))
		{
			CardGetBit = 0;
		}
		if((CardGetBit > 19) && ((CardGetBit%2) == 1))//位跳变
		//if((CardGetBit%2) == 1)
		{
			CardCh <<= 1;
			if(RFID_DAT == 1)//上升沿为1
			{
				CardCh |= 0x08;
			}
			if(++CardBitCount == 5)
			{
				CardBitCount = 0;
				RfidCardBuf[CardChCount++] = CardCh;
				CardCh = 0;
				if(CardChCount >= CARD_BUF_LEN)
				{
					CardReadOK = true;
				}
			}
		}
	}
	else if((CardRt >= 35) && (CardRt <= 70))
	{	
		if(CardGetBit < 19)//未接收到完整起始位
		{
			CardGetBit = 0;
			CardBitCount = 0;
			CardCh = 0;
		}
		else
		{
			CardGetBit+=2;
			if((CardGetBit%2) == 1)//位跳变
			{
				CardCh <<= 1;
				if(RFID_DAT == 1)//上升沿为1
				{
					CardCh |= 0x08;
				}
				if(++CardBitCount == 5)
				{
					CardBitCount = 0;
					RfidCardBuf[CardChCount++] = CardCh;
					CardCh = 0;
					if(CardChCount == CARD_BUF_LEN)
					{
						CardReadOK = true;
					}
				}
			}
		}
	}
	else//位错误
	{
		CardGetBit = 0;
		CardBitCount = 0;
		CardCh = 0;
	}
	CardRt = 0;
}
*/
/*
void CheckRfidCard(void)
{
	uint8_t i;
	uint8_t j = 0;
	uint32_t num;
	uint8_t tmp;
	uint8_t chk;
	
	CardInTime = 1000;
	
	//printf("CardBuf:");

	for(i=0;i<CARD_BUF_LEN;i++)
	{
//		printf("%b02X",RfidCardBuf[i]);
		tmp = RfidCardBuf[i]>>1;
		for(j=0,chk = 0;j<4;j++)
		{
			if((tmp & 0x01) == 0x01)
			{
				chk++;
			}
			tmp >>= 1;
		}
//		printf("%b02X,%bd\r\n",RfidCardBuf[i],chk);
		chk %= 2;
		//chk <<= 4;
		
		if((i%2) == 0)
		{
			CardCode[i/2] = (RfidCardBuf[i]<<3)&0xF0;
		}
		else
		{
			CardCode[i/2] |= (RfidCardBuf[i]>>1)&0x0F;
		}
			
		if(((RfidCardBuf[i]&0x01) != chk) && ((i/2) < (CARD_BUF_LEN/2-1)))
		{
//			CodeOld = 0;
//			CodeCheckTs = 0;
//			printf("\r\n");
			return;
		}		
	}
//printf("\r\n");

	num = CardCode[0];
	num <<= 8;
	num |= CardCode[1];
	num <<= 8;
	num |= CardCode[2];
	num <<= 8;
	num |= CardCode[3];
	printf("CardNo:%lu\r\n",(num>>8));
	if((CodeOld == num) && (num != 0) && (num != 0xFFFFFFFF))
	{
		if(++CodeCheckTs == 3)
		{
			CodeCheckTs = 3;
			CardGetOk = (CodeIn!=CodeOld);
			CodeIn = CodeOld;
			printf("CardRead:");
			for(i=0;i<j;i++)
			{
				printf("%b02X",CardCode[i]);
			}
			printf("\r\n");
			
		}
	}
	else
	{
		CodeOld = num;
		CodeCheckTs = 0;
	}
}
void CardIrq(void)
{
	if(CardReadOK)
	{
		return;
	}
	//printf("%bu, ",CardRt);return;
	if((CardRt >= 18) && (CardRt <= 35))
	{
		CardGetBit++;
		if((CardGetBit == 1) && (RFID_DAT == 0))
		{
			CardGetBit = 0;
			return;
		}
		if((CardGetBit > 19) && ((CardGetBit%2) == 1))//位跳变
		//if((CardGetBit%2) == 1)
		{
			CardCh <<= 1;
			if(RFID_DAT == 0)//上升沿为1
			{
				CardCh |= 0x01;
			}
			if(++CardBitCount == 5)
			{
				CardBitCount = 0;
				RfidCardBuf[CardChCount++] = CardCh;
				CardCh = 0;
				if(CardChCount >= CARD_BUF_LEN)
				{
					CardReadOK = true;
				}
			}
		}
	}
	else if((CardRt >= 40) && (CardRt <= 60))
	{	
		if(CardGetBit < 19)//未接收到完整起始位
		{
			CardGetBit = 0;
			CardBitCount = 0;
			CardCh = 0;
		}
		else
		{
			CardGetBit+=2;
			if((CardGetBit%2) == 1)//位跳变
			{
				CardCh <<= 1;
				if(RFID_DAT == 0)//上升沿为1
				{
					CardCh |= 0x01;
				}
				if(++CardBitCount == 5)
				{
					CardBitCount = 0;
					RfidCardBuf[CardChCount++] = CardCh;
					CardCh = 0;
					if(CardChCount == CARD_BUF_LEN)
					{
						CardReadOK = true;
					}
				}
			}
		}
	}
	else//位错误
	{
		CardGetBit = 0;
		CardBitCount = 0;
		CardCh = 0;
	}
}
*/

bool errflg = false;
void CheckRfidCard(void)
{
	uint8_t i,n,k;
	uint8_t j = 0;
	uint32_t num;
	uint8_t tmp;
	uint8_t chk;
	
	CardInTime = 1000;
//	printf("==================\r\n");
//	for(i=0;i<4;i++)
//	{
//		printf("%04X,\r\n",CardRaw[i]);
//	}
	i=0;
	while(((CardRaw[0]&0x8000) == 0) && (i<16))
	{
		i++;
		CardRaw[0] <<= 1;
	}
	if(i == 16)
	{
		return;
	}
	n = i;
	for(i=0;i<3;i++)
	{
		CardRaw[i] |= CardRaw[i+1]>>(16-n);
		CardRaw[i+1] <<= n;
	}
		
	for(k=0;k<3;k++)
	{
		errflg = false;

		if((k>0) && (n > 0))
		{
			for(i=3;i>0;i--)
			{
				CardRaw[i] >>= 1;
				CardRaw[i] |= ((CardRaw[i-1]<<15)&0x8000);
			}
			CardRaw[0] >>= 1;
			n--;
		}

		RfidCardBuf[0] = (CardRaw[0] >> 11)&0x1F;
		RfidCardBuf[1] = (CardRaw[0] >> 6)&0x1F;
		RfidCardBuf[2] = (CardRaw[0] >> 1)&0x1F;
		RfidCardBuf[3] = (CardRaw[0] << 4)&0x1F;
		
		RfidCardBuf[3] |= (CardRaw[1] >> 12)&0x0F;
		RfidCardBuf[4] = (CardRaw[1] >> 7)&0x1F;
		RfidCardBuf[5] = (CardRaw[1] >> 2)&0x1F;
		RfidCardBuf[6] = (CardRaw[1] << 3)&0x1F;
		
		RfidCardBuf[6] |= (CardRaw[2] >> 13)&0x0F;
		RfidCardBuf[7] = (CardRaw[2] >> 8)&0x1F;
		RfidCardBuf[8] = (CardRaw[2] >> 3)&0x1F;
		RfidCardBuf[9] = (CardRaw[2] << 2)&0x1F;
		RfidCardBuf[9] |= (CardRaw[2] >> 14)&0x0F;


		for(i=0;i<CARD_BUF_LEN;i++)
		{
			tmp = (RfidCardBuf[i]>>1)&0x0F;
			for(j=0,chk = 0;j<4;j++)
			{
				if((tmp & 0x01) == 0x01)
				{
					chk++;
				}
				tmp >>= 1;
			}
			//printf("%b02X,%bd\r\n",RfidCardBuf[i],chk);
			chk %= 2;
			//chk <<= 4;
			
			if((i%2) == 0)
			{
				CardCode[i/2] = (RfidCardBuf[i]<<3)&0xF0;
			}
			else
			{
				CardCode[i/2] |= (RfidCardBuf[i]>>1)&0x0F;
			}
				
			if(((RfidCardBuf[i]&0x01) != chk) && (i<6))//((i/2) < (CARD_BUF_LEN/2-1)))
			{
				errflg = true;
				break;
			}		
		}
		if(!errflg)
		{
			num = CardCode[0];
			num <<= 8;
			num |= CardCode[1];
			num <<= 8;
			num |= CardCode[2];
			num <<= 8;
			num |= CardCode[3];
			
			if((CodeOld == num) && (num != 0) && (num != 0xFFFFFFFF))
			{
				if(++CodeCheckTs == 1)
				{
					CodeCheckTs = 1;
					CardGetOk = true;//(CodeIn!=CodeOld);
					CodeIn = CodeOld;
					printf("CardNo:%lu\r\n",(num>>8));
					printf("CardRead:");
					for(i=0;i<j;i++)
					{
						printf("%b02X",CardCode[i]);
					}
					printf("\r\n");
					return;
				}
			}
			else
			{
				CodeOld = num;
				CodeCheckTs = 0;
			}
			return;
		}
	}
}
#define CARD_LEN 16
void CardIrq(void)
{
	
	if(CardReadOK)
	{
		return;
	}

	if((CardRt >= 20) && (CardRt <= 30))
	{
		CardGetBit++;
		if(((CardGetBit == 1) && (RFID_DAT == 0))
			|| ((CardGetBit == 2) && (RFID_DAT == 1)))
		{
			CardGetBit = 0;
			CardBitCount = 0;
			return;
		}

		if((CardGetBit > CARD_LEN) && (CardGetBit%2) == 1)//位跳变
		{
			CardCh <<= 1;
			if(RFID_DAT == 0)//上升沿为1
			{
				CardCh |= 0x01;
			}
			if(++CardBitCount == 16)
			{
				CardBitCount = 0;
				CardRaw[CardChCount++] = CardCh;
				if(CardChCount >= 5)
				{
					CardReadOK = true;
				}
			}
		}
	}
	else if((CardRt >= 45) && (CardRt <= 58))
	{	
		if(CardGetBit <= CARD_LEN)//未接收到完整起始位
		{
			CardGetBit = 0;
			CardBitCount = 0;
			return;
		}
		
		CardGetBit+=2;
		if((CardGetBit%2) == 1)//位跳变
		{
			CardCh <<= 1;
			if(RFID_DAT == 0)//上升沿为1
			{
				CardCh |= 0x01;
			}
			if(++CardBitCount == 16)
			{
				CardBitCount = 0;
				CardRaw[CardChCount++] = CardCh;
				if(CardChCount >= 5)
				{
					CardReadOK = true;
				}
			}
		}
	}
	else//位错误
	{
		CardGetBit = 0;
		CardBitCount = 0;
	}
}
#ifdef WG_CARD
uint32_t WgCode = 0;
uint8_t WgBitCnt = 0;
uint8_t WgTimeOut = 0;
bool WgWait = false;
bool WgReadOK = false;
void WeigenRead(void)
{
	if(WgReadOK)
	{
		return;
	}
	if(WgWait && ((WG_D0 != 1) || (WG_D1 != 1)))
	{
		return;
	}
	
	WgWait = false;
	if((WG_D0 == 1) && (WG_D1 == 1))
	{
		return;
	}
	WgTimeOut = 200;
	WgWait = true;
	WgCode <<= 1;
	if((WG_D0 == 0) && (WG_D1 == 0))//err
	{
		WgCode = 0;
		WgBitCnt = 0;
		return;
	}
	else if((WG_D0 == 0) && (WG_D1 == 1))
	{
		WgCode |= 1;
	}
	if(++WgBitCnt >= 26)
	{
		WgReadOK = true;
		//printf("WgReadOK %LX\r\n",WgCode);
		WgCode = (WgCode>>1)&0xFFFFFF;
		CardCode[0] = (WgCode>>16)&0xFF;
		CardCode[1] = (WgCode>>8)&0xFF;
		CardCode[2] = (WgCode)&0xFF;
		CardCode[3] = 0;
		
		printf("WgReadOK %lu\r\n",WgCode);
	}		
}
void WgReset(void)
{
	WgCode = 0;
	WgBitCnt = 0;
	WgReadOK = false;
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
#endif
