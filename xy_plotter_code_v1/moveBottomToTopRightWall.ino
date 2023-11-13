// Function for Bottom to Top Right Wall motion
void moveBottomToTopRightWall(int speed)
{
  myMotorDriver.setDrive(LEFT_MOTOR, 0, speed);
  myMotorDriver.setDrive(RIGHT_MOTOR, 1, speed);
}
