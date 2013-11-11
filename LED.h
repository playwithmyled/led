// LED.h

using namespace std;

#ifndef LED_H
#define LED_H

class LED {

	public:
		// Default constructor.
		LED();
	
		// Overload constructor.
		LED(int, int *, const int);
	
		// Destructor;
		~LED();

		// Accessor functions.
		int getCmdCount() const; // The function can't modify informaiton with the const keyword.
	
		// Mutator functions.
		void setCmdCount(int);
	
		void loop();


	private:

		int ledPin;
		int cmdIndex;
		int cmdCount;
		int cmdWidth;
	
		int * cmdPointer;
	
		int cmdIndexLast;
		long startMillis;
		float stepsPerMillis;

		bool doLed(int, int, int, int);	

};

#endif

