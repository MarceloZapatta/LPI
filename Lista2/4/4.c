#include <stdio.h>

int main() {
    int qtdClientes, z = 0, y = 0, pot = 0;
    char cpf[11], string[200], *p;
    float valor;

    printf("Entre com a quantidade de clientes:\n");
    scanf("%i", &qtdClientes);

    printf("Entre com a string:\n");
    scanf("%s", p);

    for(int i = 0; i < qtdClientes; i++)
    {
        for(int j = 0; j < strlen(*p); j++)
        {
            if(*(p + j) >= 48 && *(p + j) <= 57) {
                if(z <= 11) {
                    *(cpf + z) = *(p + j);
                }
            }
            if(*(p + j) >= 48 && *(p + j) <= 57 && z <= 11) {
            } else if(*(p + j) >= 48 && *(p + j) <= 57) {
                if(y == 0) {
                    if(*(p + j) != '.') {
                        
                    }
                }
            }
        }
        
    }
}