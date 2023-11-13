void home()
{
  int x_val_left = digitalRead(x_left);
  int y_val_top = digitalRead(y_top);

  Serial.println("To Home Position!!");
  myMotorDriver.enable();
  while (x_val_left != 0 || y_val_top != 0) {
    while (x_val_left != 0) {      
      home_x_movmt(180);
      delay(100);
      Serial.println("X value: ");
      Serial.println(x_val_left);
      x_val_left = digitalRead(x_left);
    }
    while (y_val_top != 0) {
      moveTopBaseRightToLeft(160);
      delay(100);
      Serial.println("Y value: ");
      Serial.println(y_val_top);
      y_val_bottom = digitalRead(y_top);
    }
    x_val_left = digitalRead(x_left);
    y_val_top = digitalRead(y_top);
    Serial.println("Reached Home!!!");
    Serial.println("X Limit: " + String(x_val_left) + ", Y Limit: " + String(y_val_top));
    delay(100);
  }
  stopMotors();
  //Serial.println("Home");
}