// Function for Diagonal: Top Left to Mid motion
void moveDiagonalTopLeftToMid(int speed)
{
  myMotorDriver.setDrive(LEFT_MOTOR, 0, speed);
  myMotorDriver.setDrive(RIGHT_MOTOR, 0, 0);
}
