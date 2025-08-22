#include <stdio.h>
#include <string.h>

typedef struct {
    long comparacoes;
    long trocas;
} Metricas;
void zera_metricas(Metricas *m) { m->comparacoes = 0; m->trocas = 0; }

void imprime_float(const float *v, int n, const char *titulo) {
    printf("%s [", titulo);
    for (int i = 0; i < n; i++) {
        printf("%.1f%s", v[i], (i < n - 1 ? ", " : ""));
    }
    printf("]\n");
}

void swap_float(float *a, float *b, Metricas *m) {
    float tmp = *a; *a = *b; *b = tmp;
    if (m) m->trocas++;
}
void bubble_sort_float_cresc(float *v, int n, Metricas *m) {
    zera_metricas(m);
    for(int pass = 0; pass < n -1; pass++) {
        int mudou = 0;
        for(int i = 0; i < n - 1 - pass; i++) {
            m->comparacoes++;
            if ( v[i] > v[i+ 1])

                swap_float(&v[i], &v[i + 1], m);
                mudou = 1;
        }
        if (!mudou) break;
    }
}
void insertion_float_cresc(float *v, int n, Metricas *m) {
    zera_metricas(m);
    for (int i = 1; i < n; i++) {
        float chave = v[i];
        int j = i - 1;
        while (j >= 0) {
            m->comparacoes++;
            if (v[j] > chave) { // 
                v[j + 1] = v[j];
                if (m) m->trocas++;
                j--;
            } else {
                break;
            }
        }
        v[j + 1] = chave;
    }
}

void selection_float_cresc(float *v, int n, Metricas *m) {
    zera_metricas(m);
    for (int i = 0; i < n - 1; i++) {
        int idx_max = i;
        for (int j = i + 1; j < n; j++) {
            m->comparacoes++;
            if (v[j] < v[idx_max]) idx_max = j; 
        }
        if (idx_max != i) swap_float(&v[i], &v[idx_max], m);
    }
}



int main(void) {
    int n;
    printf("Quantos valores deseja digitar para que possam ser armazenados? ");
    scanf("%d", &n);

    float alturas[n];

    for(int i = 0; i < n; i++) {
        printf("Digite a altura %d (em cm): ", i + 1);
        scanf("%f", &alturas[i]);
    }
    float a1[n], a2[n], a3[n];
    memcpy(a1, alturas, sizeof(alturas));
    memcpy(a2, alturas, sizeof(alturas));
    memcpy(a3, alturas, sizeof(alturas));

    Metricas mb, mi, ms;

    imprime_float(alturas, n, "\nAlturas (em cm) - (desordenados)");

    bubble_sort_float_cresc(a1, n, &mb);
    imprime_float(a1, n, "\nBubble (em ordem crescente)");
    printf("Bubble -> comparacoes=%ld, trocas=%ld\n", mb.comparacoes, mb.trocas);

    insertion_float_cresc(a2, n, &mi);
    imprime_float(a2, n, "\nInsertion (em ordem crescente)");
    printf("Insertion -> comparacoes=%ld, movimentos=%ld\n", mi.comparacoes, mi.trocas);

    selection_float_cresc(a3, n, &ms);
    imprime_float(a3, n, "\nSelection (em ordem crescente)");
    printf("Selection -> comparacoes=%ld, trocas=%ld\n", ms.comparacoes, ms.trocas);

    return 0;
}