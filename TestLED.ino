// Useled.ino

#include "LED.h"

#define LED1 6
#define LED2 9

const int cmd1Size = 4;
int cmd1[cmd1Size][4] = {
		{0,255,1000,0},
		{255,255,1000,0},		
		{255,0,1000,0},
		{0,0,1000,0}
	};

const int cmd2Size = 4;
int cmd2[cmd2Size][4] = {
		{0,0,1000,0},
		{0,255,1000,0},
		{255,255,1000,0},
		{255,0,1000,0}
	};

LED myLed1 (LED1, &cmd1[0][0], cmd1Size); // Pass the reference of the first element of the array.
LED myLed2 (LED2, &cmd2[0][0], cmd2Size); // Pass the reference of the first element of the array.

void setup() {

	pinMode(LED1,OUTPUT);
	digitalWrite(LED1,LOW);
	pinMode(LED2,OUTPUT);
	digitalWrite(LED2,LOW);
	
}

void loop() {

	myLed1.loop();
	myLed2.loop();
	
}
