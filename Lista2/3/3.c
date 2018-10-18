#include <stdio.h>
#include <string.h>

int main() {
    int posicao, controle = 0;
    char str1[20];
    char str2[20];

    printf("Indique a primeira string(ate 10 caracteres):\n");
    scanf("%s", str1);

    while(controle == 0) {
        printf("Indique a segunda string(ate 10 caracteres):\n");
        scanf("%s", str2);

        printf("Indique a posicao para trocar:\n");
        scanf("%i", &posicao);
    }

    str_replace(str1, str2, posicao);

    printf("A nova string: \"%s\"", str1);

    return 0;
}

void str_replace(char * str1, char * str2, int posicao) {
    
    int i = 0, j = posicao - 1;
    
    while(*(str2 + i) != '\0'){
        *(str1 + j) = *(str2 + i);
        i++;
        j++;
    }
}