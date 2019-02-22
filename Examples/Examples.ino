#include "transient.h"

#define MYBUTTON	23

#define LED 13
#define RISING_EDGE	true
#define FALLING_EDGE false
Transient button;

void setup() {
	button.begin(MYBUTTON , FALLING_EDGE, INPUT_PULLUP);
	pinMode(LED,OUTPUT);
}

void loop() {
	if(button.detect()) {
		digitalWrite(LED, HIGH);
		delay(100);
		digitalWrite(LED, LOW);
	}

}
