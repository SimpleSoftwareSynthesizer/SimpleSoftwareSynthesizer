#include "ADSRController.h"


ADSRController::ADSRController(void)
{
	attack = 0.0;
	decay = 0.0;
	sustain = 0.0;
	release = 0.0;
	target = 0.99;
}


ADSRController::~ADSRController(void)
{
}

void ADSRController::setAttackRate(double rate) {
	attack = rate;
}

void ADSRController::setAttackTarget(double target) {
	this->target = target;
}

void ADSRController::setDecayRate(double rate) {
	decay = rate;
}

void ADSRController::setSustainRate(double rate) {
	sustain = rate;
}

void ADSRController::setReleaseRate(double rate) {
	release = rate;
}

double ADSRController::getAttackRate() {
	return attack;
}

double ADSRController::getDecayRate() {
	return decay;
}

double ADSRController::getSustainRate() {
	return sustain;
}

double ADSRController::getReleaseRate() {
	return release;
}

double ADSRController::getTarget() {
	return target;
}