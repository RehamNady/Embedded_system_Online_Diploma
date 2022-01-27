MEMORY
{
  FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 128k
  SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 20k
}

SECTIONS
{
  .text : {
    *(.vectors*)
    *(.text*)
    *(.rodata*)
    _E_text = . ;
  } > FLASH

  .data : {
    _S_data = . ;
    *(.data*)
    _E_data = . ;
  } > SRAM AT> FLASH

  .bss : {
    _S_bss = . ;
    *(.bss*)
    . = ALIGN(4) ;
    _E_bss = . ;
  } > SRAM

  . = . + 0x1000 ;
  _stack_top = . ;

}
