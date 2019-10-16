#include <stdlib.h>
#include <stdio.h>

typedef struct _node *Node;

struct _node {
    int val;
    Node next;
};

Node newNode(int val)
{
    Node ptn = (Node) malloc(sizeof(Node));
    ptn->val = val;
    ptn->next = NULL;
}

void printNode(Node node)
{
    if (node != NULL) {
        printf("%d", node->val);
    } else {
        printf("null");
    }
}

void push(Node stack, int val)
{
    Node node = newNode(val);
    node->next = stack;
    stack = node;
}

Node pop(Node stack) {
    Node ptn;
    
    ptn = stack;
    stack = stack->next;
    
    return ptn;
}

Node createStack(int *values, int n)
{
    int i;
    Node stack = NULL;
    for (i=0; i<n; i++) {
        push(stack, values[i]);
    }
    return stack;
}

Node findNode(Node stack, int value)
{
    Node ptn = stack;
    while (ptn->val != value && ptn != NULL) {
        ptn = ptn->next;
    }
    return ptn;
}

Node emptyStack(Node stack) {
    Node ptn;
    
    ptn = pop(stack);
    while (ptn != NULL) {
        free(ptn);
        ptn = pop(stack);
    }
}

void printStack(Node list)
{
    Node ptn = list;
    if (ptn == NULL) {
        printf("empty\n");
        return;
    }
    while (ptn->next != NULL) {
        printNode(ptn);
        printf(" -> ");
        ptn = ptn->next;
    }
    printNode(ptn);
    printf("\n");
}

int main()
{

    Node stack = createStack((int[]){1, 2, 3, 4, 5}, 5);
    Node ptn;

    printf("Pilha inicial:\n");
    printStack(stack);

    printf("\nBusca do elemento 3:\n");
    printNode(findNode(stack, 3));

    printf("\n\nBusca do elemento 8:\n");
    printNode(findNode(stack, 8));

    printf("\n\nRemocao do topo:\n");
    ptn = pop(stack);
    printNode(ptn);
    
    printf("\n\nPilha:\n");
    printStack(stack);

    printf("\nPilha esvaziada:\n");
    emptyStack(stack);
    printStack(stack);

    return 0;
}