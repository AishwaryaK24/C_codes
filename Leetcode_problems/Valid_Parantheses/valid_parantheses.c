/*
 * Created on Fri Feb 04 2022
 *
 * Copyright (c) 2022 Aishwarya Kulkarni
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top = -1;
char *stack = NULL;
static char pop()
{
    char c;
    c = stack[top];
    top--;
    return c;
}

static void push(char value)
{
    top++;
    stack[top] = value;
    //printf("\nPushed bracket %c\n", stack[top]);
}

int isValid(char *s)
{
    uint8_t i = 0;
    char dummy;
    char required_bracket;
    size_t string_length;
    stack = (char *)malloc(string_length * (sizeof(char)));

    //printf("length%lu", strlen(s));
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            push(s[i]);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            dummy = pop();
            //printf("Dummy %c",dummy);
            if (dummy == '(')
            {
                required_bracket = ')';
                //printf("required_bracket %c",required_bracket);
            }
            else if (dummy == '[')
            {
                required_bracket = ']';
                //printf("required_bracket %c",required_bracket);
            }
            else if (dummy == '{')
            {
                required_bracket = '}';
                //printf("required_bracket %c",required_bracket);
            }
            if (s[i] == required_bracket)
            {
                //printf("\ns[%d] %c and required %c are same", i, s[i], required_bracket);
                continue;
            }
            else
            {
                break;
            }
        }
    }
    if (i == strlen(s) && top < 0)
    {
        return 1;
    }

    return 0;
}

int main(void)
{
    int result = 0;
    //TODO: Add interactive string input"
    static char *s = "{{{{{{{{{{()()())()()}}}}}}}}}}{[][][]}";
    result = isValid(s);
    if(result)
    {
        printf("\nThe expression is valid\n");
        return 0;
    }
    printf("\nThe expression is invalid\n");
    return 0;
}