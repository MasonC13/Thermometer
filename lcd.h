// Mason Crim
// Jake Hoke

#include <avr/io.h>
#ifndef LCD_H
#define LCD_H

void lcdInit(uint8_t rs, uint8_t enable, uint8_t db4, uint8_t db5, uint8_t db6, uint8_t db7);
void lcdHome(void);
void lcdPutc(uint8_t c);
void lcdClear(void);
void lcdCursorOn(void);
void lcdCursorOff(void);
void lcdPuts(unsigned char *s);


#endif
