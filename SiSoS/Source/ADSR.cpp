#include "ADSR.h"


ADSR::ADSR(ADSRController* controller_)
	: controller (controller_)
{
	value = 0;
	state_ = IDLE;
}


ADSR::~ADSR(void)
{
}

void ADSR::keyOn(double target_) {
	value = 0.0;
	target = target_;
	attackRate_ = controller->getAttackRate(); // Attackrate wird nur bei keyOn() aktualisiert.
	state_ = ATTACK;
}

void ADSR::keyOff() {
	state_ = RELEASE;
}

int ADSR::getState() {
	return state_;
}