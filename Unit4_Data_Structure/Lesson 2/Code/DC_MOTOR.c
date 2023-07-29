#include "DC_MOTOR.h"

DC_MOTOR_state  DC_MOTOR_state_id;
void (*pDC_MOTOR_state)();//pointer to state of motor
unsigned int speed;

void DC_MOTOR_init()
{
	printf("Dc init\n");
	DC_MOTOR_state_id=DC_idle;
	pDC_MOTOR_state=STATE(DC_idle);
}
STATE_define(DC_idle)
{
	DC_MOTOR_state_id=DC_idle;
	pDC_MOTOR_state=STATE(DC_idle);
	printf("DC_idle...........speed=%d\n\n\n",speed);

}
STATE_define(DC_busy)
{
	DC_MOTOR_state_id=DC_busy;
	pDC_MOTOR_state=STATE(DC_idle);
	printf("DC_busy...........speed=%d\n\n\n",speed);
}
void speed_set(int s)
{
	speed=s;
	pDC_MOTOR_state=STATE(DC_busy);
	printf("CA---->DC setspeed()\n");
}