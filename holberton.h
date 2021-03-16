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
	char *(*specFunc)(va_list);
} spec_t;

/** Edge case put function for double percent sign input */
char *printPerc(va_list perc);

/** Error case */
char *errorFunc(va_list double_space);

/** Put function, process character input */
char *printc(va_list c);

/** Put function, process string input */
char *prints(va_list s);

/** Put functions (2), process integer input */
char *printint(va_list d);

/** Put function for unsigned int input, unsigned int to binary conversion */
char *printb(va_list b);

/** Put functions (4), process unsigned integer input */
char *printu(va_list u);
char *printo(va_list o);
char *printx(va_list x);
char *printX(va_list X);

/** Put function, process string input, allow for non-printable characters */
char *printS(va_list S);

/** Put function, process pointer input */
char *printp(va_list p);

/** Put function, process string input, in reverse*/
char *printr(va_list r);

/** Standard Library putchar emulator, write character to standard output */
int _putchar(char c);

/** Recursive put function to process integers */
int print_number(int n, int count);

/** Standard Library puts emulator, write string to standard output */
int _puts(char *str, int count);

/** Standard Library printf emulator */
/** Variadic function to print any format data to standard output */
int _printf(const char *format, ...);

/** Recursive put function to process unsigned integers */
int print_un_number(unsigned int n, int count);

/** Select put function based on format specifier, sort through spec_t array */
char *(*scan_array(const char *format))(va_list);

/** Storing digits of an unsigned int in an array */
char *printu_alt(unsigned long int u);

/** Buffer overflow protection function */
char *flowchecky(int *f, char *BUFF);

/** Find the length of a string */
int _strlen(char *s);

/** Duplicate an input string */
char *_strdup(char *str);

/** converts into to hex and reverses string */
char *print_rev(int non);
#endif
