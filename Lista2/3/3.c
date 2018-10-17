#include <stdio.h>
#include <string.h>

int main() {
    int posicao;
    char * str1;
    char * str2;

    scanf("%[s\n]", str1);
    printf("aaa%d\n", strlen(str1));
    return 0;
    scanf("%s", &str2);
    scanf("%i", &posicao);

    return 0;
}

// char strReplace(char * str1, char * str2, int posicao) {
    
//     int i = 0, j = posicao - 1;
    
//     while(*(str2 + i) != '\0'){
//         *(str1 + j) = *(str2 + i);
//         i++;
//         j++;
//     }
    
//     return str1;
// }