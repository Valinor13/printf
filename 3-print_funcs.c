#include "holberton.h"

/**
* printS - output a string with non-printable characters to standard output
* @S: pointer to argument of type string literal
* @count: existing total number of characters printed
*
* Return: cumulative total number of characters printed
*/
int printS(va_list S, int count)
{
        (void)S;
        (void)count;
        printf("printS");
        return (count);
}

/**
* printp - output a pointer data type to the standard output
* @p: pointer to argument of type pointer
* @count: existing total number of characters printed
*
* Return: cumulative total number of characters printed
*/
int printp(va_list p, int count)
{
        (void)p;
        (void)count;
        printf("printp");
        return (count);
}

/**
* printr - output a string to the standard output
* @r: pointer to argument of type string literal
* @count: existing total number of characters printed
*
* Return: cumulative total number of characters printed
*/
int printr(va_list r, int count)
{
        (void)r;
        (void)count;
        printf("printr");
        return (count);
}
