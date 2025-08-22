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
    printf("Maior pontuador ficou na posicao: 1\n");

}