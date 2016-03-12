
#include "Motor.h" // this is the modified version of the hubee library

Motor::Motor()
{
}

Motor::Motor(const byte _motorDirectionPin, const byte _pwmPowerPin)
{
  setupPins(_motorDirectionPin, _pwmPowerPin);
}

void Motor::setupPins(const byte _motorDirectionPin, const byte _pwmPowerPin)
{
  motorDirectionPin = _motorDirectionPin;
  pwmPowerPin = _pwmPowerPin;	
  pinMode(motorDirectionPin, OUTPUT);
  pinMode(pwmPin, OUTPUT);
  initialise();
}

void Motor::initialise()
{
  motorPower = 0;
  rawPower = 0;
  motorDirection = 0;
  setMotor();
}
void Motor::setMotor()
{
  //set the motor - private function
  rawPower = abs(motorPower);
  if(motorPower < 0) motorDirection = 0;
  else motorDirection = 1;

  if(motorPower == 0)
  {
    stopMotor();
    return;
  }
  printf("pwm on pin %d set to %d\n",pwmPowerPin, rawPower);
  //write the speed value to PWM
  analogWrite(pwmPowerPin, rawPower);
  digitalWrite(motorDirectionPin,motorDirection)
}

void Motor::stopMotor()
{
  //halt the motor using the current braking mode
  analogWrite(pwmPowerPin, 0);
}


void Motor::setMotorPower(int power)
{
  //set the motor - public function
  //costrain the value to what is allowed
  motorPower = constrain(power, -255, 255);
  setMotor(); //call private func to actually set the motor
}