void stopMotors()
{
  myMotorDriver.setDrive(LEFT_MOTOR, 0, 0);     // Stop left motor
  myMotorDriver.setDrive(RIGHT_MOTOR, 0, 0);    // Stop right motor
  delay(500);
}
