

#include <Arduino.h>
#include <globalVar.h>
//#include <functions.h>



void func_spgmess()
{
       delay(500);  
      
       digitalWrite(A_X14, HIGH); // LSB
       digitalWrite(B_X14, LOW);
       digitalWrite(C_X14, LOW);  // MSB
      
       digitalWrite(a_IC2a, LOW); // LSB
       digitalWrite(b_IC2a, LOW); // MSB
       delay(200);

       VU_K20 = (analogRead(AD_0));
} 


void func_spgmess_12V_K19()
{

}               


void func_spgmess_5V_K19()
{
    digitalWrite(A_X14, HIGH);   // LSB
    digitalWrite(B_X14, HIGH);
    digitalWrite(C_X14, HIGH);  // MSB
    
    digitalWrite(a_IC2a, LOW); // LSB
    digitalWrite(b_IC2a, LOW); // MSB
    delay(200);

   V5_K19 = (analogRead(AD_0));
}
                
                
            
               
