/*SRAM 0x20000000*/

.section .vectors 
.word 0x20001000      /*stack top address*/
.word _reset		  /*reset*/
.word Vector_handler  /*NMI*/
.word Vector_handler  /*Hard fault*/
.word Vector_handler  /*MM fault*/
.word Vector_handler  /*Bus fault*/
	  
	  /*more handlers
	    for other modules*/

.section .text 
_reset:
	bl main
	b .

.thumb_func 
Vector_handler: 
		b _reset	