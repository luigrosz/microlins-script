#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lead_struct {
    char name[40];
    char phone[20];
};

struct struct_lista_enc {
    struct lead_struct lead;
    struct struct_lista_enc *prox;
};

typedef struct lead_struct est_struct;
typedef struct struct_lista_enc node;

void insereLista(node **lista, char *name, char *phone){
    node *novo = (node *)malloc(sizeof(node));
    strcpy(novo->lead.name, name);
    strcpy(novo->lead.phone, phone);

    novo->prox = (*lista);
    (*lista) = novo;
}

int main() {
    char linha_atual[10000];
    char *token;
    char *ptr;
    int base = 10;
    clock_t t;

    node *lista;
    lista = NULL;

    FILE *arquivo = fopen("leads-eja-ypy.csv", "r");
    if (arquivo == NULL) {
        printf("erro lendo arquivo");
        return 1;
    }

    fgets(linha_atual, sizeof(linha_atual), arquivo);  // pula primeira linha
    while (fgets(linha_atual, sizeof(linha_atual), arquivo)) {
        char name[40];
        char phone[20];

        token = strtok(linha_atual, ",");

        token = strtok(NULL, ",");
        strcpy(name,token);

        token = strtok(NULL, ",");
        strcpy(phone, token);

        insereLista(&lista, name, phone);
    }

    fclose(arquivo);
    node *aux;

    printf("Leads\n\n");

    for (node *i = lista; i != NULL; i = i->prox) {
        printf("%s - %s\n", i->lead.name, i->lead.phone);
    }

    return 0;
}

