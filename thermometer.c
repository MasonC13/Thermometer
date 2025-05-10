// Mason Crim
// Jake Hoke

#include <avr/io.h>
#include <stdlib.h>
#include "lcd.h"
#include "ledbyte.h"
#include "delay.h"


#define BUTTON_PIN PC0 // Button connected to PC0

#define ADC_CHANNEL 5 // Thermistor connected to ADC 5

void adc_init() {
    ADMUX = (1 << REFS0) | ADC_CHANNEL; // AVcc reference, ADC 5    
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Enable ADC, with prescaler 128
}

uint16_t adc_read() {
    ADCSRA |= (1 << ADSC); // Start conversion               
    while (ADCSRA & (1 << ADSC)); //Wait for conversion to complete       
    return ADC; // Read ADC value
}

// Convert ADC value to Celsius
// Use linear conversion formula
int16_t adc_to_celsius(uint16_t adc_val) {
    return (int16_t)((-0.1418 * adc_val) + 97.6);
}
// Convert celsius to Fahrenheit
int16_t to_fahrenheit(int16_t celsius) {
    return (celsius * 9) / 5 + 32;
}

int main(void) {
    lcdInit(12, 13, 14, 15, 16, 17); // Initialize LCD pins 12-17
    adc_init(); // initialize ADC
    DDRD = 0xFF; // Set PORTD as output for LEDs                            
    DDRC &= ~(1 << BUTTON_PIN); // set BUTTON_PIN as input              
    PORTC |= (1 << BUTTON_PIN); // Enable pull-up resistor on BUTTON_PIN             

    uint16_t sampleTemp[8]; // Array for 8 temperatures
    uint8_t index = 0;
    char buffer[16]; // String buffer

    while (1) {
        sampleTemp[index++] = adc_read(); // Read ADC and store
        delay1ms(125); // Delay for 125ms                       

        // 8 samples taken, then calculate average temperature
        if (index >= 8) {
            uint32_t sum = 0;
            for (uint8_t i = 0; i < 8; i++) {
                sum += sampleTemp[i];
            }
            uint16_t avg_adc = sum / 8; // Calculate average

            int16_t tempC = adc_to_celsius(avg_adc); // ADC to temperature conversion
            int16_t displayTemp;
            
            // Reset LCD display
            lcdClear();
            lcdHome();
            lcdPuts("Temp: ");

            // Button state check for Fahrenheit or Celsius
            if (PINC & (1 << BUTTON_PIN)) { // Button not pressed (high)
                displayTemp = to_fahrenheit(tempC);
                itoa(displayTemp, buffer, 10);
                lcdPuts(buffer);
                lcdPuts(" F");
            } else { // Button pressed (low)
                itoa(tempC, buffer, 10);
                lcdPuts(buffer);
                lcdPuts(" C");
            }

            ledbyte(avg_adc >> 2); // Display average ADC value on LEDs   
            index = 0; // Reset index
        }
    }
}
