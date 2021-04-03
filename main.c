#include <stdio.h>
#include "romToArab.c"

int main()
{
    char string[31] = "VII";
    
    //scanf("%s", string);
    
    int numArab = romanoToarabico(string);
        
    
    printf("%d", numArab);
    
    
    
    

    return 0;
}