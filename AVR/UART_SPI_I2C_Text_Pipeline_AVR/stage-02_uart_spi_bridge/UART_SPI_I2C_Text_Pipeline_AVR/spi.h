/*
 * spi.h
 *
 * Created: 15-11-2025 7.06.49 AM
 *  Author: anees
 */ 


#include <stdint.h>
#ifndef SPI_H_
#define SPI_H_

#define CS PORTB2
#define MOSI PORTB3
#define MISO PORTB4
#define SCK PORTB5

void SPI_Init(void);
 uint8_t SPI_Master_Transmit(uint8_t data);
 void SPI_SelectSlave(void);
  void SPI_DeselectSlave(void);



#endif /* SPI_H_ */