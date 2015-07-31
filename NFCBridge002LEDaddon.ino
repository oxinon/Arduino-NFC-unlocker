// NFC Computer Unlocker with NFC-bridge by elecfreaks with 
// Arduino ATmega 32U4 and PN532 NFC Chip
// and Thanks to Lewis for his first NFC Unlocker Project
// This code and howto on http://oxinon.com
// Preview Video on http://www.youtube.com/watch?v=ATToeXO42bI
// 17.09.2014 joeatx247


#include <Wire.h>
#include <Adafruit_NFCShield_I2C.h> // match for NFC Bridge


#define IRQ 4     // IRQ
#define RESET 5   // reset

Adafruit_NFCShield_I2C nfc(IRQ, RESET);


int ledpinb = A0; // blue
int ledping = A1; // green
int ledpinr = A2; // red
int ledpino = A3; // optocopler


// SETUP

void setup() {
  // Serial 9600 bps
  Serial.begin(9600);
  pinMode(7,OUTPUT);
  
 
  // find NFC
  nfc.begin();

  uint32_t versiondata = nfc.getFirmwareVersion();
  if (! versiondata) {
    Serial.print("error PN53x Connection");
    while (1); // stop
  }
  // read OK --> show info
  Serial.print("found chip PN532"); Serial.println((versiondata>>24) & 0xFF, HEX);
  Serial.print("Firmware ver. "); Serial.print((versiondata>>16) & 0xFF, DEC);
  Serial.print('.'); Serial.println((versiondata>>8) & 0xFF, DEC);
  
      // turn blue LED on
      for(int fadeValue = 255 ; fadeValue <= 255; fadeValue +=5) {
      analogWrite(ledpinb, fadeValue);
      delay(0);
      }
 
// read NFC tags
  nfc.SAMConfig();
Keyboard.begin(); //init Keyboard
}

// LOOP

unsigned digit = 0;

void loop() {
  uint8_t success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 }; // temp Speicher fuer UID
  uint8_t uidLength; // laenge der UID (4 or 7 bytes ISO14443A Card)
  
  
// wait for NFC
  Serial.println("Wait for NFC-Tag...");

   
  // Wait for an ISO14443A type cards (Mifare, etc.). When one is found
  // 'uid' will be populated with the UID, and uidLength will indicate
  // if the uid is 4 bytes (Mifare Classic) or 7 bytes (Mifare Ultralight)
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);

  uint32_t cardidentifier = 0;
 
  if (success) {
// found a card!

    Serial.print("found Tag #");
    // turn the four byte UID of a mifare classic into a single variable #
    cardidentifier = uid[3];
    cardidentifier <<= 8; cardidentifier |= uid[2];
    cardidentifier <<= 8; cardidentifier |= uid[1];
    cardidentifier <<= 8; cardidentifier |= uid[0];
    Serial.println(cardidentifier);
    
    
// Tag 1 
    if (cardidentifier == 3663943172) {
      for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) {
      analogWrite(ledpinb, fadeValue);
      delay(0);
      }
      for(int fadeValue = 255 ; fadeValue <= 255; fadeValue +=5) {
      analogWrite(ledping, fadeValue);
      delay(70);
      }
     
        // Keyboard action 1
        Keyboard.write(KEY_UP_ARROW);
        delay (800);
        
        digitalWrite(7,HIGH);
        
   
        Keyboard.write('p');
        Keyboard.write('a');
        Keyboard.write('s');
        Keyboard.write('s');
        Keyboard.write('w');
        Keyboard.write('o');
        Keyboard.write('r');
        Keyboard.write('d');
        
        Keyboard.write(KEY_RETURN);
        delay(1000); //makes sure the password isn't repeated

      for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) {
      analogWrite(ledping, fadeValue);
      delay(0);
      }
      for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) {
      analogWrite(ledpinb, fadeValue);
      delay(0);
      }
     }
      
// Tag 2 
    if (cardidentifier == 3859697829) {
      for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) {
      analogWrite(ledpinb, fadeValue);
      delay(0);
      }
      for(int fadeValue = 255 ; fadeValue <= 255; fadeValue +=5) {
      analogWrite(ledping, fadeValue);
      delay(70);
      }
     
        // Keyboard action 2
        Keyboard.write(KEY_UP_ARROW);
        delay (800);
        
        digitalWrite(7,HIGH);
        

        Keyboard.write('p');
        Keyboard.write('a');
        Keyboard.write('s');
        Keyboard.write('s');
        Keyboard.write('w');
        Keyboard.write('o');
        Keyboard.write('r');
        Keyboard.write('d');
 
        Keyboard.write(KEY_RETURN);
        delay(1000); //makes sure the password isn't repeated

      for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) {
      analogWrite(ledping, fadeValue);
      delay(0);
      }
      for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) {
      analogWrite(ledpinb, fadeValue);
      delay(0);
      }
    }
    
// Tag 3 
    if (cardidentifier == 589947533) {
      for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) {
      analogWrite(ledpinb, fadeValue);
      delay(0);
      }
      for(int fadeValue = 255 ; fadeValue <= 255; fadeValue +=5) {
      analogWrite(ledpinr, fadeValue);
      delay(70);
      }
     
        // Keyboard action 3
        Keyboard.write(KEY_UP_ARROW);
        delay (800);
        
        digitalWrite(7,HIGH);
        
        Keyboard.write('p');
        Keyboard.write('a');
        Keyboard.write('s');
        Keyboard.write('s');
        Keyboard.write('w');
        Keyboard.write('o');
        Keyboard.write('r');
        Keyboard.write('d');
        
        Keyboard.write(KEY_RETURN);
        delay(1000); //makes sure the password isn't repeated

      for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) {
      analogWrite(ledpinr, fadeValue);
      delay(0);
      }
      for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) {
      analogWrite(ledpinb, fadeValue);
      delay(0);
      }
     }
     
     
     
     // Tag 4 
    if (cardidentifier == 4063444996) {
      for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) {
      analogWrite(ledpinb, fadeValue);
      delay(0);
      }
      for(int fadeValue = 255 ; fadeValue <= 255; fadeValue +=5) {
      analogWrite(ledpino, fadeValue);
      delay(70);
      }
     
        // Keyboard action 3
        Keyboard.write(KEY_UP_ARROW);
        delay (800);
        
        digitalWrite(7,HIGH);
        
        Keyboard.write('p');
        Keyboard.write('a');
        Keyboard.write('s');
        Keyboard.write('s');
        Keyboard.write('w');
        Keyboard.write('o');
        Keyboard.write('r');
        Keyboard.write('d');
        
        Keyboard.write(KEY_RETURN);
        delay(1000); //makes sure the password isn't repeated

      for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) {
      analogWrite(ledpino, fadeValue);
      delay(0);
      }
      for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) {
      analogWrite(ledpinb, fadeValue);
      delay(0);
      }
     }
     
     
  }
}


// Keyboard driver german Decimal Layout
//
// .  -32-
//.!. -33-
//.Ä. -34-
//.§. -35-
//.$. -36-
//.%. -37-
//./. -38-
//.ä. -39-
//.). -40-
//.=. -41-
//.(. -42-
//.`. -43-
//.,. -44-
//.ß. -45-
//... -46-
//.-. -47-


//.0. -48-
//.1. -49-
//.2. -50-
//.3. -51-
//.4. -52-
//.5. -53-
//.6. -54-
//.7. -55-
//.8. -56-
//.9. -57-


//.Ö. -58-
//.ö. -59-
//.;. -60-
//.´. -61-
//.smiley-small -62-
//._. -63-
//.". -64-


//.A. -65-
//.B. -66-
//.C. -67-
//.D. -68-
//.E. -69-
//.F. -70-
//.G. -71-
//.H. -72-
//.I. -73-
//.J. -74-
//.K. -75-
//.L. -76-
//.M. -77-
//.N. -78-
//.O. -79-
//.P. -80-
//.Q. -81-
//.R. -82-
//.S. -83-
//.T. -84-
//.U. -85-
//.V. -86-
//.W. -87-
//.X. -88-
//.Z. -89-
//.Y. -90-


//.ü. -91-
//.#. -92-
//.+. -93-
//.&. -94-
//.?. -95-
//.^. -96-


//.a. -97-
//.b. -98-
//.c. -99-
//.d. -100-
//.e. -101-
//.f. -102-
//.g. -103-
//.h. -104-
//.i. -105-
//.j. -106-
//.k. -107-
//.l. -108-
//.m. -109-
//.n. -110-
//.o. -111-
//.p. -112-
//.q. -113-
//.r. -114-
//.s. -115-
//.t. -116-
//.u. -117-
//.v. -118-
//.w. -119-
//.x. -120-
//.z. -121-
//.y. -122-
//.Ü. -123-
//.'. -124-
//.*. -125-
//.°. -126-


//.a. -140-
//.b. -141-
//.c. -142-
//.d. -143-
//.e. -144-
//.f. -145-
//.g. -146-
//.h. -147-
//.i. -148-
//.j. -149-
//.k. -150-
//.l. -151-
//.m. -152-
//.n. -153-
//.o. -154-
//.p. -155-
//.q. -156-
//.r. -157-
//.s. -158-
//.t. -159-
//.u. -160-
//.v. -161-
//.w. -162-
//.x. -163-
//.z. -164-
//.y. -165-


//.1. -166-
//.2. -167-
//.3. -168-
//.4. -169-
//.5. -170-
//.6. -171-
//.7. -172-
//.8. -173-
//.9. -174-
//.0. -175-
//. . -180-
//.ß. -181-
//.´. -182-
//.ü. -183-
//.+. -184-
//.#. -185-
//.#. -186-
//.ö. -187-
//.ä. -188-
//.^. -189-
//.,. -190-
//... -191-
//.-. -192-


//KEY_LEFT_CTRL	  -128-
//KEY_LEFT_SHIFT  -129-
//KEY_LEFT_ALT	  -130-
//KEY_LEFT_GUI	  -131-
//KEY_RIGHT_CTRL  -132-
//KEY_RIGHT_SHIFT -133-
//KEY_RIGHT_ALT	  -134-
//KEY_RIGHT_GUI	  -135-
//KEY_UP_ARROW	  -218-
//KEY_DOWN_ARROW  -217-
//KEY_LEFT_ARROW  -216-
//KEY_RIGHT_ARROW -215-
//KEY_BACKSPACE	  -178-
//KEY_TAB	  -179-
//KEY_RETURN	  -176-
//KEY_ESC	  -177-
//KEY_INSERT	  -209-
//KEY_DELETE	  -212-
//KEY_PAGE_UP	  -211-
//KEY_PAGE_DOWN	  -214-
//KEY_HOME	  -210-
//KEY_END	  -213-
//KEY_CAPS_LOCK	  -193-
//KEY_F1	  -194-
//KEY_F2	  -195-
//KEY_F3	  -196-
//KEY_F4	  -197-
//KEY_F5 	  -198-
//KEY_F6	  -199-
//KEY_F7	  -200-
//KEY_F8	  -201-
//KEY_F9	  -202-
//KEY_F10	  -203-
//KEY_F11	  -204-
//KEY_F12	  -205-

