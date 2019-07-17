#include "common.h"
#include "regs.h"

// PA01 - Indicator LED
// PA02 - ADF4350 LE
// PA04 - NSS
// PA05 - SCK to ADF4350 CLK
// PA06 - MISO
// PA07 - MOSI to ADF4350 DATA
// PA08 - Test Push Switch
// PA11 - ADF4350 LD

void Delay(uint32_t);
uint16_t SendReceiveSPIData(uint16_t);
void SendSPIDataADF4350 (uint32_t);

int main(void)
{

	// Below are the ADF4350 settings for a 1 GHz +5dBm output
	uint32_t ar0=0x500000;
	uint32_t ar1=0x8008011;
	uint32_t ar2=0x4e42;
	uint32_t ar3=0x4b3;
	uint32_t ar4=0xac803c;
	uint32_t ar5=0x580005;
	
	// Below are the ADF4350 settings for a 1001.25 MHz +5dBm output
	//uint32_t ar0=0x500008;
	//uint32_t ar1=0x8008029;
	//uint32_t ar2=0x4e42;
	//uint32_t ar3=0x4b3;
	//uint32_t ar4=0xac803c;
	//uint32_t ar5=0x580005;

	// Turn on the port A + SPI1 clocks
	*(uint32_t *)(RCC_BASE + 0x18) &= MASK_2 | MASK_12;
	*(uint32_t *)(RCC_BASE + 0x18) |= BIT_2 | BIT_12;
		
	// SPI_CR2 setup
	// 02 SSOE enabled so SS output is enabled in master mode
	*(uint32_t *)(SPI1_BASE + 0x04) &= MASK_2;
	*(uint32_t *)(SPI1_BASE + 0x04) |= BIT_2;
		
	// I/O
	// PA01 needs to be in push pull mode thus 0 turns on the LED and 1 turns it off (0x2) - Bits 
	// PA02 needs to be in open drain mode (0x1) 
	// PA04 (SPI NSS) needs to be in alternate push pull mode (0xa) 0b1010
	// PA05 (SPI SCK) needs to be in alternate push pull mode (0xa)
	// PA06 (SPI MISO) is a floating input (0x4)
	// PA07 (SPI MOSI) needs to be in alternate push pull mode (0xa)
	*(uint32_t *)GPIOA_BASE &= 0x0000f00f;
	*(uint32_t *)GPIOA_BASE |= 0xa4aa0120;
	// PA08 is a push switch input
	// PA11 is a floating input
	*(uint32_t *)(GPIOA_BASE + 0x04) &= 0xffff0ff0;
	*(uint32_t *)(GPIOA_BASE + 0x04) |= 0x00004008;
	// PA8 input pull up set P8ODR to 1 
	// PA6 input pull up set P6ODR to 1
	*(uint32_t *)(GPIOA_BASE + 0x0c) &= MASK_8 | MASK_6;
	*(uint32_t *)(GPIOA_BASE + 0x0c) |= BIT_8 | BIT_6;
	
	// SPI_CR1 setup
	// 15 BIDIMODE 0 - bidirectional
	// 14 BIDIOE 0 - output enabled
	// 13 CRCEN 0 - CRC disabled
	// 12 CRCNEXT 0 - No CRC phase
	// 11 DFF 1 - 16 bit data frame
	// 10 RXONLY 0 - Full duplex
	// 09 SSM 0 - Software slave management enabled
	// 08 SSI 0
	// 07 LSBFIRST 0 - MSB sent first
	// 06 SPE 1 - SPI enabled
	// 05/04/03 111 - fpCLK/256
	// 02 MSTR 1 - Master
	// 01 CPOL 0 - Clock to zero when idle
	// 00 CPHA 0 - First clock transition is the data edge
	*(uint32_t *)(SPI1_BASE) &= 0xffff0000;
	*(uint32_t *)(SPI1_BASE) |= BIT_11 | BIT_6 | BIT_5 | BIT_4 | BIT_3 | BIT_2;
	
	// Set PA02 (LE) low
	*(uint32_t *)(GPIOA_BASE + 0x14) = BIT_2;
	
	// Flash the LED to show everything works
	*(uint32_t *)(GPIOA_BASE + 0x14) = BIT_1;
	Delay(500000);
	*(uint32_t *)(GPIOA_BASE + 0x10) = BIT_1;
	Delay(100000);
		
	// Send the setup data to the ADF4350
	SendSPIDataADF4350(ar5);
	SendSPIDataADF4350(ar4);
	SendSPIDataADF4350(ar3);
	SendSPIDataADF4350(ar2);
	SendSPIDataADF4350(ar1);
	SendSPIDataADF4350(ar0);
	
	// Go into an endless loop waiting for frequency lock to be achieved
	while(1)
	{
		// Read GPIO port A
		uint32_t portA = *(uint32_t *)(GPIOA_BASE + 0x08);
		// Just bit 11
		portA &= BIT_11;
		// If we have lock turn on the LED
		if (portA == 0) *(uint32_t *)(GPIOA_BASE + 0x10) = BIT_1;
		else *(uint32_t *)(GPIOA_BASE + 0x14) = BIT_1;
	}
}

// A general purpose delay
void Delay(uint32_t tmax)
{
	uint32_t i;
	for (i=0;i < tmax ; i++) 
		{
		asm("nop");
		}
}

// Send a 16 bit word via SPI1 and receive a 16 bit word at the same time
uint16_t SendReceiveSPIData(uint16_t value)
{
	uint8_t lout = 0;
	// Put the 16 bits to be sent into the SPI data register
	*(uint32_t *)(SPI1_BASE + 0x0c) = value;
	// Read in a 16 bit frame
	uint16_t inbyte = *(uint32_t *)(SPI1_BASE + 0x0c);
	// Loop waiting for the the SPI TXE flag to go high
	while (lout == 0)
	{
		// Read the SPI status register
		uint32_t statusSPI = *(uint32_t *)(SPI1_BASE + 0x08);
		// Just bit 1 the transmit buffer empty flag - wait for this to go high then leave this function
		statusSPI &= BIT_1;
		// The condition has been met so signal to get out of this loop
		if (statusSPI == BIT_1) lout = 1;
	}
	return inbyte;
}

// Send a 32 bit register value to the ADF4350
void SendSPIDataADF4350 (uint32_t outval)
{
	// This then needs splitting into 2 x 16 bit words
    uint16_t highWord = (outval & 0xffff0000) >> 16;
	uint16_t lowWord = outval & 0x0000ffff;
	// Send these to the ADF4350 via SPI
	SendReceiveSPIData (highWord);
	SendReceiveSPIData (lowWord);
	uint8_t lout = 0;
	// Loop waiting for the the SPI BSY flag to go low
	while (lout == 0)
	{
		// Read the SPI status register
		uint32_t statusSPI = *(uint32_t *)(SPI1_BASE + 0x08);
		// Just bit 7 the SPI BSY flag - wait for this to go low then leave this function
		statusSPI &= BIT_7;
		// The condition has been met so signal to get out of this loop
		if (statusSPI == 0) lout = 1;
	}
	// Add a delay here so the clock has gone low before LE is taken high
	Delay(10);
	// Take LE high to load the data into the register
	*(uint32_t *)(GPIOA_BASE + 0x10) = BIT_2;
	// Short delay while LE is high (minimum of 20ns)
	Delay(30);
	// Take LE low again
	*(uint32_t *)(GPIOA_BASE + 0x14) = BIT_2;
}

