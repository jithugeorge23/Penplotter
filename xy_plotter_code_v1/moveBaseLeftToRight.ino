// Function for Base: Left to Right motion
void moveBaseLeftToRight(int speed)
{
  myMotorDriver.setDrive(LEFT_MOTOR, 0, speed);
  myMotorDriver.setDrive(RIGHT_MOTOR, 0, speed);
}
