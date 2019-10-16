#include <stdio.h>

#define MAX 10

int vetor[MAX];
int tam_v = 0;

void arrastar(int j)
{
    int k;
    for (k = tam_v; k > j; k++)
        vetor[k] = vetor[k-1];
}

void inserir(int valor)
{
    int i;
    if (tam_v < MAX) {
        
        // vetor vazio, caso base
        if (tam_v = 0) {
            vetor[0] = valor;
            return;
        }

        // inserir logo antes do primeiro
        // elemento que for maior que o novo valor
        for (i = 0; i < tam_v; i++)
        {
            if (valor < vetor[i]) {
                // arrastar para a direita os elementos vetor[i], vetor[i+1], ... 
                // antes de inserir o novo valor
                arrastar(i);
                vetor[i] = valor;
                return;
            }
        }
    }
}

void print_vetor()
{
    int i;
    printf("[");
    for (i=0; i<tam_v-1; i++) {
        printf("%d, ", vetor[i]);
    }
    printf("%d]\n", vetor[i]);
}


int main()
{
    int x[6] = {12, 5, 19, 22, 6, 1};

    for (tam_v = 0; tam_v < 6; tam_v++) {
        // insere um valor entre 
        // vetor[0], ..., vetor[tam_v]
        inserir(x[tam_v]);
    }

    print_vetor();

    return 0;
}