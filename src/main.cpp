#include <Arduino.h>
#include <LiquidCrystal.h>

extern "C" {
  #include <func_spiout.h>
}
#include <globalVar.h>
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
          lcd.print("Spannungsmessung"); 
          func_spgmess_V5_K19();
          V5_K19 = (analogRead(A0));
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("5V");
          lcd.setCursor(10,0);
          lcd.print(V5_K19);
          if ((V5_K19 > 120) || (V5_K19 < 280))
            {
             lcd.print("+"); 
             delay(1000);
            }
          else
          {
            lcd.print("-");
            func_error;
          }    
      }
if (digitalRead(A_X14) == HIGH)
{
          delay(500);  
          
          lcd.clear();
          lcd.setCursor(1,1);
          lcd.print("Strommessung"); 
          func_strmess_neg12V();
          Ineg12 = (analogRead(A2));
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("-12V");
          lcd.setCursor(10,0);
          lcd.print(Ineg12);
          if ((Ineg12 > 120) || (Ineg12 < 280))
            {
             lcd.print("+"); 
             delay(1000);
            }
          else
          {
            lcd.print("-");
            error++;
          }    
}
// if ((VU_K20 < 102) || (VU_K20 > 820) && (error<=3))
//                   {
//                     error++;
//                   lcd.print("Meldung");
//                   }
  
//       {




// if (digitalRead(A_X14) == HIGH) 

//     {
      
//       lcd.clear();
//       lcd.setCursor(2,1);
//       lcd.print("Strommessung");
    
//     digitalWrite(A_X14, LOW);   // LSB
//     digitalWrite(B_X14, HIGH);
//     digitalWrite(C_X14, LOW);  // MSB
    
//     digitalWrite(a_IC2a, HIGH); // LSB
//     digitalWrite(b_IC2a, LOW);  // MSB
//     delay(200);
    
//           //hier Spannung an Poti senden ////SET SPI 255
//           digitalWrite(SCK_, LOW);
//           delay(1);
//           digitalWrite(CS, LOW);
//           spiout(0);     
            
//           digitalWrite(CS, HIGH);
//           delay(10000);
//           Vadj_K20 = analogRead(A0);
//           //Vadj_min=analogRead(A0);


//           //hier Spannung an Poti senden //SET SPI 0
//           digitalWrite(SCK_, LOW);
//           delay(1);
//           digitalWrite(CS, LOW);
//           spiout(255);
//           //Rausnehmen nur zum anschauen
//           digitalWrite(CS, HIGH);
//           delay(10000);

//           Vadj_max = analogRead(A0);
//     }

// function error()

//   if()
//   {
//     lcd.print("");
//   }

}


