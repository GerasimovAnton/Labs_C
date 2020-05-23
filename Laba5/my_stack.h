#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

typedef union
{
    uint64_t decimal;
    double real;
    char *string;
} v_type;

typedef enum
{
    _DECIMAL_,
    _REAL_,
    _STRING_
} stack_type;

typedef struct my_stack
{
    int size;
    stack_type type;
    v_type *element;
} stack;


stack *newStack(stack_type T);
void deleteStack(stack*);

v_type stack_pop(stack*);
v_type stack_top(stack*);
v_type stack_get(stack*,int);

void stack_push(stack*,v_type);
void stack_copy(stack*,stack*,int);
