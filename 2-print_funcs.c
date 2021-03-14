#include "holberton.h"

int printb(va_list b, int count)
{
	(void)b;

	printf("printb");
	print_number(count, count);
	return (count);
}
int printu(va_list u, int count)
{
	(void)u;
	printf("printb");
        print_number(count, count);
	printf("%d\n", count);
	return (count);
}
int printo(va_list o, int count)
{
	(void)o;
        (void)count;
	printf("printo");
return (count);
}
int printx(va_list x, int count)
{
	(void)x;
        (void)count;
	printf("printx");
	return (count);
}
int printX(va_list X, int count)
{
	(void)X;
        (void)count;
	printf("printX");
	return (count);
}
int printS(va_list S, int count)
{
	(void)S;
        (void)count;
	printf("printS");
return (count);
}
int printp(va_list p, int count)
{
	(void)p;
        (void)count;
	printf("printp");
return (count);
}
int printr(va_list r, int count)
{
	(void)r;
        (void)count;
	printf("printr");
	return (count);
}

