/*
 * Q10.c
 *
 * Created: 17-05-2026 1.48.28 PM
 * Author : anees
 
 
 Objective: Write a program to create an automated cooling system using an LM35 
 sensor and a DC motor with manual power control.
 Requirements: The system must interface with an LM35 temperature sensor and a DC motor. 
 A push-button must be used to toggle the entire system ON and OFF. When the system is ON, 
 it should read the temperature and adjust the motor speed accordingly. At lower 
 temperatures, the motor should run at a reduced speed, and at higher temperatures, 
 the motor should automatically switch to a higher speed. The program logic for sensor 
 reading, speed calculation, and motor control must be implemented using separate functions.
 
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

uint8_t system_state = 0;

void ADC_Init()
{
    ADMUX=(1<<REFS0); // AVCC reference
    ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0); // Prescaler 128
}

uint16_t ADC_Read(uint8_t channel)
{
    ADMUX= (ADMUX&0xF0) | channel;
    ADCSRA|=(1<<ADSC);
    while (ADCSRA&(1<<ADSC));
    return ADC;
}

void PWM_Init()
{
    DDRD|=(1<<PD6); // OC0A output
    TCCR0A=(1<<COM0A1)|(1<<WGM01)|(1<<WGM00); // Fast PWM Mode
    TCCR0B=(1<<CS01)|(1<<CS00);  // Prescaler 64
    OCR0A=0;
}

float Read_Temperature()
{
    uint16_t adc_value;
    float voltage;
    float temperature;
    adc_value=ADC_Read(0);
    voltage=(adc_value*5.0)/1023.0;
    temperature=voltage*100.0;
    return temperature;
}

uint8_t Calculate_Speed(float temp)
{
    if(temp<30)
    {
        return 80;   // Low speed
    }
    else if(temp>=30&&temp<40)
    {
        return 160;  // Medium speed
    }
    else
    {
        return 255;  // Full speed
    }
}

void Set_Motor_Speed(uint8_t speed)
{
    OCR0A=speed;
}

int main(void)
{
    float temperature;
    uint8_t speed;

    ADC_Init();
    PWM_Init();

    DDRD&=~(1<<PD2); // Button set as input
    PORTD|=(1<<PD2); // Internal pull-up enabled for PD2

    while (1)
    {
        if (!(PIND&(1<<PD2)))  // checking button pressed or not
        {
            _delay_ms(50);
            if (!(PIND&(1<<PD2)))
            {
                system_state ^= 1;
                while(!(PIND&(1<<PD2)));
            }
        }

        if (system_state)
        {
            temperature=Read_Temperature();
            speed=Calculate_Speed(temperature);
            Set_Motor_Speed(speed);
        }
        else
        {
            Set_Motor_Speed(0);
        }

        _delay_ms(200);
    }
}

