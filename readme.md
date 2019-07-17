## 2.4 GHz Downconverter for an SDR

I recently became interested in exploring some of the signals found in the 2.4 GHz ISM band. The problem is that
my favourite SDR (Software Defined Radio) an Airspy R2 only covers up to 1.7 GHz. Initially I looked at buying an
SDR that could cover the 2.4 GHz band but found either that they were to expensive , had poor performance or
weren't supported by my SDR control software of choice. So I decided it would be best to build a downconverter to
take the 2.4 GHz down by 1 GHz so it could be monitored by my Airspy.

My initial thought was to design and build the circuits to do this myself. This is my day job and having a PCB
manufactured is amazingly cheap now but I'm short of time so didn't want to go that route. However I have
recently bought a number of the very cheap Chinese made evaluation/development boards which are for sale on eBay
and decided to put together a downconverter made up of these ready made boards only. To this I needed just 3 such
boards ..

* A mixer board. This takes in the 2.4 GHz signal and mixes it with a L.O (local oscillator) signal to produce a signal which is 1 GHz lower in frequency. For this I decided to use an ADL5350 development board which cost £15.99 (the most expensive of the boards).

![Mixer Board Photo](/images/Mixer_board.jpg)

* A oscillator board to generate the 1 GHz signal required. Now a 1 GHz crystal oscillator based board or module would have been the simplest option but those don't appear to exist. So I decided to go with an ADF4350 development board which cost approx £10.

![Oscillator Board Photo](/images/Synth_board.jpg)

* The oscillator board is to told which frequency to output by setting registers within the ADF4350 IC. This is done using an SPI (Serial Peripheral Interface) so a programmable embedded board is needed. For this I decided to use a small STM32 development board.

![Embedded Board Photo](/images/STM_board.jpg)

Now I realise an STM32 board is complete overkill for this job and a small 8 bit micro would have easily done what was needed. But it was cheap enough at just under £4 but also I wanted to learn how to program an STM32
and what better reason is there than that ! I already had a cheap clone ST-Link V2 programmer bought for a couple of UK pounds for another job that never happened and a Linux PC already loaded with OpenOCD and the GCC compiler
so I had everything I needed for actually programming it.

My original thought had been to program the STM32 in assembly language partly because it is many years since I last programmed an ARM device in assembly but for various reasons (speed being the main one) I
decided to go with C instead. To get me started with this I needed some kind of a bare metal framework. Thankfully I soon found the one by [Andrea Loi](https://github.com/al95/STM32-Bare-Metal) which soon got
me started and which I can't recomend highly enough. With the aid of that framework I soon had a basic "Hello World" (actually a flash a LED which is usually the embedded equivalent) C program up and running on
the STM board. From reading the [datasheet](https://www.analog.com/media/en/technical-documentation/data-sheets/ADF4350.pdf) I knew that programming the ADF4350 involved setting 6 registers to the correct
values. Looking at the calculations I realised that was going to be a quick job but soon found a program which could be [downloaded](https://www.analog.com/media/en/evaluation-boards-kits/evaluation-software/ADF435x_v4_5_0.zip) 
from Analog Devices which did these calculations for me.

![Screen shot](/images/ad_ss.jpg)

The boards were connected so that the +5V DC and GND lines from the STM board fed the 5V power inputs of the oscillator and mixer boards. In addition the STM board was wired to the oscillator (ADF4350)
board in the following ways ..

STM32 | ADF4350
----- | -------
PA02 | LE
PA05 (SPI SCK) | CLK
PA07 (SPI MOSI) | DATA
PA11 | LD

I must admit that getting the STM32 SPI feature working was ~~annoying~~ fun. The main problem was that the vast majority of the STM32 SPI examples on the web use various programming libraries which wrap around the 
SPI feature and make it easy to use. I didn't want to go that route however and wanted to get 'hands on' with the STM32 so did things the hard way writing directly to the STM32s registers. It was during this
period I got to know various STM32 datasheets very well. I had annoying week or so where what ever I did the ADF4350 wouldn't respond and it wasn't until I attached a Keysight DSOX-2002A oscilloscope I had
available to the SPI lines that I could see the problem which was that I wasn't waiting for the STM32s SPI BSY flag to go low before I took the ADF4350s LE line high. As soon as I saw the LE line issue on
the oscilloscopes screen I knew what the problem was and quickly fixed it.

The completed prototype unit looks like this ..

![Prototype photo](/images/full_unit.jpg)

Note the mixer boards RFOUT output goes directly to the Airspy's antenna input. The antenna you see on that photo comes from an old Wi-Fi hub I had laying around.

So does it work ? I am pleased to say that it does. I can 'see' Wi-Fi signals (which are to wide bandwidth for my Airspy to handle) but I can now also monitor Zigbee and Bluetooth signals. I have also found
some interesting 2.4 GHz ISM band oddities using OOK and 2FSK modulation which I have yet to identify. Oh and I can detect 3G or 4G phone signals around 2.6 GHz.

###Future Improvements

* A band pass filter on the antenna input to the mixer to remove strong out of band transmissions.

* The entire unit needs boxing up nicely with the STM board in its own screened metal box inside the main box. This is because I am seeing harmonics of the STM32s crystal oscillator in the 2.4 GHz band.

[Ian Wraith](https://twitter.com/IanWraith) 17th July 2019
