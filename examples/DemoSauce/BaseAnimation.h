#ifndef BASE_ANIMATION_H__
#define BASE_ANIMATION_H__

#include <Arduino.h>
#include "Adafruit_ILI9341.h"
#include "MathUtil.h"

class BaseAnimation {
public:
	BaseAnimation(){};

	virtual void init( Adafruit_ILI9341 tft );
	virtual uint_fast16_t bgColor( void );
	virtual void reset( Adafruit_ILI9341 tft );
	virtual String title();

	virtual boolean willForceTransition( void );
	virtual boolean forceTransitionNow( void );

	virtual void perFrame( Adafruit_ILI9341 tft, FrameParams frameParams );
};

void BaseAnimation::init( Adafruit_ILI9341 tft ) {
	// Extend me
}

uint_fast16_t BaseAnimation::bgColor( void ) {
	// Extend me
	return 0xf81f;	// Everyone loves magenta
}

void BaseAnimation::reset( Adafruit_ILI9341 tft ) {
	// Extend me
}

String BaseAnimation::title() {
	return "BaseAnimation";
}

boolean BaseAnimation::willForceTransition( void ) {
	return false;	// Default: SuperTFT will transition animations automatically
}

boolean BaseAnimation::forceTransitionNow( void ) {
	// Extend me
	return false;	// Default: SuperTFT will transition animations automatically
}

void BaseAnimation::perFrame( Adafruit_ILI9341 tft, FrameParams frameParams ) {
	// Extend me
}

#endif
