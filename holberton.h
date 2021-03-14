#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

typedef struct specPrint
{
	char *spec;
	int (*specFunc)(va_list, int);
} spec_t;

int printPerc(va_list perc, int count);
int printc(va_list c, int count);
int prints(va_list s, int count);
int printd(va_list d, int count);
int printi(va_list i, int count);
int printb(va_list b, int count);
int printu(va_list u, int count);
int printo(va_list o, int count);
int printx(va_list x, int count);
int printX(va_list X, int count);
int printS(va_list S, int count);
int printp(va_list p, int count);
int printr(va_list r, int count);
int _putchar(char c);
int print_number(int n, int count);
int _puts(char *str, int count);
int _printf(const char *format, ...);

#endif
