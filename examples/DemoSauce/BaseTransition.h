#ifndef BASE_TRANSITION_H__
#define BASE_TRANSITION_H__

#include <Arduino.h>
#include "Adafruit_ILI9341.h"
#include "MathUtil.h"

class BaseTransition {
public:
	BaseTransition(){};

	virtual void init( Adafruit_ILI9341 tft );
	virtual void restart( Adafruit_ILI9341 tft, uint_fast16_t color );
	virtual void perFrame( Adafruit_ILI9341 tft, FrameParams frameParams );
	virtual boolean isComplete();
};

void BaseTransition::init( Adafruit_ILI9341 tft ) {
	// Extend me
}

void BaseTransition::restart( Adafruit_ILI9341 tft, uint_fast16_t color ) {
	// Extend me
}

void BaseTransition::perFrame( Adafruit_ILI9341 tft, FrameParams frameParams ) {
	// Extend me
}

boolean BaseTransition::isComplete() {
	// Extend me
	return false;
}

#endif
