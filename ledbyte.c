// Mason Crim
// Jake Hoke

#include <avr/io.h>
#include "ledbyte.h"
   
void ledbyte(uint8_t b) {
    PORTD = b;
}         


