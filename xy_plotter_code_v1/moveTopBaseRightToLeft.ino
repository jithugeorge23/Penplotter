// Function for Top Base: Right to Left motion
void moveTopBaseRightToLeft(int speed)
{
  myMotorDriver.setDrive(LEFT_MOTOR, 1, speed);
  myMotorDriver.setDrive(RIGHT_MOTOR, 1, speed);
}
