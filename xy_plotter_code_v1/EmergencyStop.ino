void emergencyStop()
{
  int val_emergency = digitalRead(emergency_pin);
  if (val_emergency == 0)
    {
      stopMotors();
    }

}
