float logR2, R2, T;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;


void setup(){
  Serial.begin(115200);
  analogSetPinAttenuation(A3, ADC_0db);
  int valA3 = analogRead(A3);
  int valA4 = analogRead(A4);
  float temp = convert2Temp(valA4);
  
  
  char buff[] = "";

  sprintf(buff, "temp=%f\nlum=%d\0",temp,valA3);

  Serial.println(buff);
  delay(100);

  esp_sleep_enable_timer_wakeup(50000);
  esp_deep_sleep_start();
}

float convert2Temp(int val) {
  R2 = 10000 * (1023.0 / (float)val - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15;
  return T;
}

void loop(){

}
