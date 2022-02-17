#include <Arduino.h>
#include <LiquidCrystal.h>
#include <globalVar.h>
extern "C" {
  #include <func_spiout.h>
}

extern "C" { 
  #include <func_spgmess.h>
}

extern "C"{
  #include <func_strmess.h>
}

extern "C"{
  #include <func_error.h>
}

String aZeile1 = "BFW MUENCHEN";
String aZeile2 = "EGS 28 und 34";        
String aZeile3 = " ";
String aZeile4 = "Platinentester";
String bZeile1 = "Platine anschliessen";
String bZeile3 = "Test starten";


//-------------------------------PINS-----------------------------------------
//A0= + spg; A1= - spg; A2= Strom ;
int opto = A4; int AUS = A5;
             
byte AD_0 = A0, AD_1 = A1, AD_2 = A2, AD_5 = A5;

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
 
 // while(digitalRead(Taster)== HIGH);           // Für Testbetrieb Dauerhaft Taster gedrückt
  //{}

 pinMode(Taster, OUTPUT);
 digitalWrite(Taster,LOW);
 delay(2000);
 lcd.clear();
 lcd.print("Taster gedrueckt");

 delay(2000);

}

void loop()
{
 
if (digitalRead(A_X14) == LOW)
      {
          // Spannungsmessung V5_K19 
          delay(500);  
          lcd.clear();
          lcd.setCursor(1,1);
          lcd.print("Spannungsmessung");
          delay(1000); 
          func_spgmess_V5_K19();
          V5_K19 = (analogRead(A0));
          
          lcd.clear();
          lcd.setCursor(1,0);
          lcd.print("V5K19:");
          if ((V5_K19 > 120) && (V5_K19 < 280))
            {
             lcd.setCursor(7,0); 
             lcd.print("+"); 
             delay(500);
                               
            }
          else
          {
            lcd.setCursor(7,0);
            lcd.print("-");
            func_error();
          } 

          // Spannungsmessung V12_K19
          delay(200);
          func_spgmess_V12_K19();
          V12_K19 = (analogRead(A0));
          lcd.setCursor(0,1);
          lcd.print("V12K19:");
          if ((V12_K19 > 370) && (V12_K19 < 600))
          {
            lcd.setCursor(7,1);
            lcd.print("+");
            delay(500);
          }
          else
          {
            lcd.setCursor(7,1);
            lcd.print("-");
            func_error();
          }

          //Spannungsmessung V12_K20
          delay(200);
          func_spgmess_V12_K20();
          V12_K20 = (analogRead(A0));
          lcd.setCursor(0,2);
          lcd.print("V12K20:");
          delay(500);
          if ((V12_K19 > 370) && (V12_K19 < 600))
                    {
            lcd.setCursor(7,2);
            lcd.print("+");
            delay(500);
          }
          else
          {
            lcd.setCursor(7,2);
            lcd.print("-");
            func_error();
          }
          //Spannungsmessung Vneg12_K19
          delay(200);
          func_spgmess_Vneg12_K19();
          Vneg12_K19 = (analogRead(A1));
          lcd.setCursor(0,3);
          lcd.print("V-12K19:");
          delay(500);
          if ((Vneg12_K19 > 370) && (Vneg12_K19 < 600))
                    {
            lcd.setCursor(8,3);
            lcd.print("+");
            delay(500);
          }
          else
          {
            lcd.setCursor(8,3);
            lcd.print("-");
            func_error();
          }
         //Spannungsmessung Vneg12_K20
          delay(200);
          func_spgmess_Vneg12_K20();
          Vneg12_K20 = (analogRead(A1));
          lcd.setCursor(11,0);
          lcd.print("V-12K20:");
          delay(500);
          if ((Vneg12_K20 > 370) && (Vneg12_K20 < 600))
                    {
            lcd.setCursor(19,0);
            lcd.print("+");
            delay(500);
          }
          else
          {
            lcd.setCursor(19,0);
            lcd.print("-");
            func_error();
          }
           //Spannungsmessung Vadj_K20
          delay(200);
          func_spgmess_Vneg12_K20();
          Vadj_K20 = (analogRead(A0));
          lcd.setCursor(16,3);
          lcd.print(Vadj_K20);
          lcd.setCursor(11,1);
          lcd.print("VadjK20:");
          delay(500);

          //hier Spannung an Poti senden ////SET SPI 255
          digitalWrite(SCK_, LOW);
          delay(1);
          digitalWrite(CS, LOW);
          func_spiout(255);    
            
          digitalWrite(CS, HIGH);
          delay(1000);
          Vadj_K20 = analogRead(A0);
          lcd.setCursor(16,3);
          lcd.print(Vadj_K20);

          if ((Vadj_K20 > 0) && (Vadj_K20 < 1000))
                    {
            lcd.setCursor(19,1);
            lcd.print("+");
            delay(500);
          }
          else
          {
            lcd.setCursor(19,1);
            lcd.print("-");
            func_error();
          } 
          //Spannungsmessung VU_K19
          delay(200);
          func_spgmess_VU_K19();
          VU_K19 = (analogRead(A0));
          lcd.setCursor(13,2);
          lcd.print("VUK19:");
          delay(500);
          if ((VU_K19 > 0) && (VU_K19 < 1000))
          {
            lcd.setCursor(19,2);
            lcd.print("+");
            delay(10000);
          }
          else
          {
            lcd.setCursor(19,2);
            lcd.print("-");
            func_error();
            delay(10000);
          } 
      


  
          delay(500);  
          lcd.clear();
          lcd.setCursor(4,1);
          lcd.print("Strommessung");
          delay(2000);
          func_strmess_neg12V();
          Ineg12 = (analogRead(A2)); // zeile kommt weg wenn programm Funktuniert
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("-12V:");
          lcd.setCursor(10,0);
          lcd.print(Ineg12);          // zeile kommt weg wenn programm Funktuniert
          if ((Ineg12 > 370) && (Ineg12 < 600))
            {
             lcd.setCursor(5,0); 
             lcd.print("+"); 
             delay(500);
            }
          else
          {
            lcd.setCursor(5,0);
            lcd.print("-");
            func_error();
          }
          delay(500);
          func_strmess_neg12VBeg();
          I = (analogRead(A2));
          lcd.setCursor(0,1);
          lcd.print("-12V Beg:");
          lcd.setCursor(0,3);
          lcd.print(I);
          if (I < 1)
            {
              lcd.setCursor(9,1);
              lcd.print("+");
              delay(5000);
            }
          else
          {
            lcd.setCursor(9,1);
            lcd.print("-");
            delay(5000);
          }
          

          
          func_spgmess();
      
         
      }


  



  
}




