// LED.cpp

#include <Arduino.h>
#include "LED.h"

// Constructors
LED::LED() {}

LED::LED(int led, int * cp, const int count) {

	cmdIndexLast = -1;
	startMillis = millis();
	stepsPerMillis = 0;
	cmdIndex = 0;
	cmdWidth = 4;

	cmdPointer = cp;

	setCmdCount(count);
	ledPin = led;

}

// Destructor.
LED::~LED() {}

// Accessor functions.
int LED::getCmdCount() const {
	return cmdCount;
}

// Mutator funcctions.
void LED::setCmdCount(int count) {
	cmdCount = count;
}

/*	LED control function.
*	@inputs
* 	start : Starting brightness from 0 to 255.
*	stop : Stopping brightness from 0 to 255.
*	duration : Time to go to stop brightness from start in milliseconds.
*	easying : Not yet implemented.
*/ 
bool LED::doLed(int start, int stop, int duration, int easying) {

	if( cmdIndexLast != cmdIndex ) {
	
		cmdIndexLast = cmdIndex;
	
		// Number of steps per millis.
		stepsPerMillis = (float(stop) - float(start)) / float(duration);
		
		// init start millis.
		startMillis = millis();
	}
	
	long deltaMillis = millis() - startMillis;
	float brightness = int(start + deltaMillis * stepsPerMillis);

	if(
		// Step up.
		( start < stop && brightness < stop ) ||
			// Step down.
			( start > stop && brightness > stop ) ||
			// Duraction not expired
			( deltaMillis <= duration )
		) {
	
		// Ouput current.
		analogWrite(ledPin, int(brightness));

		
	} else {
		return false;
	}
	
	return true;

}

/*
	Called in the arduino script loop.
*/
void LED::loop() {

	if( ! LED::doLed(
		*(cmdPointer + (cmdIndex * cmdWidth + 0)),
		*(cmdPointer + (cmdIndex * cmdWidth + 1)),
		*(cmdPointer + (cmdIndex * cmdWidth + 2)),
		*(cmdPointer + (cmdIndex * cmdWidth + 3))
		)) {
	
		cmdIndex++;
		
		if( cmdIndex > cmdCount - 1 )
			cmdIndex = 0;
	}
}
