#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/**
* struct specPrint - correlation between format specifier and puts functions
* @spec: Specifier character input
* @specFunc: puts to standard output, conversions based on specifiers,
*	returns number of characters printed
*
* Description: Template for structures in a spec_t array that checks for
*	valid specifiers and calls the corresponding fuction.
*/

typedef struct specPrint
{
	char *spec;
	int (*specFunc)(va_list, int);
} spec_t;

/** Edge case put function for double percent sign input */
int printPerc(va_list perc, int count);

/** Put function, process character input */
int printc(va_list c, int count);

/** Put function, process string input */
int prints(va_list s, int count);

/** Put functions (2), process integer input */
int printd(va_list d, int count);
int printi(va_list i, int count);

/** Put function for unsigned int input, unsigned int to binary conversion */
int printb(va_list b, int count);

/** Put functions (4), process unsigned integer input */
int printu(va_list u, int count);
int printo(va_list o, int count);
int printx(va_list x, int count);
int printX(va_list X, int count);

/** Put function, process string input, allow for non-printable characters */
int printS(va_list S, int count);

/** Put function, process pointer input */
int printp(va_list p, int count);

/** Put function, process string input, in reverse*/
int printr(va_list r, int count);

/** Standard Library putchar emulator, write character to standard output */
int _putchar(char c);

/** Recursive put function to process integers */
int print_number(int n, int count);

/** Standard Library puts emulator, write string to standard output */
int _puts(char *str, int count);

/** Standard Library printf emulator */
/** Variadic function to print any format data to standard output */
int _printf(const char *format, ...);

#endif
