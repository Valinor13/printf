#_Printf

\_Printf is an emulation of the standard library function by a similar name that allows any user to print data of any type.

\_Printf receives any number of variadic arguments, writes them to the standard output, and returns a count of characters printed. The variadic arguments are parsed by user input specifier following a '%' character.

To effectively use \_printf, ensure you have compiled all '.c' files, including your main, and that the header file, 'holberton.h' can be found in the same directory. \_Printf is written in the **'C'** function, compiled with **gcc 4.8.4**.


##Using \_Printf
To use \_printf, follow these steps:

1. Within your terminal, create and enter a '.c' file.
1. Inside a 'C' function, call the \_printf function.
	1. int \_printf(const char \*format, ...);
1. Input a string for the format paramter, denoting places of alternative data types with the "%" delimiter followed by a format specifier.
	1. See man \_printf for a list of format specifies.
1. List the alternative data elements as variadic argument parameters following your string's closing quotation marks.
1. View the written elements in standard output, or interact with the integer return value with more 'C' code functions.


##Usage Example
\_printf("This is a good %dst example, %s", 1, name); /\*\* name is a variable which stores "Betty" \*/

###Contributors:

__@Valinor13__ 
__@angelofgrace__

###Contact
If you want to contact the team you can look us up on the Holberton intranet.
