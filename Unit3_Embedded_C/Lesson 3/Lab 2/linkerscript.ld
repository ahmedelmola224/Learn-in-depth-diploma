/*linkerscript cortex-m3
Ahmed Essam
*/


MEMORY
{
	flash(rx) : ORIGIN = 0x8000000, LENGTH = 128k
	sram(rwx) : ORIGIN = 0x20000000, LENGTH = 20k
}

SECTIONS
{
	.text :{
		*(.vectors*)
		*(.text)
		*(.rodata)
		_E_text = . ;
	}>flash
	
	.data :{
	_S_data = . ;
		*(.data)
		. = ALIGN(4) ;
	_E_data = . ;
	}>sram AT> flash

	.bss :{
	_S_bss = . ;
		*(.bss)
		. = ALIGN(4) ;
	_E_bss = . ;
	. = . + 0x1000 ;
	_stack_top = . ;
	}>sram
}