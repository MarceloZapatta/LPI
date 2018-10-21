#include <stdio.h>
#include <string.h>

int Cripto(char * str1, char * str2);

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

/**
 * Função para criptografar/descripritografar um número
 * @param char * str 1 Recebe a string a ser (des)criptografa
 * @param char * str 2 String onde sera salvo a nova string.
 */
int Cripto(char * str1, char * str2) {
    
    // Strings de controle para criptografia
    char controle1[19] = "afhsu]i@lD5,23&eyPc";
    char controle2[19] = "gFp04#:w^ld9!/*?.;z";
    int i, j;

    // Percorre a str1 entrada
    for(i = 0; i < 9; i++) {

        // Percorre as cadeias de controle
        for(j = 0; j < 19; j++) {

            // Se o caracter estiver presente na primeira
            // cadadeia de controle
            if(*(str1 + i) == *(controle1 + j)) {
                *(str2 + i) = *(controle2 + j);
                break;
            } else if(*(str1 + i) == *(controle2 + j)) {

                // Presente na segunda cadeia
                *(str2 + i) = *(controle1 + j);
                break;
            } else {

                // permanece o mesmo
                *(str2 + i) = *(str1 + i);
            }
        }
    }

    return 0;
}