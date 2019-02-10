#include <Servo.h> 
Servo servo1; 
Servo servo2; 
Servo servo3; 
int sensorPin = A0;
int LedBiru =3; // Led warna biru digital pin 3
int LedHijau=4; // Led warna hijau digital pin 4
int LedMerah=5; // Led warna merah digital pin 5
int hasil,hasilb,hasilm,hasilh;
int k=3 ;  // toleransi warna

void setup() {
  pinMode(LedBiru,OUTPUT);
  pinMode(LedMerah,OUTPUT);
  pinMode(LedHijau,OUTPUT);  
  digitalWrite(LedBiru,LOW);
  digitalWrite(LedMerah,LOW);
  digitalWrite(LedHijau,LOW);
  servo1.attach(9);  // motor servo1 pin digital 9
  servo1.write(0);  
  servo2.attach(10);  // motor servo2 pin digital 10
  servo2.write(0);  
  servo3.attach(11);  // motor servo3 pin digital 11
  servo3.write(0);    
  delay(100);       
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  digitalWrite(LedMerah,HIGH);
  delay(1000);
  // baca data sensor
  hasil= analogRead(sensorPin);
  hasilm=map(hasil,0,1023,0,255);
  Serial.print("R,G,B = ");
  Serial.print(hasilm); 
  digitalWrite(LedMerah,LOW);    
  delay(150);

  // nyalakan LedHijau
  digitalWrite(LedHijau,HIGH);
  delay(1000);
  // baca data sensor
  hasil= analogRead(sensorPin);
  hasilh=map(hasil,0,1023,0,255);  
  Serial.print(",");
  Serial.print(hasilh); 
  digitalWrite(LedHijau,LOW);    
  delay(150);
  
  digitalWrite(LedBiru,HIGH);
  delay(1000);
  // baca data sensor
  hasil= analogRead(sensorPin);
  hasilb=map(hasil,0,1023,0,255);  
  Serial.print(",");
  Serial.println(hasilb); 
  digitalWrite(LedBiru,LOW);  
  delay(150);

  if(abs(hasilm-179)<k && abs(hasilh-179)<k && abs(hasilb-179)<k){
    Serial.println(" -> Gelas warna biru\n");
    servo1.write(60); 
    delay (3000);
    servo1.write(0);} else
  if(abs(hasilm-242)<k && abs(hasilh-242)<k && abs(hasilb-242)<k){
    Serial.println(" -> Gelas warna merah\n");
    servo2.write(60);    
    delay (3000);
    servo2.write(0);} else
  if(abs(hasilm-248)<k && abs(hasilh-248)<k && abs(hasilb-248)<k){
    Serial.println(" -> Gelas warna kuning\n");
    servo3.write(60);
    delay (3000);
    servo3.write(0);} else
    Serial.println(" -> ???\n");     
    
  delay (2000);
}