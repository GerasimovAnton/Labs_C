#include "my_stack.h"

#define STACK_UNDERFLOW -101

void printStack(stack *s);

int main()
{
    stack *from = newStack(_DECIMAL_);
    stack *to = newStack(_DECIMAL_);

    v_type val;

    for (size_t i = 0; i < 32; i++)
    {
        val.decimal = i;
        stack_push(from,val);
    }

    stack_copy(to,from,0);

    printf("Size of 1st Stack = %i\n",to->size);
    printf("\nSize of 2nd Stack= %i\n",from->size);

    printStack(from);
    printf("\n");
    printStack(to);

    return 0;
}

void printStack(stack *s)
{
    printf("PRINT = [");

    for (size_t i = 0; i < s->size; i++)
    switch (s->type)
    {
    case _DECIMAL_:
        printf(" %ld ",(*(s->element + i)).decimal);
        break;
    case _REAL_:
        printf(" %lf ",(*(s->element + i)).real);
        break;
    case _STRING_:
        printf(" %s ",(*(s->element + i)).string);
        break;    
    }

    printf("]");
}

void stack_push(stack * s,v_type data)
{
    int memSize = 0;
    switch (s->type)
    {
    case _DECIMAL_:
        memSize = sizeof(uint64_t);
        break;
    case _REAL_:
        memSize = sizeof(double);
        break;
    case _STRING_:
        memSize = sizeof(char*);
        break;    
    }

    if(sizeof(*(s->element)) != memSize) return;

    s->size ++;

    if(s->element != NULL)
        s->element = realloc(s->element,s->size*(memSize));
    else
        s->element = malloc(memSize);

    *(s->element + s->size - 1) = data;   
}

v_type stack_pop(stack *s)
{
    if(s->size == 0) exit(STACK_UNDERFLOW);

    s->size--;
    v_type el = *(s->element + s->size);
    
    int memSize = 0;
    switch (s->type)
    {
    case _DECIMAL_:
        memSize = sizeof(uint64_t);
        break;
    case _REAL_:
        memSize = sizeof(double);
        break;
    case _STRING_:
        memSize = sizeof(char*);
        break;    
    }

    s->element = realloc(s->element,s->size*(memSize));
    if(s->size == 0) free(s->element);

    return el;
}

v_type stack_top(stack *s)
{
    return *(s->element + s->size - 1);
}

stack *newStack(stack_type T)
{
    stack *s = (stack*)malloc(sizeof(stack));
    s->size = 0;
    s->type = T;

    s->element = NULL;
    return s;
}

v_type stack_get(stack* s,int i)
{
    if(s->size == 0 || i > s->size || i < 0) exit(-101);
    return *(s->element + i);
}

void deleteStack(stack* s)
{
    while(s->size != 0)
    stack_pop(s); 
    free(s);
}

void stack_copy(stack* to,stack* from,int startIndx)
{
    if(startIndx > from->size || to->type != from->type) return;
    for (size_t i = startIndx; i < from->size; i++)
    {
        stack_push(to,stack_get(from,i));
    }
}