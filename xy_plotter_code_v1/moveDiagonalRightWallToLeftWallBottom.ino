// Function for Diagonal: Right Wall to Left Wall Bottom motion
void moveDiagonalRightWallToLeftWallBottom(int speed)
{
  myMotorDriver.setDrive(LEFT_MOTOR, 1, speed);
  myMotorDriver.setDrive(RIGHT_MOTOR, 0, 0);
}
