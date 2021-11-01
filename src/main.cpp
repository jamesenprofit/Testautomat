#include <Arduino.h>
#include <LiquidCrystal.h>
#include <spi_out.h>

String aZeile1 = "BFW MUENCHEN";
String aZeile2 = "EGS 28 und 34";        
String aZeile3 = " ";
String aZeile4 = "Platinentester";
String bZeile1 = "Platine anschliessen";
String bZeile3 = "Test starten";

void spi_out_(byte dat);                    // Daten über SPI senden

//-------------------------------PINS-----------------------------------------
//A0= + spg; A1= - spg; A2= Strom ;
int opto = A4; int AUS = A5;
int Taster = 2;                   byte CS = 13;           byte SCK_ = 5;
int LED = 3;                      byte SDA_ = 4;


//-4051-----MUX--------4052----     -----------------LCD--------------------
byte A_X14 = 10;         byte a_IC2a = 0;      byte D4 = 4;    byte D5 = 5;    byte D6 = 6;
byte B_X14 = 11;         byte b_IC2a = 1;      byte D7 = 7;    byte RS = 8;    byte EN = 9;
byte C_X14 = 12;         byte AD_0 = A0;        byte AD_1 = A1;  byte AD_2 = A2;  byte AD_5 = A5;

int V5_K19 ;          int V12_K19;         int Vneg12_K19;
int V12_K20;          int Vneg12_K20;         
int Vadj_K20;         int Vadj_min;        int Vadj_max;

int VU_K20;
int posSpg;             int negSpg;         int Spg;
int Ineg12;             int Iadj;           int I; 

int error;

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup()
{
  
 
 pinMode(A_X14, OUTPUT);
 pinMode(B_X14, OUTPUT);
 pinMode(C_X14, OUTPUT);

 pinMode(LED, OUTPUT);
 
 pinMode(AD_0, INPUT);
 pinMode(AD_1, INPUT);
 pinMode(AD_2, INPUT);

 pinMode(AD_5, OUTPUT);
 
 pinMode(SCK_, OUTPUT);
 pinMode(CS, OUTPUT);
 pinMode(SDA_, OUTPUT);
 digitalWrite(SCK_, LOW);
                    
 pinMode(a_IC2a, OUTPUT);
 pinMode(b_IC2a, OUTPUT);
 pinMode(Taster,INPUT_PULLUP); 

 digitalWrite(A_X14, LOW); // LSB
 digitalWrite(B_X14, LOW);
 digitalWrite(C_X14, LOW);  // MSB

 digitalWrite(a_IC2a, LOW); // LSB
 digitalWrite(b_IC2a, LOW); // MSB

 digitalWrite(AD_5, LOW);   // AUS=LOW ...also AN! (einstellberer regler)

 digitalWrite(LED, LOW);

  // set up the LCD's number of columns(Spalte) and rows(Zeile):
 lcd.begin(20,4);
 lcd.setCursor(0,0);
 lcd.print("Platine Anschliessen");
 lcd.setCursor(0,1);        
 lcd.print("Taster druecken");
 
  while(digitalRead(Taster)== HIGH);           // Für Testbetrieb Dauerhaft Taster gedrückt
  {}

 pinMode(Taster, OUTPUT);
 digitalWrite(Taster,LOW);
 delay(4000);
 lcd.clear();
 lcd.print("Taster gedrueckt");

 delay(2000);

}

void loop()
{
        
if (digitalRead(A_X14) == LOW)
      {
       
       
       
       
       delay(500);  
      
       lcd.clear();
       lcd.setCursor(1,1);
       lcd.print("Spannungsmessung 1"); 
       
       digitalWrite(A_X14, HIGH);   // LSB
       digitalWrite(B_X14, LOW);
       digitalWrite(C_X14, LOW);  // MSB
      
       digitalWrite(a_IC2a, LOW); // LSB
       digitalWrite(b_IC2a, LOW); // MSB
       delay(200);
              
      VU_K20 = (analogRead(AD_0));
          
       delay(300); 

       digitalWrite(A_X14, LOW);   // LSB
       digitalWrite(B_X14, HIGH);
       digitalWrite(C_X14, LOW);  // MSB
      
       digitalWrite(a_IC2a, LOW); // LSB
       digitalWrite(b_IC2a, LOW); // MSB

       delay(200); 
        
       Vadj_K20 = (analogRead(AD_0));

       digitalWrite(A_X14, HIGH); // LSB
       digitalWrite(B_X14, HIGH);
       digitalWrite(C_X14, LOW);  // MSB
      
       digitalWrite(a_IC2a, LOW); // LSB
       digitalWrite(b_IC2a, LOW); // MSB
       
      Vneg12_K20 = (analogRead(AD_1));

      delay(200);

       digitalWrite(A_X14, LOW);   // LSB
       digitalWrite(B_X14, LOW);
       digitalWrite(C_X14, HIGH);  // MSB
      
       digitalWrite(a_IC2a, LOW); // LSB
       digitalWrite(b_IC2a, LOW); // MSB
       delay(200);

      V12_K20 = (analogRead(AD_0));

    digitalWrite(A_X14, HIGH);   // LSB
    digitalWrite(B_X14, LOW);
    digitalWrite(C_X14, HIGH);  // MSB
    
    digitalWrite(a_IC2a, LOW); // LSB
    digitalWrite(b_IC2a, LOW); // MSB
    delay(200);

    Vneg12_K19 = (analogRead(AD_1));

    digitalWrite(A_X14, LOW);   // LSB
    digitalWrite(B_X14, HIGH);
    digitalWrite(C_X14, HIGH);  // MSB
    
    digitalWrite(a_IC2a, LOW); // LSB
    digitalWrite(b_IC2a, LOW); // MSB
    delay(200);

    V12_K19 = (analogRead(AD_0));

    digitalWrite(A_X14, HIGH);   // LSB
    digitalWrite(B_X14, HIGH);
    digitalWrite(C_X14, HIGH);  // MSB
    
    digitalWrite(a_IC2a, LOW); // LSB
    digitalWrite(b_IC2a, LOW); // MSB
    delay(200);

   V5_K19 = (analogRead(AD_0));
      }

if ((VU_K20 < 102) || (VU_K20 > 820) && (error<=3))
                  {
                    error++;
                  lcd.print("Meldung");
                  }
  
      {




        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Soll:5V   IST:");
        float Rech2 = 5*5*V5_K19/1024;
        lcd.print(Rech2);
        lcd.print("V");

          Rech2 = 5*5*V5_K19/1024;
        delay(10000);

      }

if (digitalRead(A_X14) == HIGH) 

    {
      
      lcd.clear();
      lcd.setCursor(2,1);
      lcd.print("Strommessung");
    
    digitalWrite(A_X14, LOW);   // LSB
    digitalWrite(B_X14, HIGH);
    digitalWrite(C_X14, LOW);  // MSB
    
    digitalWrite(a_IC2a, HIGH); // LSB
    digitalWrite(b_IC2a, LOW);  // MSB
    delay(200);
    
          //hier Spannung an Poti senden ////SET SPI 255
          digitalWrite(SCK_, LOW);
          delay(1);
          digitalWrite(CS, LOW);
          spi_out_(0);     //

          digitalWrite(CS, HIGH);
          delay(10000);
          Vadj_K20 = analogRead(A0);
          //Vadj_min=analogRead(A0);


          //hier Spannung an Poti senden //SET SPI 0
          digitalWrite(SCK_, LOW);
          delay(1);
          digitalWrite(CS, LOW);
          spi_out_(255);
          //Rausnehmen nur zum anschauen
          digitalWrite(CS, HIGH);
          delay(10000);

          Vadj_max = analogRead(A0);
    }

// function error()

//   if()
//   {
//     lcd.print("");
//   }

}

// void spi_out_(byte dat)  // Daten über SPI senden
// {
//   byte i = 8;                                             //dat = z.B. 15 = B0000 1111
//   do
//   { //          <<1          <<1         <<1          <<1          <<1         <<1         <<1
//     if (dat & 0x80)                                    //0000 1111    0001 1110   0011 1100    0111 1000    1111 0000    1110 0000   1100 0000    1000 0000
//       digitalWrite(SDA_, HIGH);                        //1000 0000    1000 0000   1000 0000    1000 0000    1000 0000    1000 0000   1000 0000    1000 0000
//     else                                               //0000 0000                                          1000 0000
//       digitalWrite(SDA_, LOW);                         //   LOW         LOW          LOW         LOW           HIGH        HIGH         HIGH        HIGH

//     delayMicroseconds(60);
//     digitalWrite(SCK_, HIGH);
//     delayMicroseconds(60);

//     dat <<= 1;

//     digitalWrite(SCK_, LOW);
//     delayMicroseconds(50);
//   } while (--i);


// }
