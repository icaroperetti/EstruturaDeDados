#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct sElemento{ 
    struct sElemento *next;
    struct sElemento *prev;
    int dado; 
} Elemento;

typedef struct sPilha{ 
    struct sElemento *head;
    struct sElemento *tail; 
    int size;
} Pilha;

Pilha* criaPilha();
Elemento* criaElemento(int dado);
void push(Pilha* pilha,int dado);
void imprimePilha(Pilha* pilha);
bool isEmpty(Pilha* pilha);
int pop(Pilha* pilha);
void destroiPilha(Pilha* pilha);
Elemento* stacktop(Pilha* pilha);

int main(){
    Pilha* pilha = criaPilha();
    Elemento* top;
    push(pilha,10);
    push(pilha,20);
    push(pilha,30);
    push(pilha,40);
    push(pilha,50);
    push(pilha,60);
    push(pilha,70);
    top = stacktop(pilha);
    printf("\nTop:%i\n",top->dado);
    imprimePilha(pilha);

    pop(pilha);
    printf("Size:%i\n",pilha->size);
    
    imprimePilha(pilha);
    
    destroiPilha(pilha);
    imprimePilha(pilha);
}

void destroiPilha(Pilha* pilha){
    printf("DESTRUINDO\n");
    while(pilha->size != 0){
        pop(pilha);
        printf("Size:%i\n",pilha->size);
    }
    free(pilha);
    pilha->size--;
}

Elemento* stacktop(Pilha* pilha){
    Elemento* top;
    top = pilha->head;
    return top;
}

Pilha* criaPilha(){
    Pilha* pilha;
    pilha = (Pilha*)malloc(sizeof(Pilha));
    if(pilha == NULL){
        printf("Memoria nao alocada");
    }
    pilha->head = NULL;
    pilha->tail = NULL;
    pilha->size = 0;
    return pilha;
}

Elemento* criaElemento(int dado){
    Elemento* elemento;
    elemento = (Elemento*)malloc(sizeof(Elemento));
    elemento->next = NULL;
    elemento->prev = NULL;
    elemento->dado = dado;
    return elemento;
}

void push(Pilha* pilha,int dado){
    Elemento *novo = criaElemento(dado);
    novo->next = pilha->head;
    pilha->head = novo;
    printf("Inserido:%i\n",novo->dado);
    pilha->size++;
}

int pop(Pilha *pilha) {
    Elemento* remove;
    remove = stacktop(pilha);
    if(pilha->size == 0){
        printf("Fila esta vazia");
    }else{
        pilha->head = remove->next;
        remove->next = NULL;
    }
    free(remove);
    pilha->size--;   
}


void imprimePilha(Pilha* pilha){
    Elemento *aux = pilha->head;
    if (pilha->size < 0){
        printf("A pilha esta vazia!");
    }
    else{
        printf("Pilha: ");
        while (aux != NULL){
            printf("%i ", aux->dado);
            aux = aux->next;
        }
        printf("\n");
    }
}

bool isEmpty(Pilha* pilha){
    if(pilha->head == NULL){
        return true;
    }else{
        return false;
    }
}
