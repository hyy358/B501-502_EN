/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC 1T Series MCU Demo Programme -------------------------------*/
/* --- Mobile: (86)13922805190 ----------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ------------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ------------------------*/
/* --- Web: www.STCMCU.com --------------------------------------------*/
/* --- Web: www.STCMCUDATA.com  ---------------------------------------*/
/* --- QQ:  800003751 -------------------------------------------------*/
/* ���Ҫ�ڳ�����ʹ�ô˴���,���ڳ�����ע��ʹ����STC�����ϼ�����            */
/*---------------------------------------------------------------------*/

#include "PWM.h"

u8 PWM_Configuration(u8 PWM, PWMx_InitDefine *PWMx)
{
	if(PWM == PWMA)
	{
		EAXSFR();		/* MOVX A,@DPTR/MOVX @DPTR,Aָ��Ĳ�������Ϊ��չSFR(XSFR) */
		
		if(PWMx->PWM1_SetPolity > Polity_3)	return 2;	//����
		PWM1_Polity(PWMx->PWM1_SetPolity);	//ָ���ж����ȼ�(�͵���) Polity_0,Polity_1,Polity_2,Polity_3
		if(PWMx->PWM2_SetPolity > Polity_3)	return 2;	//����
		PWM2_Polity(PWMx->PWM2_SetPolity);	//ָ���ж����ȼ�(�͵���) Polity_0,Polity_1,Polity_2,Polity_3
		if(PWMx->PWM3_SetPolity > Polity_3)	return 2;	//����
		PWM3_Polity(PWMx->PWM3_SetPolity);	//ָ���ж����ȼ�(�͵���) Polity_0,Polity_1,Polity_2,Polity_3
		if(PWMx->PWM4_SetPolity > Polity_3)	return 2;	//����
		PWM4_Polity(PWMx->PWM4_SetPolity);	//ָ���ж����ȼ�(�͵���) Polity_0,Polity_1,Polity_2,Polity_3
		
		PWMA_CCER1_Disable();		//�ر��������벶��/�Ƚ����
		PWMA_CCER2_Disable();		//�ر��������벶��/�Ƚ����
		PWMA_OC1ModeSet(PWMx->PWM1_Mode);		//��������Ƚ�ģʽ
		PWMA_OC2ModeSet(PWMx->PWM2_Mode);		//��������Ƚ�ģʽ
		PWMA_OC3ModeSet(PWMx->PWM3_Mode);		//��������Ƚ�ģʽ
		PWMA_OC4ModeSet(PWMx->PWM4_Mode);		//��������Ƚ�ģʽ
		if(PWMx->PWM_Reload == ENABLE)	PWMA_OC1_ReloadEnable();	//����Ƚϵ�Ԥװ��ʹ��
		else		PWMA_OC1_RelosdDisable();	//��ֹ����Ƚϵ�Ԥװ��
		if(PWMx->PWM_Fast == ENABLE)	PWMA_OC1_FastEnable();		//����ȽϿ��ٹ���ʹ��
		else		PWMA_OC1_FastDisable();	//��ֹ����ȽϿ��ٹ���
		
		if(PWMx->PWM_CC1Enable == ENABLE)	PWMA_CC1E_Enable();			//�������벶��/�Ƚ����
		else		PWMA_CC1E_Disable();	//�ر����벶��/�Ƚ����
		if(PWMx->PWM_CC1NEnable == ENABLE)	PWMA_CC1NE_Enable();	//�������벶��/�Ƚ����
		else		PWMA_CC1NE_Disable();	//�ر����벶��/�Ƚ����
		if(PWMx->PWM_CC2Enable == ENABLE)	PWMA_CC2E_Enable();			//�������벶��/�Ƚ����
		else		PWMA_CC2E_Disable();	//�ر����벶��/�Ƚ����
		if(PWMx->PWM_CC2NEnable == ENABLE)	PWMA_CC2NE_Enable();	//�������벶��/�Ƚ����
		else		PWMA_CC2NE_Disable();	//�ر����벶��/�Ƚ����
		if(PWMx->PWM_CC3Enable == ENABLE)	PWMA_CC3E_Enable();			//�������벶��/�Ƚ����
		else		PWMA_CC3E_Disable();	//�ر����벶��/�Ƚ����
		if(PWMx->PWM_CC3NEnable == ENABLE)	PWMA_CC3NE_Enable();	//�������벶��/�Ƚ����
		else		PWMA_CC3NE_Disable();	//�ر����벶��/�Ƚ����
		if(PWMx->PWM_CC4Enable == ENABLE)	PWMA_CC4E_Enable();			//�������벶��/�Ƚ����
		else		PWMA_CC4E_Disable();	//�ر����벶��/�Ƚ����
		if(PWMx->PWM_CC4NEnable == ENABLE)	PWMA_CC4NE_Enable();	//�������벶��/�Ƚ����
		else		PWMA_CC4NE_Disable();	//�ر����벶��/�Ƚ����
		
		PWMA_AutoReload(PWMx->PWM_Period);
		PWMA_Duty1(PWMx->PWM1_Duty);
		PWMA_Duty2(PWMx->PWM2_Duty);
		PWMA_Duty3(PWMx->PWM3_Duty);
		PWMA_Duty4(PWMx->PWM4_Duty);
		
		PWMA_CCPCAPreloaded(PWMx->PWM_PreLoad);	//����/�Ƚ�Ԥװ�ؿ���λ(��λֻ�Ծ��л��������ͨ��������)
		PWMA_PS = PWMx->PWM_PS_SW;			//�л�IO
		PWMA_ENO = PWMx->PWM_EnoSelect;	//���ͨ��ѡ��
		PWMA_DeadTime(PWMx->PWM_DeadTime);	//��������������
		
		if(PWMx->PWM_BrakeEnable == ENABLE)	PWMA_BrakeEnable();	//����ɲ������
		else		PWMA_BrakeDisable();		//��ֹɲ������
		if(PWMx->PWM_MainOutEnable == ENABLE)	PWMA_BrakeOutputEnable();	//�����ʹ��
		else		PWMA_BrakeOutputDisable();		//�������ֹ
		if(PWMx->PWM_CEN_Enable == ENABLE)	PWMA_CEN_Enable();	//ʹ�ܼ�����
		else		PWMA_CEN_Disable();		//��ֹ������
		
		EAXRAM();		/* MOVX A,@DPTR/MOVX @DPTR,Aָ��Ĳ�������Ϊ��չRAM(XRAM) */
		return	0;
	}

	if(PWM == PWMB)
	{
		EAXSFR();		/* MOVX A,@DPTR/MOVX @DPTR,Aָ��Ĳ�������Ϊ��չSFR(XSFR) */
		
		if(PWMx->PWM5_SetPolity > Polity_3)	return 2;	//����
		PWM5_Polity(PWMx->PWM5_SetPolity);	//ָ���ж����ȼ�(�͵���) Polity_0,Polity_1,Polity_2,Polity_3
		
		PWMB_CCER1_Disable();		//�ر��������벶��/�Ƚ����
		PWMB_CCER2_Disable();		//�ر��������벶��/�Ƚ����
		PWMB_OC5ModeSet(PWMx->PWM5_Mode);		//��������Ƚ�ģʽ
		PWMB_OC6ModeSet(PWMx->PWM6_Mode);		//��������Ƚ�ģʽ
		PWMB_OC7ModeSet(PWMx->PWM7_Mode);		//��������Ƚ�ģʽ
		PWMB_OC8ModeSet(PWMx->PWM8_Mode);		//��������Ƚ�ģʽ
		if(PWMx->PWM_Reload == ENABLE)	PWMB_OC5_ReloadEnable();	//����Ƚϵ�Ԥװ��ʹ��
		else		PWMB_OC5_RelosdDisable();	//��ֹ����Ƚϵ�Ԥװ��
		if(PWMx->PWM_Fast == ENABLE)	PWMB_OC5_FastEnable();		//����ȽϿ��ٹ���ʹ��
		else		PWMB_OC5_FastDisable();	//��ֹ����ȽϿ��ٹ���
		
		if(PWMx->PWM_CC5Enable == ENABLE)	PWMB_CC5E_Enable();			//�������벶��/�Ƚ����
		else		PWMB_CC5E_Disable();	//�ر����벶��/�Ƚ����
		if(PWMx->PWM_CC6Enable == ENABLE)	PWMB_CC6E_Enable();			//�������벶��/�Ƚ����
		else		PWMB_CC6E_Disable();	//�ر����벶��/�Ƚ����
		if(PWMx->PWM_CC7Enable == ENABLE)	PWMB_CC7E_Enable();			//�������벶��/�Ƚ����
		else		PWMB_CC7E_Disable();	//�ر����벶��/�Ƚ����
		if(PWMx->PWM_CC8Enable == ENABLE)	PWMB_CC8E_Enable();			//�������벶��/�Ƚ����
		else		PWMB_CC8E_Disable();	//�ر����벶��/�Ƚ����
		
		PWMB_AutoReload(PWMx->PWM_Period);
		PWMB_Duty5(PWMx->PWM5_Duty);
		PWMB_Duty6(PWMx->PWM6_Duty);
		PWMB_Duty7(PWMx->PWM7_Duty);
		PWMB_Duty8(PWMx->PWM8_Duty);
		
		PWMB_CCPCBPreloaded(PWMx->PWM_PreLoad);	//����/�Ƚ�Ԥװ�ؿ���λ(��λֻ�Ծ��л��������ͨ��������)
		PWMB_PS = PWMx->PWM_PS_SW;			//�л�IO
		PWMB_ENO = PWMx->PWM_EnoSelect;	//���ͨ��ѡ��
		PWMB_DeadTime(PWMx->PWM_DeadTime);	//��������������
		
		if(PWMx->PWM_BrakeEnable == ENABLE)	PWMB_BrakeEnable();	//����ɲ������
		else		PWMB_BrakeDisable();		//��ֹɲ������
		if(PWMx->PWM_MainOutEnable == ENABLE)	PWMB_BrakeOutputEnable();	//�����ʹ��
		else		PWMB_BrakeOutputDisable();		//�������ֹ
		if(PWMx->PWM_CEN_Enable == ENABLE)	PWMB_CEN_Enable();	//ʹ�ܼ�����
		else		PWMB_CEN_Disable();		//��ֹ������
		
		EAXRAM();		/* MOVX A,@DPTR/MOVX @DPTR,Aָ��Ĳ�������Ϊ��չRAM(XRAM) */
		return	0;
	}

	return	2;	//����
}

/*********************************************************/

/******************* PWM ռ�ձ����ú��� *******************/
void UpdatePwm(u8 PWM, PWMx_Duty *PWMx)
{
	EAXSFR();		/* MOVX A,@DPTR/MOVX @DPTR,Aָ��Ĳ�������Ϊ��չSFR(XSFR) */

	if(PWM == PWMA)
	{
		PWMA_Duty1(PWMx->PWM1_Duty);
		PWMA_Duty2(PWMx->PWM2_Duty);
		PWMA_Duty3(PWMx->PWM3_Duty);
		PWMA_Duty4(PWMx->PWM4_Duty);
	}
	else
	{
		PWMB_Duty5(PWMx->PWM5_Duty);
		PWMB_Duty6(PWMx->PWM6_Duty);
		PWMB_Duty7(PWMx->PWM7_Duty);
		PWMB_Duty8(PWMx->PWM8_Duty);
	}
	
	EAXRAM();		/* MOVX A,@DPTR/MOVX @DPTR,Aָ��Ĳ�������Ϊ��չRAM(XRAM) */
}

/*********************************************************/