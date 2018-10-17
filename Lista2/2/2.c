#include <stdio.h>

int main()
{
    char texto1[9], texto2[9], texto3[9];
    printf( "Informe um texto de até 8 caracteres:" ) ;
    scanf( "%[^\n]", texto1 );
    Cripto(texto1, texto2);
    Cripto(texto2, texto3);
    printf("O texto criptografado eh: \n%s\n e descriptografado eh: \n%s\n", texto2, texto3);

    return 0;
}

void Cripto(char * str1, char * str2) {
    char cadeia[52] = 'abcdefghijkl...';

    for(int i = 0; i < 52; i++) {
        for(int j = 0; j < 9; j++)
        {
            if(*(str1 + j) == *(cadeia + i)) {
                
            }
        }
    }
}