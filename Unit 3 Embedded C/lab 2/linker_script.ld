/* ARM-CORTEX-M3 linker script 
Mohamed samir
*/ 


MEMORY
{
	flash(RX)  : ORIGIN = 0X8000000, LENGTH = 128K
	sram(RWX)  : ORIGIN = 0X2000000, LENGTH = 20K
}


SECTIONS 
{
	.text : {

	        *(.vectors*)
	        *(.text*)
	        *(.rodata*)
	        _E_Text = . ;
	}>flash

	.data : {
	        _S_DATA = . ;
	        *(.data*)
	        . = ALIGN(4);
	        _E_DATA = . ;
	}>sram AT> flash

	.bss : {
	       _S_bss = . ;
	       *(.bss*)
            _E_bss = . ;
            . = . + 0x1000 ;
            _stack_top = . ;


	}>sram
}