#include <stdio.h>
#include "romToArab.h"

int main()
{
    char string[31] = "VIII";

    //scanf("%s", string);

    int numArab = romanoToarabico(string);


    printf("%d", numArab);





    return 0;
}
