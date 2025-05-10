// Mason Crim
// Jake Hoke

#include <avr/io.h>
#include "lcd.h"

#define CTRL_PORT PORTD  // Control signals (RS, ENABLE) are on PORTD
#define DATA_PORT PORTB  // Data signals (DB4, DB5, DB6, DB7) are on PORTB


void delay1us( uint16_t n);
void delay1ms( uint16_t n);

uint8_t rs = 0;
uint8_t enable = 0;
uint8_t db4 = 0;
uint8_t db5 = 0;
uint8_t db6 = 0;
uint8_t db7 = 0;

// Function to set a pin as output based on passed pin number
void setPinAsOutput(uint8_t pin) {
    if (pin == 12) {
        DDRD |= (1 << PD6);  // RS pin is PD6
    } else if (pin == 13) {
        DDRD |= (1 << PD7);  // ENABLE pin is PD7
    } else if (pin == 14) {
        DDRB |= (1 << PB0);  // DB4 pin is PB0
    } else if (pin == 15) {
        DDRB |= (1 << PB1);  // DB5 pin is PB1
    } else if (pin == 16) {
        DDRB |= (1 << PB2);  // DB6 pin is PB2
    } else if (pin == 17) {
        DDRB |= (1 << PB3);  // DB7 pin is PB3
    }
}


void setPinHigh(uint8_t pin){
    if (pin == 1) {
        PORTC |= (1 << PC6);  // RS pin is PC6
    }
    if (pin == 2) {
        PORTD |= (1 << PD0);  // RS pin is PD0
    }
    if (pin == 3) {
        PORTD |= (1 << PD1);  // RS pin is PD1
    }
    if (pin == 4) {
        PORTD |= (1 << PD2);  // RS pin is PD2
    }
    if (pin == 5) {
        PORTD |= (1 << PD3);  // RS pin is PD3
    }
    if (pin == 6) {
        PORTD |= (1 << PD4);  // RS pin is PD4
    }
    if (pin == 9) {
        PORTB |= (1 << PB6);  // RS pin is PB6
    }
    if (pin == 10) {
        PORTB |= (1 << PB7);  // RS pin is PB7
    }
    if (pin == 11) {
        PORTD |= (1 << PD5);  // RS pin is PD5
    }
    if (pin == 12) {
        PORTD |= (1 << PD6);  // RS pin is PD6
    }
    if (pin == 13) {
        PORTD |= (1 << PD7);  // RS pin is PD7
    }
    if (pin == 14) {
        PORTB |= (1 << PB0);  // RS pin is PB0
    }
    if (pin == 15) {
        PORTB |= (1 << PB1);  // RS pin is PB1
    }
    if (pin == 16) {
        PORTB |= (1 << PB2);  // RS pin is PB2
    }
    if (pin == 17) {
        PORTB |= (1 << PB3);  // RS pin is PB3
    }
    if (pin == 18) {
        PORTB |= (1 << PB4);  // RS pin is PB4
    }
    if (pin == 19) {
        PORTB |= (1 << PB5);  // RS pin is PB5
    }
    if (pin == 23) {
        PORTC |= (1 << PC0);  // RS pin is PC0
    }
    if (pin == 24) {
        PORTC |= (1 << PC1);  // RS pin is PC1
    }
    if (pin == 25) {
        PORTC |= (1 << PC2);  // RS pin is PC2
    }
    if (pin == 26) {
        PORTC |= (1 << PC3);  // RS pin is PC3
    }
    if (pin == 27) {
        PORTC |= (1 << PC4);  // RS pin is PC4
    }
    if (pin == 28) {
        PORTC |= (1 << PC5);  // RS pin is PC5
    }
}

void setPinLow(uint8_t pin){
    if (pin == 1) {
        PORTC &= ~(1 << PC6);  // RS pin is PC6
    }
    if (pin == 2) {
        PORTD &= ~(1 << PD0);  // RS pin is PD0
    }
    if (pin == 3) {
        PORTD &= ~(1 << PD1);  // RS pin is PD1
    }
    if (pin == 4) {
        PORTD &= ~(1 << PD2);  // RS pin is PD2
    }
    if (pin == 5) {
        PORTD &= ~(1 << PD3);  // RS pin is PD3
    }
    if (pin == 6) {
        PORTD &= ~(1 << PD4);  // RS pin is PD4
    }
    if (pin == 9) {
        PORTB &= ~(1 << PB6);  // RS pin is PB6
    }
    if (pin == 10) {
        PORTB &= ~(1 << PB7);  // RS pin is PB7
    }
    if (pin == 11) {
        PORTD &= ~(1 << PD5);  // RS pin is PD5
    }
    if (pin == 12) {
        PORTD &= ~(1 << PD6);  // RS pin is PD6
    }
    if (pin == 13) {
        PORTD &= ~(1 << PD7);  // RS pin is PD7
    }
    if (pin == 14) {
        PORTB &= ~(1 << PB0);  // RS pin is PB0
    }
    if (pin == 15) {
        PORTB &= ~(1 << PB1);  // RS pin is PB1
    }
    if (pin == 16) {
        PORTB &= ~(1 << PB2);  // RS pin is PB2
    }
    if (pin == 17) {
        PORTB &= ~(1 << PB3);  // RS pin is PB3
    }
    if (pin == 18) {
        PORTB &= ~(1 << PB4);  // RS pin is PB4
    }
    if (pin == 19) {
        PORTB &= ~(1 << PB5);  // RS pin is PB5
    }
    if (pin == 23) {
        PORTC &= ~(1 << PC0);  // RS pin is PC0
    }
    if (pin == 24) {
        PORTC &= ~(1 << PC1);  // RS pin is PC1
    }
    if (pin == 25) {
        PORTC &= ~(1 << PC2);  // RS pin is PC2
    }
    if (pin == 26) {
        PORTC &= ~(1 << PC3);  // RS pin is PC3
    }
    if (pin == 27) {
        PORTC &= ~(1 << PC4);  // RS pin is PC4
    }
    if (pin == 28) {
        PORTC &= ~(1 << PC5);  // RS pin is PC5
    }
}


//pulse enable
void pulseENABLE( void ) {
    delay1us( 1 );
    setPinHigh(enable);            // set ENABLE pin high
    delay1us( 1 );
    setPinLow(enable);           // set ENABLE pin low
    delay1us( 100 );
}

//write4bits
void write4bits( uint8_t bits) {
    if ( bits & 1 ) {
        setPinHigh(db4);
    } else{
        setPinLow(db4);
    }
    if ( bits & 2) {
        setPinHigh(db5);
    } else {
        setPinLow(db5);
    }
    if (bits & 4) {
        setPinHigh(db6);
    } else {
        setPinLow(db6);
    }
    if (bits & 8) {
        setPinHigh(db7);
    } else {
        setPinLow(db7);
    }
    pulseENABLE();
}

//command
void command( uint8_t cmd ) {
    setPinLow(rs);               // RS pin is low for commands
    write4bits( cmd >> 4 );        
    write4bits( cmd );              
}

//lcdInit
void lcdInit(uint8_t fun_rs, uint8_t fun_enable, uint8_t fun_db4, uint8_t fun_db5, uint8_t fun_db6, uint8_t fun_db7) {
    // Set passed in values to global values
    rs = fun_rs;
    enable = fun_enable;
    db4 = fun_db4;
    db5 = fun_db5;
    db6 = fun_db6;
    db7 = fun_db7;

    // Set the passed pins as outputs
    setPinAsOutput(rs);
    setPinAsOutput(enable);
    setPinAsOutput(db4);
    setPinAsOutput(db5);
    setPinAsOutput(db6);
    setPinAsOutput(db7);

    // Set RS and ENABLE pins low initially
    setPinLow(rs);  // RS pin
    setPinAsOutput(enable);  // ENABLE pin

    delay1ms( 50 );                 // Wait 50ms for power on
    write4bits( 0x03 );             // Init routine is to
    delay1ms( 5 );                  // Write 0x03 three times
    write4bits( 0x03 );
    delay1ms( 1 );
    write4bits( 0x03 );
    delay1ms( 1 );
    write4bits( 0x02 );             // Choose 4-bit interface
    command( 0x28 );                // 2 lines w/ 5x8 font
    command( 0x0C );                // Display on, cursor OFF
    command( 0x01 );                // Clear display
    delay1ms( 2 );                  // Wait 2ms for clear
    command( 0x06 );                // Left-to-right text
}

//data
void lcdPutc( uint8_t c ) {
    setPinHigh(rs);                // RS pin is high for data
    write4bits( c>>4 );
    write4bits( c );
}

//lcdPuts
void lcdPuts( unsigned char *s) {
    while( *s ) lcdPutc( *s++ );
}

void lcdClear() {
    command( 0x01 );                // Clear display
    delay1ms( 2 );                  // Wait 2ms for clear
}

void lcdHome() {
    command( 0x02 );                // Return home
    delay1ms( 2 );                  // Wait 2ms for return
}

void lcdCursorOn() {
    command( 0x0E );                // Display on, cursor ON
}

void lcdCursorOff() {
    command( 0x0C );                // Display on, cursor OFF
}
