/*
 * bmp280.h
 *
 * Created: 15-11-2025 7.40.09 AM
 *  Author: anees
 */ 


#ifndef BMP280_H_
#define BMP280_H_

void getChip_ID(void);
void getMSB(void);
void getLSB(void);
void getxLSB(void);
void getRawTemp(void);
void get_dig_T1(void);
void get_dig_T2(void);
void get_dig_T3(void);
void ctrl_meas(void);
void realTemp(void);




#endif /* BMP280_H_ */