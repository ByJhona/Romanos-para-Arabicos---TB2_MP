#include "romToArab.h"

int romanoToarabico(char string[]){
    int arab = 0;
    int cont = 1;
    
    // limita a quantidade de caracteres do vetor de char
    if(tamanhoString(string) > 30){
        return -1;
    }
    
    for (int i = 0; i < tamanhoString(string); i++){
        
        char s1 = string[i];
        char s2 = string[i + 1];
        
        if (i  < tamanhoString(string)){

            // Verifica se nao se repetem mais de 3 vezes
            if(cont < 4){
                if(s1 == s2){
                    cont++;
                }else{
                    cont = 1;
                }
            }else{
                return -1;
            }
            
            // Verifica se a string possui todos os caracteres validos
            if(valor(s1) == -1) return -1;

            if(s1 == 'L'){
                if(s2 == 'C' || s2 == 'D' || s2 == 'M'){
                    return -1;
                }
            }
            if(s1 == 'D'){
                if(s2 == 'D' || s2 == 'M'){
                    return -1;
                }
            }

            if(s1 == 'V'){
                if(s2 != 'I' && s2 != '\0'){
                    return -1;
                }
            }
            // Verifica de acordo com a tabela e decide qual operação realizar
            if(s1 == 'I'){
                if(s2 == 'V'){
                    arab += valor(s2) - valor(s1);
                    i++;
                }else if(s2 == 'X'){
                    arab += valor(s2) - valor(s1);
                    i++;
                }else{
                    arab += valor(s1);
                }
            }else if(s1 == 'X'){
                if(s2 == 'L'){
                    arab += valor(s2) - valor(s1);
                    i++;
                }else if(s2 == 'C'){
                    arab += valor(s2) - valor(s1);
                    i++;
                }else{
                    arab += valor(s1);
                }
            }else if(s1 == 'C'){
                if(s2 == 'D'){
                    arab += valor(s2) - valor(s1);
                    i++;
                }else if(s2 == 'M'){
                    
                    arab += valor(s2) - valor(s1);
                    i++;
                }else{
                    arab += valor(s1);
                }
            }else{
                arab += valor(s1);
            }
        }
    }
    return verificaArabico(arab);
}

// Verifica se o numero arabico é menor ou igual a 3000
int verificaArabico(int arab){
    
    return arab > 3000 ? -1 : arab;
}


int valor(char r){
    
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
 
    return -1;
}

// Verifica a quantidade de caracteres dentro da string
int tamanhoString(char string[]){
    int cont = 0;
    
    for(int i = 0; ; i++){
        
        if(string[i] == '\0'){ 
            break;
        }
        
        cont++;
    }
    return cont;
}

