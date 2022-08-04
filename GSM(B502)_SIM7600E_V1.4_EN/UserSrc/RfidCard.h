#ifndef __RFIDCARD_H__
#define __RFIDCARD_H__
#include "config.h"

// #define WG_CARD

#define CARD_BUF_LEN 9

extern volatile uint8_t CardRt;

extern uint8_t CardCode[5];
extern bool CardReadOK;
extern bool CardGetOk;
void CardReadInit(void);
void CardIrq(void);
void CardMsTask(void);
void CheckRfidCard(void);

#ifdef WG_CARD
extern bool WgReadOK;
extern uint32_t WgCode;
void WeigenRead(void);
void WgReset(void);
void WgWdg(void);
#endif
#endif
