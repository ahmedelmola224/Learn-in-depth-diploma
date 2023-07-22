#include "./Platform_Types.h"

#define RCC_Base   (0x40021000)
#define GPIO_Base (0x40010800)
#define APB2ENR    *(vuint32_t * ) (RCC_Base +0x18)
#define CRH        *(vuint32_t * ) (GPIO_Base +0x04)
#define ODR        *(vuint32_t * ) (GPIO_Base +0x0C)


typedef union
{
	vuint32_t all;
	struct
	{
		vuint32_t  reserved:13;
		vuint32_t  pin13:1;
	}pin;
}R_ODR_t;


volatile R_ODR_t * R_ODR =(volatile R_ODR_t*)(GPIO_Base +0x0C);
unsigned char g_Value [3]={1,2,3};
const unsigned char const_g_Value [3]={1,2,3};
int main(void)
{
	vuint32_t i;
	APB2ENR|=1<<2;
	CRH&=0xff0fffff;
	CRH|=0x00200000;

	while(1)
	{
		R_ODR->pin.pin13=1;
		for( i=0;i<5000;i++);
		R_ODR->pin.pin13=0;
		for( i=0;i<5000;i++);

	}


}
