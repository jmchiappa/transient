#include "transient.h"

#define RISING_EDGE		true
#define FALLING_EDGE	false

Transient::Transient() {}

void Transient::begin(uint8_t Pin,boolean edge, uint8_t mode)
{
	this->Pin = Pin;
	this->Active_Edge = edge;
	if((mode==INPUT)||(mode==INPUT_PULLUP))
	{
		pinMode(Pin, mode);
	}
	else
		pinMode(Pin, INPUT);

	Last_input_state = digitalRead(this->Pin);
}

/* Return true if an expected transition occurs
*/
boolean Transient::detect(void)
{
	boolean ret=false;
	boolean state = digitalRead(Pin);
	if(state!=Last_input_state) // transition occurs
	{
		if(state==Active_Edge)
		{
			ret=true;	// transition occurs
		}
	}
	Last_input_state = state;
	return ret;
}
