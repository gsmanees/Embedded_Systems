//-----------------------------------------------------------

// 						I2C Protocol

// I2C base addresses
#define I2C1_BASEADDR 0x40005400U
#define I2C2_BASEADDR 0x40005800U
#define I2C3_BASEADDR 0x40005C00U

// I2C Register Structure
typedef struct
{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t OAR1;
	volatile uint32_t OAR2;
	volatile uint32_t DR;
	volatile uint32_t SR1;
	volatile uint32_t SR2;
	volatile uint32_t CCR;
	volatile uint32_t TRISE;
	volatile uint32_t FLTR;

}I2C_RegDef_t;

// I2C Pointers
#define I2C1 ((I2C_RegDef_t*)I2C1_BASEADDR)
#define I2C2 ((I2C_RegDef_t*)I2C2_BASEADDR)
#define I2C3 ((I2C_RegDef_t*)I2C3_BASEADDR)


// I2C enable

#define I2C1_EN() (RCC->APB1ENR|=(1<<21))
#define I2C2_EN() (RCC->APB1ENR|=(1<<22))
#define I2C3_EN() (RCC->APB1ENR|=(1<<23))

