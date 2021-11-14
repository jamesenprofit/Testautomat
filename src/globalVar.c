#include <Arduino.h>
#include <globalVar.h>



byte CS = 13 , SCK_ = 5, SDA_ = 4;

//-4051-------MUX--------4052-------           
byte A_X14 = 10;     byte a_IC2a = 0;      
byte B_X14 = 11;     byte b_IC2a = 1;      
byte C_X14 = 12;         

//-----------------LCD--------------------
byte D4 = 4;    byte D5 = 5;    byte D6 = 6;
byte D7 = 7;    byte RS = 8;    byte EN = 9;


//-------------------------------PINS-----------------------------------------
//A0= + spg; A1= - spg; A2= Strom ;
int Taster = 2;            
int LED = 3;            

// byte AD_0 = A0;
// byte AD_1 = A1;
// byte AD_2 = A2;
// byte AD_5 = A5;
