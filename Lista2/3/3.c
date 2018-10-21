#include <stdio.h>
#include <string.h>

void str_replace(char * str1, char * str2, int posicao);

int main() {
    int posicao = 0, stop = 0;
    char str1[20];
    char str2[20];

    while (!stop) {
        printf("Indique a primeira string(ate 20 caracteres):\n");
        scanf("%s", str1);

        printf("Indique a segunda string(ate 20 caracteres):\n");
        scanf("%s", str2);

        printf("Indique a posicao para trocar:\n");
        scanf("%i", &posicao);
        if(posicao < 0) {
            return 0;
        }

        str_replace(str1, str2, posicao);

        printf("A nova string: \"%s\"\n", str1);
    }
}

void str_replace(char * str1, char * str2, int posicao) {
    
    int i = 0, j = posicao - 1;
    
    while(*(str2 + i) != '\0'){
        *(str1 + j) = *(str2 + i);
        i++;
        j++;
    }
}