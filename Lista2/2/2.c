#include <stdio.h>
#include <string.h>

int main()
{
    char texto1[9], texto2[9], texto3[9];
    printf( "Informe um texto de até 8 caracteres:\n" ) ;
    scanf( "%[^\n]", texto1 );
    Cripto(texto1, texto2);
    Cripto(texto2, texto3);
    printf("O texto criptografado eh: \n%s\n e descriptografado eh: \n%s\n", texto2, texto3);

    return 0;
}

int Cripto(char * str1, char * str2) {
    char controle1[15] = "Afhs2]s@lD5,23&";
    char controle2[15] = "gFp04#:w^ld9!/*";
    int i, j;

    for(i = 0; i < 9; i++) {
        for(j = 0; j < 15; j++) {
            if(*(str1 + i) == *(controle1 + j)) {
                *(str2 + i) = *(controle2 + j);
                break;
            } else if(*(str1 + i) == *(controle2 + j)) {
                *(str2 + i) = *(controle1 + j);
                break;
            } else {
                *(str2 + i) = *(str1 + i);
            }
        }
    }

    return 0;
}