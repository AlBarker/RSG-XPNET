#define ENCODER_OPTIMIZE_INTERRUPTS
#include <Encoder.h>
#include <Bounce2.h>

Bounce buttonCDI = Bounce(32,5);

Encoder navFine = Encoder(53, 52); //GPS1 Nav Freq Fine
Encoder navCoarse = Encoder(51, 50); //GPS1 Nav Freq Fine
Encoder Chapter = Encoder(31, 30); //GPS1 Chapter Up/Dn
Encoder Page = Encoder(47, 46); //GPS1 Page Up/Dn

//variables
long encoderNavFine_prev=0;  //for detecting rotary position change
long encoderNavCoarse_prev=0;  //for detecting rotary position change
long encoderChapter_prev=0;  //for detecting rotary position change
long encoderPage_prev=0;  //for detecting rotary position change

long positionLeft = -999;

int NavFreqFine = 900;
int NavFreqCoarse = 115;
int eChapter = 0;
int ePage = 0;

void setup() {

  
  // initialize the button pin as a input:
  pinMode(32, INPUT_PULLUP);
  pinMode(33, INPUT_PULLUP);
  pinMode(34, INPUT_PULLUP);
  pinMode(35, INPUT_PULLUP);
  pinMode(36, INPUT_PULLUP);
  pinMode(37, INPUT_PULLUP);
  pinMode(38, INPUT_PULLUP);
  pinMode(39, INPUT_PULLUP);
  pinMode(40, INPUT_PULLUP);
  pinMode(41, INPUT_PULLUP);
  pinMode(42, INPUT_PULLUP);
  pinMode(43, INPUT_PULLUP);
  pinMode(44, INPUT_PULLUP);
  pinMode(45, INPUT_PULLUP);
  pinMode(48, INPUT_PULLUP);
  pinMode(49, INPUT_PULLUP);
 
  // initialize the LED as an output:
  pinMode(13, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
}

void loop() {

//read the rotary encoder, if it's changed, wite to output var

int efDelta = 0;
long encNavFine = navFine.read();
encNavFine = encNavFine/2; //to deal with 1/2 cycle encoder hardware
if (encNavFine != encoderNavFine_prev) {
 // NavFreqFine = NavFreqFine + (encNavFine - encoderNavFine_prev);
 efDelta = encNavFine - encoderNavFine_prev;
  encoderNavFine_prev = encNavFine;
  Serial.print("Encoder Nav Freq Fine ");
  Serial.print(efDelta);
  Serial.print("\n");
}

//read the rotary encoder, if it's changed, wite to output var
int ncDelta = 0;
long encNavCoarse = navCoarse.read();
encNavCoarse = encNavCoarse/2; //to deal with 1/2 cycle encoder hardware

if (encNavCoarse != encoderNavCoarse_prev) {
  //NavFreqCoarse = NavFreqCoarse + (encNavCoarse - encoderNavCoarse_prev);
  ncDelta = encNavCoarse - encoderNavCoarse_prev;
  encoderNavCoarse_prev = encNavCoarse;
  Serial.print("Encoder Nav Freq Coarse ");
  Serial.print(ncDelta);
  Serial.print("\n");
}

//read the rotary encoder, if it's changed, wite to output var
int chapDelta = 0;
long encChapter = Chapter.read();
encChapter = encChapter/2; //to deal with 1/2 cycle encoder hardware

if (encChapter != encoderChapter_prev) {
 // eChapter = eChapter + (encChapter - encoderChapter_prev);
  chapDelta = encChapter - encoderChapter_prev;
  encoderChapter_prev = encChapter;
  Serial.print("Encoder Chapter ");
  Serial.print(chapDelta);
  Serial.print("\n");
}

//read the rotary encoder, if it's changed, wite to output var
int pageDelta = 0;
long encPage = Page.read();
encPage = encPage/2; //to deal with 1/2 cycle encoder hardware

if (encPage != encoderPage_prev) {
  //ePage = ePage + (encPage - encoderPage_prev);
  pageDelta = encPage - encoderPage_prev;
  encoderPage_prev = encPage;
  Serial.print("Encoder Page ");
  Serial.print(pageDelta);
  Serial.print("\n");
}


    if ((digitalRead(32)) == LOW) {
      Serial.print("sim/GPS/g430n1_proc");
      Serial.print("\n");
      delay(250);
    } else {
        if ((digitalRead(33)) == LOW) {
          Serial.print("sim/GPS/g430n1_cdi");
          Serial.print("\n");
          delay(250);
        } else {
          if ((digitalRead(34)) == LOW) {
            Serial.print("sim/GPS/g430n1_fpl");
            Serial.print("\n");
            delay(250);
          } else {
            if ((digitalRead(35)) == LOW) {
              Serial.print("sim/GPS/g430n1_vnav");
              Serial.print("\n");
              delay(250);
            } else {
              if ((digitalRead(36)) == LOW) {
                Serial.print("sim/GPS/g430n1_obs");
                Serial.print("\n");
                delay(250);
            } else {
              if ((digitalRead(37)) == LOW) {
                Serial.print("sim/GPS/g430n1_msg");
                Serial.print("\n");
                delay(250);
            } else {
              if ((digitalRead(38)) == LOW) {
                Serial.print("sim/GPS/g430n1_nav_ff");
                Serial.print("\n");
                delay(250);
            } else {
              if ((digitalRead(39)) == LOW) {
                Serial.print("sim/GPS/g430n1_com_ff");
                Serial.print("\n");
                delay(250);
            } else {
              if ((digitalRead(40)) == LOW) {
                Serial.print("sim/GPS/g430n1_zoom_in");
                Serial.print("\n");
                delay(250);
            } else {
              if ((digitalRead(41)) == LOW) {
                Serial.print("sim/GPS/g430n1_zoom_out");
                Serial.print("\n");
                delay(250);
            } else {
              if ((digitalRead(42)) == LOW) {
                Serial.print("sim/GPS/g430n1_menu");
                Serial.print("\n");
                delay(250);
            } else {
              if ((digitalRead(43)) == LOW) {
                Serial.print("sim/GPS/g430n1_direct");
                Serial.print("\n");
                delay(250);
            } else {
              if ((digitalRead(44)) == LOW) {
                Serial.print("sim/GPS/g430n1_ent");
                Serial.print("\n");
                delay(250);
            } else {
              if ((digitalRead(45)) == LOW) {
                Serial.print("sim/GPS/g430n1_clr");
                Serial.print("\n");
                delay(250);
            } else {
              if ((digitalRead(48)) == LOW) {
                Serial.print("sim/GPS/g430n1_cursor");
                Serial.print("\n");
                delay(250);
            } else {
              if ((digitalRead(49)) == LOW) {
                Serial.print("sim/GPS/g430n1_nav_com_tog");
                Serial.print("\n");
                delay(250);
            }
            }
            }
    
          }
        }
    }
}
            }
            }
            }
            }
            }
            }
          }
        }
    }
}
 

//BUTTONS
//32 GPS1 PROC
//33 GPS1 CDI
//34 GPS1 FPL
//35 GPS1 VNAV
//36 GPS1 OBS
//37 GPS1 MSG
//38 GPS1 NAV Flip
//39 GPS1 COM Flip
//40 GPS1 Zoom In
//41 GPS1 Zoom Out
//42 GPS1 Menu
//43 GPS1 Direct
//44 GPS1 Enter
//45 GPS1 Clr
//48 GPS1 Push Cursor
//49 GPS1 NAV/COM toggle active

//Encoders
//30 GPS1 Chapter UP/DN encoder
//31 second pin
//46 GPS1 Page UP/DN encoder
//47 second pin
//50 G430 COM/NAV1 coarse encoder
//51 second pin
//52 G430 COM/NAV1 fine encoder  
//53 second pin
