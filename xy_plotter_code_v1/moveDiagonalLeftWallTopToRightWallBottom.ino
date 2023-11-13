// Function for Diagonal: Left Wall Top to Right Wall Bottom motion
void moveDiagonalLeftWallTopToRightWallBottom(int speed)
{
  myMotorDriver.setDrive(LEFT_MOTOR, 0, 0);
  myMotorDriver.setDrive(RIGHT_MOTOR, 0, speed);
}
