

#include <Arduino.h>
#include <globalVar.h>
#include <func_spgmess.h>



void func_spgmess()
{
      
} 


void func_spgmess_V12_K19()
{
       delay(100);
       digitalWrite(A_X14, LOW);   // LSB
       digitalWrite(B_X14, HIGH);
       digitalWrite(C_X14, HIGH);  // MSB
    
       digitalWrite(a_IC2a, LOW);  // LSB
       digitalWrite(b_IC2a, LOW);  // MSB
       delay(200);

       //V12_K19 = (analogRead(AD_0));
}               

void func_spgmess_V12_K20()
{
       digitalWrite(A_X14, LOW);   // LSB
       digitalWrite(B_X14, LOW);
       digitalWrite(C_X14, HIGH);  // MSB
      
       digitalWrite(a_IC2a, LOW); // LSB
       digitalWrite(b_IC2a, LOW); // MSB
       delay(200);

       //V12_K20 = (analogRead(AD_0));

}


void func_spgmess_V5_K19()
{
       delay(500); 
       digitalWrite(A_X14, HIGH);  // LSB
       digitalWrite(B_X14, HIGH);
       digitalWrite(C_X14, HIGH);  // MSB
    
       digitalWrite(a_IC2a, LOW);  // LSB
       digitalWrite(b_IC2a, LOW);  // MSB
       delay(200);

      //V5_K19 = (analogRead(AD_0));
}

void func_spgmess_Vneg12_K19()
{
       digitalWrite(A_X14, HIGH);  // LSB
       digitalWrite(B_X14, LOW);
       digitalWrite(C_X14, HIGH);  // MSB
    
       digitalWrite(a_IC2a, LOW);  // LSB
       digitalWrite(b_IC2a, LOW);  // MSB
       delay(200);

       //Vneg12_K19 = (analogRead(AD_1));
}

void func_spgmess_Vneg12_K20()
{
       digitalWrite(A_X14, HIGH); // LSB
       digitalWrite(B_X14, HIGH);
       digitalWrite(C_X14, LOW);  // MSB
      
       digitalWrite(a_IC2a, LOW); // LSB
       digitalWrite(b_IC2a, LOW); // MSB
       
       //Vneg12_K20 = (analogRead(AD_1));
       delay(200);
}

void func_spgmess_Vadj_K20()
{
       delay(300); 

       digitalWrite(A_X14, LOW);   // LSB
       digitalWrite(B_X14, HIGH);
       digitalWrite(C_X14, LOW);  // MSB
      
       digitalWrite(a_IC2a, LOW); // LSB
       digitalWrite(b_IC2a, LOW); // MSB

       delay(200); 
            
       //Vadj_K20 = (analogRead(AD_0));
}
                
void func_spgmess_VU_K20()
{
       delay(200);
       digitalWrite(A_X14, HIGH);   // LSB
       digitalWrite(B_X14, LOW);
       digitalWrite(C_X14, LOW);  // MSB
      
       digitalWrite(a_IC2a, LOW); // LSB
       digitalWrite(b_IC2a, LOW); // MSB
       delay(200);
              
       //VU_K20 = (analogRead(AD_0));
}                
            
               
