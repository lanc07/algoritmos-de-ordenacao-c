#include <stdio.h>
#include <string.h>

// exibir o vetor
void exibe(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

// Bubble Sort decrescente
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Função para encontrar a posição do maior valor
int posicaoM(int arr[], int n) {
    int maior = arr[0];
    int pos = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > maior) {
            maior = arr[i];
            pos = i;
        }
    }
    return pos + 1;
}

int main() {
    int pontos[12] = {10, 22, 9, 15, 20, 30, 25, 18, 12, 5, 8, 14};
    int n = 12;
    int copia[12];

    printf("Lista original: ");
    exibe(pontos, n);

    // Bubble Sort
    memcpy(copia, pontos, sizeof(pontos));
    bubbleSort(copia, n);
    printf("\nBubble Sort (decrescente): ");
    exibe(copia, n);
    printf("Maior pontuador ficou na posicao: %d\n");
    printf("Lista original: ");
    for (int i = 0; i < 12; i++) {
        printf("%d ", pontos[i]);
    }
    printf("\n");

    printf("Maior pontuador ficou na posicao: %d\n", posicaoM(pontos, 12));

    return 0;
}