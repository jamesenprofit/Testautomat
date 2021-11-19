#include <Arduino.h>
#include <globalVar.h>
#include <func_error.h>

void func_error()

{
    if (error <= 3)

    {
      error++;  
    }
    else
    {
        // hier kommt ein brake oder so hin
    }
}

