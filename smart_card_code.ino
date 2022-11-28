#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance.
int buzzer = 2;
int LED = 3;
void setup() {
// put your setup code here, to run once:
pinMode(7,1);
pinMode(6,1);
Serial.begin(9600); // Initiate a serial communication
SPI.begin(); // Initiate SPI bus
mfrc522.PCD_Init(); // Initiate MFRC522
pinMode(buzzer, OUTPUT);
pinMode(LED,OUTPUT);
}
void loop() {
// put your main code here, to run repeatedly:
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
String content= "";
byte letter;
for (byte i = 0; i < mfrc522.uid.size; i++)
{
content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
content.concat(String(mfrc522.uid.uidByte[i], HEX));
}
content.toUpperCase();
if (content.substring(1) == "E7 1D 5B C9") //change here the UID of the card/cards that you
want to give access
{
digitalWrite(LED, HIGH);
delay(500);
digitalWrite(buzzer, HIGH); //tun buzzer
delay(500);
Serial.println("YOUNEX RACKET : 800");
digitalWrite(buzzer, LOW);
digitalWrite(LED, LOW);
digitalWrite(6,0);
delay(1000);
}
else if (content.substring(1) == "F3 F1 DB 1A") //change here the UID of the card/cards that
you want to give access
{
digitalWrite(LED, HIGH);
delay(500);
digitalWrite(buzzer, HIGH); //tun buzzer
delay(500);
Serial.println("YOUNEX SHUTTLE : 500");
digitalWrite(buzzer, LOW);
digitalWrite(LED, LOW);
digitalWrite(7,0);
delay(1000);
}
}
