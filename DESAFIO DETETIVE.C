#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Sala {
    char nome[50];
    struct Sala *esq;
    struct Sala *dir;
} Sala;

Sala* criarSala(char nome[]) {
    Sala* nova = (Sala*) malloc(sizeof(Sala));
    strcpy(nova->nome, nome);
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
}

void explorarSalas(Sala* atual) {
    char op;

    while (1) {
        printf("\nVocê está na sala: %s\n", atual->nome);
        printf("(e) Esquerda | (d) Direita | (s) Sair\n");
        printf("Escolha: ");
        scanf(" %c", &op);

        if (op == 's') {
            printf("\nEncerrando exploração...\n");
            break;
        } 
        else if (op == 'e') {
            if (atual->esq != NULL) {
                atual = atual->esq;
            } else {
                printf("Não há sala à esquerda!\n");
            }
        }
        else if (op == 'd') {
            if (atual->dir != NULL) {
                atual = atual->dir;
            } else {
                printf("Não há sala à direita!\n");
            }
        }
        else {
            printf("Opção inválida!\n");
        }
    }
}

int main() {
    Sala *hall = criarSala("Hall de Entrada");
    Sala *biblioteca = criarSala("Biblioteca");
    Sala *cozinha = criarSala("Cozinha");
    Sala *sotao = criarSala("Sótão");
    Sala *porao = criarSala("Porão");

    hall->esq = biblioteca;
    hall->dir = cozinha;

    biblioteca->esq = sotao;
    cozinha->dir = porao;

    explorarSalas(hall);

    return 0;
}
