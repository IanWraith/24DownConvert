/*
********************************************************************************
*                                                                              *
* Copyright (c) 2017 Andrea Loi                                                *
*                                                                              *
* Permission is hereby granted, free of charge, to any person obtaining a      *
* copy of this software and associated documentation files (the "Software"),   *
* to deal in the Software without restriction, including without limitation    *
* the rights to use, copy, modify, merge, publish, distribute, sublicense,     *
* and/or sell copies of the Software, and to permit persons to whom the        *
* Software is furnished to do so, subject to the following conditions:         *
*                                                                              *
* The above copyright notice and this permission notice shall be included      *
* in all copies or substantial portions of the Software.                       *
*                                                                              *
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR   *
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,     *
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL      *
* THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER   *
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING      *
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER          *
* DEALINGS IN THE SOFTWARE.                                                    *
*                                                                              *
********************************************************************************
*/



/******************************************************************************/
/*          DON'T EDIT THIS FILE UNLESS YOU KNOW WHAT YOU'RE DOING!           */
/******************************************************************************/



_heap_size =          0x00000400;
_stack_size =         0x00000400;

_isrvectors_tend =    0x00000150;

ENTRY(ResetHandler)

MEMORY {
  FLASH (RX) : ORIGIN = 0x08000000, LENGTH = 0x10000
  RAM (RWX)  : ORIGIN = 0x20000000, LENGTH = 0x05000
}

SECTIONS {
  .isrvectors 0x08000000 :
  {
    _sisrvectors = .;
    KEEP(*(.isrvectors))
    ASSERT(. == _isrvectors_tend, "The vector table needs to be 84 elements long!");
    _eisrvectors = .;
  } >FLASH

  .text :
  {
    . = ALIGN(4);
    _stext = .;
    *(.text*)
    *(.rodata*)
    . = ALIGN(4);
    _etext = .;
  } >FLASH
  
  .ARM.extab :
  {
    *(.ARM.extab* .gnu.linkonce.armextab.*)
  } >FLASH
  
  .ARM : {
    *(.ARM.exidx*)
  } >FLASH
  
  .data :
  {
    . = ALIGN(4);
    _sdata = .;
    *(.data*)
    . = ALIGN(4);
    _edata = .;
  } >RAM AT >FLASH

  _ldata = LOADADDR(.data);

  .bss :
  {
    . = ALIGN(4);
    _sbss = .;
    *(.bss*)
    *(COMMON)
    . = ALIGN(4);
    _ebss = .;
  } >RAM
  
  ._heap_trick :
  {
    . = ALIGN(4);
    . = . + _heap_size;
    . = ALIGN(4);
  } >RAM

  ._stack_trick :
  {
    . = ALIGN(8);
    . = . + _stack_size;
    . = ALIGN(8);
  } >RAM
  
}


