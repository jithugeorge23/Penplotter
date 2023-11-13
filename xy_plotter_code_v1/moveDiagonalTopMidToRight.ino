// Function for Diagonal: Top Mid to Right motion
void moveDiagonalTopMidToRight(int speed)
{
  myMotorDriver.setDrive(LEFT_MOTOR, 0, 0);
  myMotorDriver.setDrive(RIGHT_MOTOR, 0, speed);
}
