# Mason Crim
# Jake Hoke

all: thermometer.hex

install: thermometer.hex
	avrdude -C "C:\Program Files (x86)\Arduino\hardware\tools\avr\etc\avrdude.conf" -p atmega328p -c usbtiny -U flash:w:thermometer.hex:i
	
thermometer.hex: thermometer.elf
	avr-objcopy -j .text -j .data -O ihex thermometer.elf thermometer.hex

thermometer.elf: thermometer.o lcd.o delay.o ledbyte.o
	avr-gcc -mmcu=atmega328p -o thermometer.elf thermometer.o lcd.o delay.o ledbyte.o

thermometer.o: thermometer.c lcd.h delay.h ledbyte.h
	avr-gcc -mmcu=atmega328p -c thermometer.c

lcd.o: lcd.c lcd.h
	avr-gcc -mmcu=atmega328p -c lcd.c

delay.o: delay.S delay.h
	avr-gcc -mmcu=atmega328p -c delay.S

ledbyte.o: ledbyte.c ledbyte.h
	avr-gcc -mmcu=atmega328p -c ledbyte.c

clean:
	del *.o *.elf *.hex







