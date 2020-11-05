int R_LED=8;
int B_LED=7;
int Buz=5;
const int temp=0;
void setup() {
  Serial.begin(9600);
  pinMode(R_LED,OUTPUT);
  pinMode(B_LED,OUTPUT);
  pinMode(Buz,OUTPUT);
}
void loop() {
  float Real_Voltage=analogRead(temp)*0.004882814;
  float temp_C = Real_Voltage*100.0;
  float temp_F = temp_C*(9.0/5.0)+32.0;
  Serial.print("Tegangan: ");
  Serial.println(Real_Voltage);
  Serial.print("Suhu(C): ");
  Serial.println(temp_C);
  Serial.print("Suhu(F): ");
  Serial.println(temp_F);
if(temp_C >= 26.0)
{
  Serial.println("Warning, Sistem PANAS");
  digitalWrite(R_LED,HIGH);
  analogWrite(Buz,20);
  delay(2000);
  digitalWrite(R_LED,LOW);
  analogWrite(Buz,0);
  delay(2000);
}
else if (temp_C <=25.0)
{
  Serial.println("Warning, Sistem DINGIN");
  digitalWrite(B_LED,HIGH);
  analogWrite(Buz,80);
  delay(2000);
  digitalWrite(B_LED,LOW);
  analogWrite(Buz,0);
  delay(2000);
}
else
{
  Serial.println("System Berfungsi BAIK");
  digitalWrite(R_LED,LOW);
  digitalWrite(B_LED,LOW);
  delay(2000);
}
}
