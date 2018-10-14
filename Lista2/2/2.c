#include <stdio.h>

int main()
{
    
    return 0;
}

char * Cripto(char * str1, char * str2) {
    
    for(int i = 0; i < 9; i++)
    {
        // Pesquisa na segunda string o caracter
        for(int j = 0; j < 9; j++)
        {
            if(*(str1 + i) == *(str2 + j)) {
                
            }
        }
        
    }
    
    return *str2;
}