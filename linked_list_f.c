#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void show_menu() {
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("Insire a opção desejada:\n");
    printf("[0] Exit\n");
    printf("[1] Start linked list\n");
    printf("[2] Show linked list\n");
    printf("[3] Show ammount of nodes\n");
    printf("[4] Restart linked list\n");
    printf("[5] Insert node in the list\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

void start_linked_list(Descriptor *p) {
    int n = -1;
    while (n < 0) {
        printf("Set the size of the linked list: ");
        scanf("%d", &n);
        if (n < 0)
            printf("Invalid size!\n");
    }
    p->size = n;

    if (n == 0) {
        p->start = NULL;
        return;
    }
    else {
        p->start = new_node(1);
        link_node(p->start, n);
    }
}

Node *new_node(int data) {
    Node *p = (Node *) malloc(sizeof(Node));
    p->data = data;
    p->link = NULL;
    return p;
}

void link_node(Node *p, int size) {
    Node *aux;
    for (int i = 2; i <= size; i++) {
        aux = new_node(i);
        while (p->link != NULL) {
            p = p->link;
        }
        p->link = aux;
    }
}

void show_linked_list(Descriptor *p) {
    Node *aux = p->start;
    printf("Linked list: ");
    printf("[%d|%p]->", p->size, &p->start);
    if (p != NULL) {
        while (aux != NULL) {
            printf("[%d|%p]->", aux->data, &aux->link);
            aux = aux->link;
        }
    }
    printf("NULL\n");
}

int restart(Descriptor *p) { // must implement
    Node *aux = p->start;

    while (p->start != NULL) {
        p->start = aux->link;
        free(aux);
        aux = p->start;
    }

    if (p->start == NULL)
        return 1;
    else
        return 0;
}


int insert(Descriptor *p, Node *new, int pos) {
    Node *aux = p->start;

    while (aux->data < pos - 1) {
        printf("%d\n", aux->data);
        aux = aux->link;
    }

    new->link = aux->link;
    aux->link = new;

    if (new->data != pos)
        return 0;

    while (new->link != NULL) {
        new = new->link;
        new->data++;
    }

    return 1;
}
