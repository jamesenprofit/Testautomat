#include <Arduino.h>
#include <LiquidCrystal.h>






//-------------------------------PINS-----------------------------------------
//A0= + spg; A1= - spg; A2= Strom ;
int opto = A4; int AUS = A5;
int Taster = 2;                   byte CS = 13;           byte SCK_ = 5;
int LED = 3;                       byte SDA_ = 4;


//-4051-----MUX--------4052----     -----------------LCD--------------------
byte A_X14 = 10;         byte a_IC2a = 0;      byte D4 = 4;    byte D5 = 5;    byte D6 = 6;
byte B_X14 = 11;         byte b_IC2a = 1;      byte D7 = 7;    byte RS = 8;    byte EN = 9;
byte C_X14 = 12;         byte AD_0 = A0;        byte AD_1 = A1;  byte AD_2 = A2;  byte ADP = A5;

int V5_K19 ;          int V12_K19;        int Vneg12_K19;
int V12_K20;          int Vneg12_K20;         
int Vadj_K20;         int Vadj_min;        int Vadj_max;

int VU_K20;
int posSpg;                    int negSpg;                   int Spg;
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

 pinMode(ADP, OUTPUT);
 
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

 digitalWrite(ADP, LOW);

 digitalWrite(LED, LOW);

 digitalWrite(a_IC2a, LOW); // LSB
 digitalWrite(b_IC2a, LOW); // MSB

 // set up the LCD's number of columns(Spalte) and rows(Zeile):
 lcd.begin(20,4);
 lcd.setCursor(0,0);
 lcd.print("Platine Anschliessen");
 lcd.setCursor(0,1);        
 lcd.print("Taster druecken");
 
 while(digitalRead(Taster)== HIGH);
 {}

 pinMode(Taster, OUTPUT);
 digitalWrite(Taster,LOW);
 delay(4000);
 lcd.clear();
 lcd.print("Taster gedrueckt");

 delay(4000);

}

void loop()
{
    digitalWrite(A_X14, LOW);   // LSB
    digitalWrite(B_X14, LOW);
    digitalWrite(C_X14, LOW);  // MSB
    
    digitalWrite(a_IC2a, LOW); // LSB
    digitalWrite(b_IC2a, LOW); // MSB


    
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

if ((VU_K20 < 102) ||(VU_K20 > 820)&& (error<=3))
                  {
                    error++;
                  lcd.print("Meldung");
                  }
  
      }




        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Soll:5V   IST:");
        float Rech2 = 5*5*V5_K19/1024;
        lcd.print(Rech2);
        lcd.print("V");

          Rech2 = 5*5*V5_K19/1024;
        delay(10000);

      }




    
      //if (digitalRead(b_IC2a) == LOW)
      //    {
      //    digitalWrite(A_X14, HIGH);   // LSB
      //    digitalWrite(B_X14, LOW);
      //    digitalWrite(C_X14, HIGH);  // MSB
      //    
      //    digitalWrite(a_IC2a, LOW); // LSB
      //    digitalWrite(b_IC2a, HIGH); // MSB
      //    delay(5000);
      //    
      //    lcd.clear();
      //    lcd.setCursor(0,0);
      //    lcd.print("A=H,B=L,C=H,a=L,b=H");  
      //    lcd.setCursor(0,1);
      //      lcd.print("AD_0:");
      //      lcd.print(analogRead(ADW));
      //      lcd.setCursor(0, 2);
      //      lcd.print("AD_1:");
      //      lcd.print(analogRead(ADE));
      //      lcd.setCursor(0,3);
      //      lcd.print("AD_2:");
      //      lcd.print(analogRead(ADR));
      //    delay(5000); 
      //    }
      //
      //if (digitalRead(b_IC2a) == HIGH)
      //    {
      //    digitalWrite(A_X14, HIGH);   // LSB
      //    digitalWrite(B_X14, LOW);
      //    digitalWrite(C_X14, HIGH);  // MSB
      //    
      //    digitalWrite(a_IC2a, HIGH); // LSB
      //    digitalWrite(b_IC2a, HIGH); // MSB
      //    delay(5000);
      //    
      //    lcd.clear();
      //    lcd.setCursor(0,0);
      //    lcd.print("A=H,B=L,C=H,a=H,b=H");  
      //    lcd.setCursor(0,1);
      //      lcd.print("AD_0:");
      //      lcd.print(analogRead(ADW));
      //      lcd.setCursor(0, 2);
      //      lcd.print("AD_1:");
      //      lcd.print(analogRead(ADE));
      //      lcd.setCursor(0,3);
      //      lcd.print("AD_2:");
      //      lcd.print(analogRead(ADR));
      //    delay(5000); 
      //    }
      //
      //    if (digitalRead(b_IC2a) == HIGH)
      //    {
      //    digitalWrite(A_X14, HIGH);   // LSB
      //    digitalWrite(B_X14, HIGH);
      //    digitalWrite(C_X14, LOW);  // MSB
      //    
      //    digitalWrite(a_IC2a, LOW); // LSB
      //    digitalWrite(b_IC2a, HIGH); // MSB
      //    delay(5000);
      //    
      //    lcd.clear();
      //    lcd.setCursor(0,0);
      //    lcd.print("A=H,B=H,C=L,a=L,b=H");  
      //    lcd.setCursor(0,1);
      //      lcd.print("AD_0:");
      //      lcd.print(analogRead(ADW));
      //      lcd.setCursor(0, 2);
      //      lcd.print("AD_1:");
      //      lcd.print(analogRead(ADE));
      //      lcd.setCursor(0,3);
      //      lcd.print("AD_2:");
      //      lcd.print(analogRead(ADR));
      //    delay(5000); 
      //    }
      //    if (digitalRead(b_IC2a) == HIGH)
      //    {
      //    digitalWrite(A_X14, HIGH);   // LSB
      //    digitalWrite(B_X14, HIGH);
      //    digitalWrite(C_X14, LOW);  // MSB
      //    
      //    digitalWrite(a_IC2a, HIGH); // LSB
      //    digitalWrite(b_IC2a, HIGH); // MSB
      //    delay(5000);
      //    
      //    lcd.clear();
      //    lcd.setCursor(0,0);
      //    lcd.print("A=H,B=H,C=L,a=H,b=H");  
      //    lcd.setCursor(0,1);
      //      lcd.print("AD_0:");
      //      lcd.print(analogRead(ADW));
      //      lcd.setCursor(0, 2);
      //      lcd.print("AD_1:");
      //      lcd.print(analogRead(ADE));
      //      lcd.setCursor(0,3);
      //      lcd.print("AD_2:");
      //      lcd.print(analogRead(ADR));
      //    delay(5000); 
      //    }

    
   
   


 
// function error()

//   if()
//   {
//     lcd.print("");
//   }




