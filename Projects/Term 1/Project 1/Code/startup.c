/*startup 
Ahmed Essam*/
#include "Platform_Types.h"

extern void main();
void Reset_Handler();
void Default_Handler();

/*__attribute__((weak,alias("Default_Handler")))-> weak enable the override of the function ,alias to make alias for the function */
void NMI_Handler()         __attribute__((weak,alias("Default_Handler")));
void H_Fault_Handler()     __attribute__((weak,alias("Default_Handler")));
void MM_Fault_Handler()    __attribute__((weak,alias("Default_Handler")));
void Bus_Fault()           __attribute__((weak,alias("Default_Handler")));
void Usage_Fault_Handler() __attribute__((weak,alias("Default_Handler")));

/*__attribute__((section(".vectors"))) -> to make a new section called .vectors and put it throught ld at the begining of the flash so the sp at it's place and the IVT*/
extern uint32_t _stack_top;
uint32_t vectors[] __attribute__((section(".vectors")))=
{
	(uint32_t)&_stack_top,
	(uint32_t)&Reset_Handler,
	(uint32_t)&NMI_Handler,
	(uint32_t)&H_Fault_Handler,
	(uint32_t)&MM_Fault_Handler,
	(uint32_t)&Bus_Fault,
	(uint32_t)&Usage_Fault_Handler,
};

/*symbols not variables so you need to use & */
extern uint32_t _E_text;
extern uint32_t _S_data;
extern uint32_t _E_data;
extern uint32_t _S_bss;
extern uint32_t _E_bss;
void Reset_Handler()
{
	/*copy .data from FLASH to RAM*/
	uint32_t i =0;
	unsigned int Data_size= (uint8_t *)&_E_data -(uint8_t *)&_S_data;
	uint8_t * psrc=(uint8_t *)&_E_text;
	uint8_t * pdes=(uint8_t *)&_S_data;
	for(i =0;i<Data_size;i++)
	{
		*((uint8_t *)pdes)= *((uint8_t *)psrc);
		pdes++;
		psrc++;
	}
	
	/*init .bss in the RAM*/
	unsigned int Bss_size= (uint8_t *)&_E_bss -(uint8_t *)&_S_bss;
	pdes=(uint8_t *)&_S_bss;
	for(i =0;i<Bss_size;i++)
	{
		*((uint8_t *)pdes++)= (uint8_t)0;
	}
	
	main();
}

void Default_Handler()
{
	Reset_Handler();
}