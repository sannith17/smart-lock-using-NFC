//RFID Door Lock System

#include <Wire.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
#define LED_G 4 //define green LED pin
#define LED_R 5 //define red LED
#define BUZZER 2 //buzzer pin
#define lock 3
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
int Btn = 6;
 
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  noTone(BUZZER);
  pinMode(Btn,INPUT);
  pinMode(lock,OUTPUT);

 }
void loop()}
 if(digitalRead(Btn) == HIGH){
  
    Serial.println("Access Granted");
    Serial.println();
    delay(500);
    digitalWrite(LED_G, HIGH);
    tone(BUZZER, 2000);
    delay(100);
    noTone(BUZZER);
    delay(50);
    tone(BUZZER, 2000);
    delay(100);
    noTone(BUZZER);
    digitalWrite(lock,HIGH);
    delay(3000);
    digitalWrite(lock,LOW);
    delay(100);
    digitalWrite(LED_G, LOW);
    tone(BUZZER, 2000);
    delay(100);
    noTone(BUZZER);
  delay(50);
  }


  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x27 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x27 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();


  
 if (content.substring(1) == "F3 8F C8 2F") //change here the UID of card/cards or tag/tags that you want to give access
  {
    Serial.println("Access Granted");
    Serial.println();
    delay(500);
    digitalWrite(LED_G, HIGH);
    tone(BUZZER, 2000);
    delay(100);
    noTone(BUZZER);
    delay(50);
    tone(BUZZER, 2000);
    delay(100);
    noTone(BUZZER);
    digitalWrite(lock,HIGH);

    delay(3000);
    digitalWrite(lock,LOW);
    delay(100);
    digitalWrite(LED_G, LOW);
    tone(BUZZER, 2000);
    delay(100);
    noTone(BUZZER);
    delay(50);
  }

else
{
    digitalWrite(LED_R, HIGH);
    tone(BUZZER, 1500);
    delay(500);
    digitalWrite(LED_R, LOW);
    noTone(BUZZER);
    delay(100);
    digitalWrite(LED_R, HIGH);
    tone(BUZZER, 1500);
    delay(500);
    digitalWrite(LED_R, LOW);
    noTone(BUZZER);
    delay(100);
    digitalWrite(LED_R, HIGH);
    tone(BUZZER, 1500);
    delay(500);
    digitalWrite(LED_R, LOW);
    noTone(BUZZER);
 }
 }

#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
 

 

  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();          // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(RELAY, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  noTone(BUZZER);
  digitalWrite(RELAY, HIGH);
  lcd.begin(16,2);
  lcd.setCursor(0,0); 
  lcd.print("Put card on rdr");
  Serial.println("Put your card to the reader...");
  Serial.println();
  
  

}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "14 26 84 7B") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
    lcd.setCursor(0,1); 
  lcd.print("Access Granted");
    delay(500);
    digitalWrite(RELAY, LOW);
    digitalWrite(LED_G, HIGH);
    delay(ACCESS_DELAY);
    digitalWrite(RELAY, HIGH);
    digitalWrite(LED_G, LOW);
  }
 
 else   {
    Serial.println(" Access denied");
    lcd.setCursor(0,1); 
  lcd.print("Access denied.");
    digitalWrite(LED_R, HIGH);
    tone(BUZZER, 300);
    delay(DENIED_DELAY);
    digitalWrite(LED_R, LOW);
    noTone(BUZZER);
  }
  
    lcd.setCursor(0,1);
    lcd.print("................");
}

