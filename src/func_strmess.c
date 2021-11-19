#include <Arduino.h>
#include <globalVar.h>
#include <func_spgmess.h>

void func_strmess_neg12VBeg()
{
    digitalWrite(A_X14, HIGH);  // LSB
    digitalWrite(B_X14, LOW);
    digitalWrite(C_X14, HIGH);  // MSB
    
    digitalWrite(a_IC2a, HIGH); // LSB
    digitalWrite(b_IC2a, HIGH);  // MSB
    delay(200); 
}

void func_strmess_neg12V()
{
    digitalWrite(A_X14, HIGH);  // LSB
    digitalWrite(B_X14, LOW);
    digitalWrite(C_X14, HIGH);  // MSB
    
    digitalWrite(a_IC2a, LOW); // LSB
    digitalWrite(b_IC2a, HIGH);  // MSB
    delay(200);
}
