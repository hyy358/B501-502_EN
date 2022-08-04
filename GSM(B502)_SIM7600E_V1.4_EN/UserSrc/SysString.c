#include "SysString.h"
#include "Lcd12864.h"
#include "stdio.h"
#include "GSM.h"
#include "Audio.h"
#include "SysStatus.h"

//code uint8_t FhChar[]={"0\"/:()'_- "};
code uint8_t FhChar[]={"-\"/:()'_"};

#ifdef LANGUAGE_EN
code char StrTabSysSet[] = {"System settings"};
code char StrTabSysSet1[] = {"1-13"};

code char StrTabNameSet1[] = {"1-Add/Edit user"};
code char StrTabNameSet2[] = {"2-Delete user"};
code char StrTabNameSet3[] = {"3-DeleteAllusers"};
code char StrTabDelAllName[] = {"Delete all      Users?"};
code char StrTabRoom[] = {"Apartment:"};
code char StrTabName[] = {"Name:"};
code char StrTabTel[] = {"Tel"};
code char StrTabMakeSure[] = {" Confirm Save ?"};
code char StrTabSaveOK[] = {"Save!"};
code char StrTabErr[] = {"Error!"};

code char StrTabDel[] = {"Confirm         Deletion?"};
code char StrTabDelOK[] = {"   Deleted !"};
code char StrTabDelAllPsw[] = {"Delete all      Passwords?"};
code char StrTabPswSet1[] = {"1-Add a Password"};
code char StrTabPswSet2[] = {"2-DeletePassword"};
code char StrTabPswSet3[] = {"3-Delete all "};
code char StrTabPsw1[] = {"Password:"};
code char StrTabPsw3[] = {"Confirm"};
code char StrTabPsw2[] = {"Password:"};

code char StrTabListCount[] = {"Total:"};
code char StrTabSysPsw[] = {"Admin password:"};

code char StrTabCardSet1[] = {"1-Add a card"};
code char StrTabCardSet2[] = {"2-Delete card"};
code char StrTabCardSet3[] = {"3-DeleteAllcards"};
code char StrTabDelAllCard[] = {"Delete all      cards?"};
code char StrTabCard[] = {"Card:"};
code char StrTabCardErr[] = {"Card Error!"};
code char StrTabUnlock[] = {"The door is open!"};

code char StrTabCall[] = {"Calling: "};

code char StrTabTalkTime[] = {"Talk time:"};
//code char StrTabRingTime[] = {"RingTime:"};
code char StrTabRingTime[] = {"Call panel:"};
code char StrTabCallTime[] = {"Ring time:"};
code char StrTabTone[] = {"Voice           Instructions:"};
code char StrTabCamrea[] = {"Camera:"};
code char StrTabRelay[] = {"Relay time:"};

code char StrTabOn[] = {"On"};
code char StrTabOff[] = {"Off"};

code char StrTabGsmErr[] = {"  Gsm Error!"};
//code char StrTabGsmCsq[] = {"Csq:"};
//code char StrTabGsmCsqErr[] = {"No Signal"};
code char StrTabSimCardReady[] = {"Active SIM"};
code char StrTabNotSimCard[] = {"SIM not exist"};
code char StrTabSimCardBusy[] = {"Inactive SIM"};
code char StrTabGsmCsqErr[] = {"No Signal"};
code char StrTabGsmCsqLow[] = {"Low signal"};
code char StrTabGsmCsqMed[] = {"Medium signal"};
code char StrTabGsmCsqGood[] = {"High signal"};

code char StrTabMain1[] = {"To cancel press"};
code char StrTabMain2[] = {"select a name"};
code char StrTabMain3[] = {"from the list"};
code char StrTabMain4[] = {"press"};

code char StrTabMain5[] = {"Welcome!"};
code char StrTabMain6[] = {"To call -"};
code char StrTabMain7[] = {"Enter apartment"};
code char StrTabMain8[] = {"number + "};

code char StrTabMain9[] = {"To call,press"};
code char StrTabMain10[] = {"To unlock,press"};
code char StrTabMain11[] = {"+ 4 Digits code"};
code char StrTabRoomErr[] = {"Apartment Error!"};
code char StrTabTalk[] = {"Talking:"};

code char StrTabReset[] = {"Reset OK!"};
code char StrTabUnlockKey[] = {"CMD Door        Open 1:"};
code char StrTabUnlockKey2[]= {"CMD Door        Open 2:"};

code char StrTabTalkValum[] = {"Speech volume:"};
code char StrTabNum[] = {"Room: "};
code char StrTabSms[] = {"Sms"};

#endif

#ifdef LANGUAGE_HB
code char StrTabSysSet[] = {"הגדרת מערכת"};
code char StrTabSysSet1[] = {"1-13"};

code char StrTabNameSet1[] = {"1-הוסף/ערוך שם"};
code char StrTabNameSet2[] = {"2-מחק שם"};
code char StrTabNameSet3[] = {"3- מחק הכל"};
code char StrTabDelAllName[] = {"האם למחוק הכל ?"};
code char StrTabRoom[] = {"דירה: "};
code char StrTabNum[] = {"תא: "};
code char StrTabName[] = {"שם:"};
code char StrTabTel[] = {"טל"};//{"טלפון"};
code char StrTabMakeSure[] = {" לאשר שמירה?"};
code char StrTabSaveOK[] = {"   שמור!"};
code char StrTabErr[] = {"  שגיאה!"};

code char StrTabDel[] = {"לאשר מחיקה ?"};
code char StrTabDelOK[] = {"  נמחק!"};
code char StrTabDelAllPsw[] = {"האם למחוק הכל ?"};
code char StrTabPswSet1[] = {"1- הוסף סיסמה"};
code char StrTabPswSet2[] = {"2-מחק סיסמה"};
code char StrTabPswSet3[] = {"3-מחק הכל"};
code char StrTabPsw1[] = {"סיסמה:"};
code char StrTabPsw2[] = {"אשר:"};

code char StrTabListCount[] = {"סך הכל:"};
code char StrTabSysPsw[] = {"סיסמת מנהל"};

code char StrTabCardSet1[] = {"1-הוסף כרטיס"};
code char StrTabCardSet2[] = {"2-מחיקת כרטיס"};
code char StrTabCardSet3[] = {"3-מחק הכל"};
code char StrTabDelAllCard[] = {"האם למחוק הכל ?"};
code char StrTabCard[] = {"כרטיס:"};
code char StrTabCardErr[] = {"  שגיאת כרטיס!"};
code char StrTabUnlock[] = {"  דלת נפתחת!"};
code char StrTabTalkValum[] = {"עוצמת דיבור"};

code char StrTabCall[] = {"מצלצל:"};

code char StrTabTalkTime[] = {"זמן דיבור:"};
//code char StrTabRingTime[] = {"זמן צלצול:"};
code char StrTabRingTime[] = {"התקשרות לפנל:"};
code char StrTabCallTime[] = {"זמן צלצול:"};//{"זמן שיחה:"};
code char StrTabTone[] = {"הנחיות קוליות:"};
code char StrTabCamrea[] = {"מצלמה:"};
code char StrTabRelay[] = {"זמן ממסר:"};
code char StrTabUnlockKey[] = {"מקש פ.דלת 1:"};
code char StrTabUnlockKey2[] = {"מקש פ.דלת 2:"};

code char StrTabOn[] = {"פעיל"};
code char StrTabOff[] = {"כבוי"};

code char StrTabGsmErr[] = {"שגיאת כרטיס סים!"};
//code char StrTabGsmCsq[] = {"Csq:"};
//code char StrTabGsmCsqErr[] = {"אין קליטה"};
code char StrTabSimCardReady[] = {"סים פעיל"};
code char StrTabNotSimCard[] = {"סים לא קיים"};
code char StrTabSimCardBusy[] = {"סים תפוס"};
code char StrTabGsmCsqErr[] = {"אין קליטה"};
code char StrTabGsmCsqLow[] = {"קליטה נמוכה"};
code char StrTabGsmCsqMed[] = {"קליטה בינונית"};
code char StrTabGsmCsqGood[] = {"קליטה טובה"};

code char StrTabMainA1[] = {"ברוכים הבאים!"};
code char StrTabMainA2[] = {"לצלצול לדירה"};
code char StrTabMainA3[] = {"לחצו מספר דירה"};
code char StrTabMainA4[] = {"לביטול לחצו"};

code char StrTabMain1[] = {"לרשימת שמות"};
code char StrTabMain2[] = {" לבחירת שם לחצו"};
code char StrTabMain3[] = {"לכניסה עם קוד"};
code char StrTabMain4[] = {"לחצו   וקוד"};

code char StrTabRoomErr[] = {" שגיאה בדירה!"};
code char StrTabTalk[] = {"שיחה:"};

code char StrTabReset[] = {"Reset OK!"};

code char StrTabSms[] = {"Sms"};

#endif
//code char StrTabGsmCsqErr[] = {"אבגדהוזחטיךכלםמןנסעףפץצקרשת"};
//code char StrTabMain1[] = {"אבגדהוזחטיךכלםמן"};
//code char StrTabMain2[] = {"נסעףפץצקרשת"};

char DisBuf[20];

void ShowConfirmSave(void)
{
	LcdClear();
	DisplayString(1,0,StrTabMakeSure);
}
void ShowConfirmDel(void)
{
	LcdClear();
	DisplayString(1,0,StrTabDel);
}
void ShowSaveOK(void)
{
	LcdClear();
	DisplayString(1,0,StrTabSaveOK);
	MP3_StartPlay(MP3_SetOK);
}
void ShowErr(void)
{
	LcdClear();
	DisplayString(1,0,StrTabErr);
	MP3_StartPlay(MP3_Failed);
}
void ShowDeleteOK(void)
{
	LcdClear();
	DisplayString(1,0,StrTabDelOK);
	MP3_StartPlay(MP3_SetOK);
}

void ShowCardErr(void)
{
	LcdClear();
	DisplayString(1,0,StrTabCardErr);
	MP3_StartPlay(MP3_CardErr);
}
void ShowUnlock(bool Sound)
{
	LcdClear();
	DisplayString(1,0,StrTabUnlock);
	if(Sound)
	{
		MP3_StartPlay(MP3_Unlock);
	}
}

void ShowGsmErr(void)
{
	LcdClear();
	DisplayString(1,0,StrTabGsmErr);
	MP3_StartPlay(MP3_Noresponse);
}

void ShowRoomErr(void)
{
	LcdClear();
	DisplayString(1,0,StrTabRoomErr);
	
}

void ShowGsmCsq(void)
{
	if(SysStatus != SYS_IDLE)
	{
		return;
	}
	DisplayString(3,0,"                ");
	if((GsmCsq == 0xFE))
	{
		DisplayString(3,0,StrTabNotSimCard);
		return;
	}
	else if((GsmCsq == 0xFD))
	{
		DisplayString(3,0,StrTabSimCardBusy);
		return;
	}
	else if((GsmCsq == 0xFC))
	{
		DisplayString(3,0,StrTabSimCardReady);
		return;
	}
	else if((GsmCsq == 0xff) || (GsmCsq < 5))
	{
		DisplayString(3,0,StrTabGsmCsqErr);
		//DisplayCsq(0,0,0);
		//DisplayIco(0,1,6);
		return;
	}
//	DisplayCsq(0,0,GsmCsq);
	
	if(GsmCsq < 18)
	{
		DisplayString(3,0,StrTabGsmCsqLow);
	}
	else if(GsmCsq < 25)
	{
		DisplayString(3,0,StrTabGsmCsqMed);
	}
	else
	{
		DisplayString(3,0,StrTabGsmCsqGood);
	}
//	sprintf(DisBuf,"%s%bd",StrTabGsmCsq,GsmCsq);
//	DisplayString(0,0,DisBuf);
	
//	DisplayIco(0,0,0);
//	DisplayIco(0,1,1);
//	DisplayIco(0,2,2);
//	DisplayIco(0,3,3);
//	DisplayIco(0,4,4);
//	DisplayIco(0,5,5);
//	DisplayIco(0,6,6);
	
}

void ShowMain(uint8_t first)
{
	//if((first != 0) && (first != 3) && (first != 5) && (first != 8))
//	if((first != 0) && (first != 5))
//	{
//		return;
//	}
	LcdClear();
#ifdef LANGUAGE_HB	
//	if((first == 3) || (first == 8))
//	{
//		ShowGsmCsq();
//		return;
//	}
	if(first == 0)
	{
		DisplayString(0,0,StrTabMainA1);
		DisplayString(1,0,StrTabMainA2);
		DisplayString(2,0,StrTabMainA3);
		DisplayIco(2,0,2);
		DisplayString(3,0,StrTabMainA4);
		DisplayIco(3,1,8);
	}
	else// if(first == 5)
	{
		
		DisplayString(0,0,StrTabMain1);
		DisplayIco(0,3,0);
		DisplayIco(0,4,1);
		
		DisplayString(1,0,StrTabMain2);
		DisplayIco(1,0,2);
		
		DisplayString(2,0,StrTabMain3);
		
//		DisplayString(3,0,StrTabMain4);
//		DisplayIco(3,10,3);
		
		ShowGsmCsq();
	}

//#ifdef LANGUAGE_EN	
//	if((first == 3) || (first == 8))
//	{
//		ShowGsmCsq();
//		return;
//	}
//	LcdClear();
//	DisplayString(0,6,StrTabMain1);
//	DisplayIco(0,3,0);
//	DisplayIco(0,4,1);
//	
//	DisplayString(1,1,StrTabMain2);
//	DisplayIco(1,2,2);
//	
//	
//	DisplayString(2,0,StrTabMain3);
//	DisplayIco(2,5,2);
//	
//	DisplayString(3,3,StrTabMain4);
//	DisplayIco(3,1,3);
#else LANGUAGE_EN
	if(first == 0)
	{
		DisplayString(0,0,StrTabMain5);
		//DisplayIco(0,7,4);
		
		DisplayString(1,0,StrTabMain6);
		
		DisplayString(2,0,StrTabMain7);
		
		DisplayString(3,0,StrTabMain8);
		DisplayIco(3,9,2); //铃铛
//		DisplayIco(3,7,0);
//		DisplayIco(3,8,1); //上下键
	}

	else if(first == 1)
	{
		DisplayString(0,0,StrTabMain1);
		DisplayIco(0,15,4);
	//	DisplayIco(0,3,1);
		
		DisplayString(1,0,StrTabMain2);
	//	DisplayIco(1,2,2);
		
		
		DisplayString(2,0,StrTabMain3);
		//DisplayIco(2,5,2); //
		
		DisplayString(3,0,StrTabMain4);
		DisplayIco(3,6,0);
		DisplayIco(3,8,1); //上下键
		//DisplayIco(3,12,2); //铃铛
	}

	else if(first == 2)
	{
		DisplayString(0,0,StrTabMain9);
		DisplayIco(0,14,2); //铃铛
		
		DisplayString(1,0,StrTabMain10);
		DisplayIco(1,15,3); //钥匙
		
		DisplayString(2,0,StrTabMain11);
		
		ShowGsmCsq();
	}
	
#endif
}

void ShowTalkTime(void)
{
	LcdClear();
#ifdef LANGUAGE_HB
	DisplayString(1,0,StrTabTalk);
	sprintf(DisBuf,"%u",TalkTime);
	DisplayString(1,8,DisBuf);
#else
	sprintf(DisBuf,"%s%u",StrTabTalk,TalkTime);
	DisplayString(1,0,DisBuf);
#endif
}
void ShowReset(void)
{
	LcdClear();
	DisplayString(1,0,StrTabReset);
}
