#ifndef _REG_H
#define	_REG_H
#endif
/**********************Data-tpye************************
 			define kinds of data	
						
********************************************************/
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef long long32;





/************************SPI part***********************
		spi maps in 0X4000 3800 -- 0X4000 3BFF , (1K)

*******************************************************/

typedef struct{
	int CR1;
	int CR2;
	int SR;
	int DR;
	int CRCPR;
	int RXCRCR;
	int TXCRCR;
	int I2SCFGR;
	int I2SPR;
}SPI_REG;

#define SPI_REG ((SPI_REG*)(0X40003800))

/***********************RCC part****************************
		we must enable the rcc before  we enable the spi
		RCC address:0X4002 1000 -- 0X4002 13FF (1K)
***********************************************************/

#define RCC_APB2ENR (*((long *)(0X40021000+0X34)))
#define RCC_IOPAENR (*((long *)(0X40021000+0X2C)))




/**********************GPIO part*************************
		we use PA5 6 7 as spi port,
		GPIOA	dress: 0X5000 0000 -- 0X5000 03FF, (1K)
*********************************************************/

typedef struct{
	int MOR;				//mode
	int OTR;				//otype
	int OSR;				//ospeed
	int PPR;				//
	int IDR;
	int ODR;
	int BSRR;
	int LCKR;
	int AFRL;				//AF0-AF15
	int AHRH;				//AF0-AF15
	int BRR;
}GPIO;

#define GPIOA ((GPIO *)(0X50000000))

/********************Function table***********************
				function defintion 
				ps:we should apply spi_init first
*********************************************************/

void
Spi_Init(void);

void
Spi_SetSpeed(u8 Speed);

u8
Spi_ReadWriteByte(u8 Data);

u16
Spi_ReadWriteHalfWord(u16 Data);

