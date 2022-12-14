#ifndef __RFIDCARD_H__
#define __RFIDCARD_H__
#include "config.h"

#define WG_CARD

#define CARD_BUF_LEN 9
#define RFID_CARD_LEN 4

extern volatile uint8_t CardRt;

extern uint8_t CardCode[RFID_CARD_LEN];
extern bool CardReadOK;
extern bool CardGetOk;

void CardReadInit(void);
void WG_Read26(void);
void WG_Send26(void);
//void CardIrq(void);
void CardMsTask(void);
void CheckRfidCard(void);
void WgReset(void);
void WgWdg(void);
#endif
