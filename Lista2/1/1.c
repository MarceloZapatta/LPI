#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // String para armazenar os dígitos ISBN
    // 11 caracteres por que conta o '-'
    char isbn[11];
    
    while (strcmp(isbn, "FIM") != 0) {

        scanf("%s", &isbn);
        
        // Verifica se o usuário digitou FIM
        if(strcmp(isbn, "FIM") == 0) {
            return 0;
        }

        // Acumuladores
        int s1[10] = {0}, s2 = 0;
        int k = 0, j = 0, resto;
        
        for(int i = 0; i < 11; i++) {
            if(i == 0) {
                *s1 = *(isbn + i) - '0';
                k++;
            } else if(i != 9 && i != 10) {
                *(s1 + k) += *(s1 + (k - 1)) + (*(isbn + i) - '0');
                k++;
            } else if(i == 10) {
                if(*(isbn + i) == 'X') {
                    *(s1 + k) += (*(s1 + (k - 1)) + 10);
                } else {
                    *(s1 + k) += *(s1 + (k - 1)) + (*(isbn + i) - '0');
                }
            }
        }

        for(int i = 0; i < 10; i++)
        {
            s2 += *(s1 + i);
        }

        resto = s2 % 11;

        if(resto == 0) {
            printf("ISBN %s e' va'lido\n", isbn);
        } else {
            printf("ISBN inva'lido: %i\n", resto);
        }
        
    }
}