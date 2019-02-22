/*********************************************************************
	Bistable library

	Author : Jean-Marc Chiappa
	Date   : 30.10.2018
	Rev : 1
	
	*******************************************************************/

#ifndef transient_h
#define transient_h

#include "Arduino.h"

class Transient
{
public:
	Transient();
	void begin(uint8_t Pin, boolean edge, uint8_t mode);
	boolean detect();

private:
	uint8_t Pin;
	uint8_t Active_Edge;
	boolean Last_input_state;
	boolean state;
};

#endif // transient_h