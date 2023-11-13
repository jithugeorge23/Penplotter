// Function for Left Wall motion
void moveLeftWall(int speed)
{
  myMotorDriver.setDrive(LEFT_MOTOR, 0, speed);
  myMotorDriver.setDrive(RIGHT_MOTOR, 1, speed);
}
