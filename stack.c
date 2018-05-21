#include <stdio.h>
#include <stdlib.h>
 

typedef struct stack {
    int value;             
    struct stack * next;   
} node_t, stack_t;
 

int is_empty(stack_t ** top) {
    return *top == NULL;
}
 

void push(stack_t ** top, int value) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->value = value;
    node->next = NULL;

    if(!is_empty(top))
        node->next = *top;
    (*top) = node;
}

void pop(stack_t **top) {
    node_t *node;
 

    if(!is_empty(top)) {
        node = *top;
        *top = (*top)->next;
        free(node);
        node = NULL;
    }
}
 
int top(stack_t **top) {
    if(!is_empty(top)) 
        return (*top)->value;
    else
        return 0;
}
 

void clear(stack_t **top) {
    while(!is_empty(top))
        pop(top);
}
 
 
void print(stack_t **top) {
    node_t *node;
    for(node = *top; node != NULL; node = node->next)
        printf("%d -> ", node->value);
    printf("\b\b\b   \n");
}
 
int main()
{
    int i;
    stack_t *s1 = NULL;
    stack_t *s2 = NULL;
 
    for(i = 0; i < 10; ++i) 
        push(&s1, i);
 
    printf("Содержимое первого стека: \n");
    print (&s1);
 
    printf("5 элементов перекладываем во второй стек\n");
    for(i = 0; i < 5; ++i) {
        push(&s2, top(&s1));
        pop(&s1);
    }
    printf("\nСодержимое первого стека: \n");
    print (&s1);
    printf("\nСодержимое второго стека: \n");
    print (&s2);
    clear(&s1);
    clear(&s2);
    return 0;
}