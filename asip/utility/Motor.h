class Motor
{
    public:
        Motor();
        Motor(const byte motorDirectionPin, const byte pwmPowerPin);
        void setupPins(const byte motorDirectionPin, const byte pwmPowerPin);
        void stopMotor();
        void setDirectionMode(boolean direction);
        boolean getDirectionMode();
        void setMotorPower(int MPower);
        int getMotorPower();
    
    private:
        void initialise();
        void setMotor();

        //pin assignments
        byte motorDirectionPin;
        byte pwmPowerPin;

        int motorPower;
        int rawPower;
        int motorDirection;
};