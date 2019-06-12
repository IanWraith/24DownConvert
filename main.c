#include "common.h"
#include "regs.h"

// PA01 - Indicator LED
// PA04 - NSS
// PA05 - SCK
// PA06 - MISO
// PA07 - MOSI
// PA08 - Test Push Switch
// PA11 - LD

void Delay(uint32_t);
uint8_t SendReceiveSPIByte(uint32_t);
void SendSPIData (uint8_t,uint32_t);

int main(void)
{

	// Below are the ADF4350 settings for a 1 GHz -4dBm output
	uint32_t ar0=0x00500000;
	uint32_t ar1=0x08008011;
	uint32_t ar2=0x00004e42;
	uint32_t ar3=0x000004b3;
	uint32_t ar4=0x00ac8024;
	uint32_t ar5=0x00580005;
		
	// Turn on the port A + SPI1 clocks
	*(uint32_t *)(RCC_BASE + 0x18) &= MASK_2 | MASK_12;
	*(uint32_t *)(RCC_BASE + 0x18) |= BIT_2 | BIT_12;
		
	// SPI_CR2 setup
	// 02 SSOE enabled so SS output is enabled in master mode
	*(uint32_t *)(SPI1_BASE + 0x04) &= MASK_2;
	*(uint32_t *)(SPI1_BASE + 0x04) |= BIT_2;
		
	// I/O
	// PA01 needs to be in push pull mode thus 0 turns on the LED and 1 turns it off (0x2) - Bits 
	// PA04 (SPI NSS) needs to be in alternate push pull mode (0xa) 0b1010
	// PA05 (SPI SCK) needs to be in alternate push pull mode (0xa)
	// PA06 (SPI MISO) is a floating input (0x4)
	// PA07 (SPI MOSI) needs to be in alternate push pull mode (0xa)
	*(uint32_t *)GPIOA_BASE &= 0x0000ff0f;
	*(uint32_t *)GPIOA_BASE |= 0xa4aa0020;
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
	// 11 DFF 0 - 8 bit data frame
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
	*(uint32_t *)(SPI1_BASE) |= BIT_6 | BIT_5 | BIT_4 | BIT_3 | BIT_2;
								
	// Flash the LED to show everything works
	*(uint32_t *)(GPIOA_BASE + 0x14) = BIT_1;
	Delay(500000);
	*(uint32_t *)(GPIOA_BASE + 0x10) = BIT_1;
	Delay(100000);
		
		
	while (1)
	{
	// Send the setup data to the synth board
	SendSPIData(0,ar0);
	SendSPIData(1,ar1);
	SendSPIData(2,ar2);
	SendSPIData(3,ar3);
	SendSPIData(4,ar4);
	SendSPIData(5,ar5);
	}
	
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

uint8_t SendReceiveSPIByte(uint32_t value)
{
	uint8_t lout = 0;
	// Put the 8 bits to be sent into the SPI data register
	*(uint32_t *)(SPI1_BASE + 0x0c) = value;
	// Read a byte
	uint8_t inbyte = *(uint32_t *)(SPI1_BASE + 0x0c);
	
	// Loop waiting for the the SPI TXE flag to go high
	while (lout == 0)
	{
		// Read the SPI status register
		uint32_t statusSPI = *(uint32_t *)(SPI1_BASE + 0x08);
		// Just bit 1 the transmit buffer empty flag - wait for this to go high then leave this function
		statusSPI &= BIT_1;
		if (statusSPI == BIT_1) lout = 1;
	}
	
	return inbyte;
}

void SendSPIData (uint8_t regNo,uint32_t outval)
{
	SendReceiveSPIByte(0xa0);
}

