#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

#define MS_DELAY 1000

/* DDR register - PIN = Input or Output
   PORT register - PIN = HIGH or LOW
   PIN register - reads pinMode(), Input
*/

int main (void) 
{
	/* Inputs or Outputs? */
	DDRB |= _BV(DDB1); // Pin 9 for output LED, PB1
	DDRC &= B11111010; // Photoresistor and Flex Sensor as inputs

	/* Turn on the Analogs and the LED */	
	PORTC |= _BV(PORTC0); // A0 for PhotoResistor
      PORTC |= _BV(PORTC2); // A2 for Flex Sensor
	PORTB |= _BV(PORTB1): // Pin 9 for LED

	int value; //save analog value
      int photoValue;
	int blueValue;

	while(1)
	{
		photoValue = (PINC & B00000001); // analogRead(photoPin)
  		_delay_ms(MS_DELAY);
 		blueValue = photoValue / 4; // conversion from raw to analog values
  		_delay_ms(MS_DELAY);
		PB1 = blueValue;
		PORTB |= (1 << PB1); // analogWrite(ledPin, blueValue);
  		
		if (blueValue > 100) {
   			value = (PINC & B00000100) // analogRead(flexPin)
			// value = map(value, 768, 853, 0, 90); // Map value 0-1023 to 0-255 (PWM)
			PB1 = value
			PORTB |= (1 << PB1) value; // analogWrite(ledPin, value); 
			_delay_ms(MS_DELAY);
  		}
	}               	
}
