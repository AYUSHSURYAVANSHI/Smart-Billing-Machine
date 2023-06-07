#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4); 
#include <SPI.h>
#include <MFRC522.h>
 int total = 0;
 int temp = 0;
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 
void setup() 
{
  lcd.init();  
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Proj: Automatic");
   lcd.setCursor(0,1);
  lcd.print(" Billing Machine");
  delay(2000);
  lcd.clear();
lcd.setCursor(0,0);
lcd.print("Guided By:");
lcd.setCursor(0,1);
lcd.print("ANKITA SHIRIVASTAV ");
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("MADE by:");
lcd.setCursor(0,1);
lcd.print("LOKENDRA YADAV ");
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("MADE by:");
lcd.setCursor(0,1);
lcd.print("NIKET VISHWAKARMA");
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("MADE by:");
lcd.setCursor(0,1);
lcd.print("SATYAM YADAV");
delay(2000);
lcd.clear();
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("MADE by:");
lcd.setCursor(0,1);
lcd.print("ABHISHEK SHAKYA");
delay(2000);
lcd.clear();
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  delay(1000);
  digitalWrite(2, LOW);

  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();

}
void loop() 
{
  lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Total Bill: ");
    lcd.print(total);
    delay(500);
  
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
  if (content.substring(1) == "7B 66 7C 36") //change here the UID of the card/cards that you want to give access
  {
   digitalWrite(2, HIGH);
  lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Item: Biscuit ");
    lcd.setCursor(0,1);
    lcd.print("Price : +10");
   delay(100);
  digitalWrite(2, LOW);
    delay(1400);
    total += 10;
    temp = 1;
    lcd.clear();
    lcd.print("Total Bill: ");
    lcd.print(total);
    delay(500);
    
  }
   if (content.substring(1) == "CA 57 56 19") //change here the UID of the card/cards that you want to give access
  {
   digitalWrite(2, HIGH);
  lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Item: COCO COLA ");
    lcd.setCursor(0,1);
    lcd.print("Price : +30");
   delay(100);
  digitalWrite(2, LOW);
    delay(1400);
    total += 30;
    temp = 2;
    lcd.clear();
    lcd.print("Total Bill: ");
    lcd.print(total);
    delay(500);
    
  }
  if (content.substring(1) == "9A B7 4C 19" ) //change here the UID of the card/cards that you want to give access
  {
      digitalWrite(2, HIGH);
  lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Item: Chocolate ");
    lcd.setCursor(0,1);
    lcd.print("Price : +20");
   delay(100);
  digitalWrite(2, LOW);
    delay(1400);
    total += 20;
    temp = 3;
    lcd.clear();
    lcd.print("Total Bill: ");
    lcd.print(total);
    delay(500);
  }
  if (content.substring(1) == "9C 2E 3E 2F" && temp == 1) //change here the UID of the card/cards that you want to give access
  {
      digitalWrite(2, HIGH);
  lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Item: Biscuit ");
    lcd.setCursor(0,1);
    lcd.print("Price : -10");
   delay(100);
  digitalWrite(2, LOW);
    delay(1400);
    total -= 10;
    temp = 0;
    lcd.clear();
    lcd.print("Total Bill: ");
    lcd.print(total);
    delay(500);
  }
  if (content.substring(1) == "CA 57 56 19" && temp == 2) //change here the UID of the card/cards that you want to give access
  {
      digitalWrite(2, HIGH);
  lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Item: COCO COLA ");
    lcd.setCursor(0,1);
    lcd.print("Price : -30");
   delay(100);
  digitalWrite(2, LOW);
    delay(1400);
    total -= 30;
    temp = 0;
    lcd.clear();
    lcd.print("Total Bill: ");
    lcd.print(total);
    delay(500);
  }
  if (content.substring(1) == "9C 2E 3E 2F" && temp == 3) //change here the UID of the card/cards that you want to give access
  {
     digitalWrite(2, HIGH);
  lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Item: Chocolate ");
    lcd.setCursor(0,1);
    lcd.print("Price : -20");
   delay(100);
  digitalWrite(2, LOW);
    delay(1400);
    total -= 20;
    temp = 0;
    lcd.clear();
    lcd.print("Total Bill: ");
    lcd.print(total);
    delay(500);
  }
 
}
