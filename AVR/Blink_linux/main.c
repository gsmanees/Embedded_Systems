#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // PB5 (Arduino Uno LED, Digital Pin 13) as output
    DDRB |= (1 << PB5);

    while (1)
    {
        PORTB ^= (1 << PB5);   // Toggle LED
        _delay_ms(500);
    }
}