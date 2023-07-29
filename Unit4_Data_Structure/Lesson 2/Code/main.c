#include "US.h"
#include "CA.h"
#include "DC_MOTOR.h"

void setup()
{
	US_init();
	DC_MOTOR_init();

}

int main()
{
	setup();

	while(1)
	{
		pUS_state();
		pCA_state();
		pDC_MOTOR_state();
	}
	return 0;
}