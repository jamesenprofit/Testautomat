#include <Arduino.h>
#pragma once

// Digitales Poti PINS Zum Ansprechen
extern byte CS, SCK_, SDA_;

// Variablen 
int V5_K19 ;          int V12_K19;         int Vneg12_K19;
int V12_K20;          int Vneg12_K20;         
int Vadj_K20;         int Vadj_min;        int Vadj_max;

int VU_K20;
int posSpg;             int negSpg;         int Spg;
int Ineg12;             int Iadj;           int I; 

int error;

//----------MUX-4051-----------    
extern byte A_X14, B_X14, C_X14;

//-------MUX-4052--------
extern byte a_IC2a, b_IC2a;

 //-----------------LCD--------------------
extern byte D4, D5, D6;
extern byte D7 , RS, EN;

//----------------Auslese Pins Am Arduino----------------
extern byte AD_0;
extern byte AD_1;
extern byte AD_2;
extern byte AD_5;

//-------------------------------PINS-----------------------------------------
//A0= + spg; A1= - spg; A2= Strom ;
//int opto ; int AUS;
extern int Taster;            
extern int LED;               




