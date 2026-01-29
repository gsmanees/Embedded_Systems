/*
 * spi.h
 *
 * Created: 15-11-2025 7.06.49 AM
 *  Author: anees
 */ 


#ifndef SPI_H_
#define SPI_H_

#define CS PORTB2
#define MOSI PORTB3
#define MISO PORTB4
#define SCK PORTB5

void SPI_init(void);



#endif /* SPI_H_ */