#include "main.h"

/** PRINT UNSIGNED NUMBER ***/
/**
 * print_unsigned - Prints an unsigned number.
 * @types: list a of arguments.
 * @buffer: buffer array to handle print.
 * @flags:  calculates active flags.
 * @width: get width.
 * @precision: precision specification.
 * @size: size specifier.
 * great work, clear and straight forward
 * Return: number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = (num % 10) + '0';
		num /= 10;
	}

	a++;

	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/** PRINT UNSIGNED NUMBER IN OCTAL  **/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: list a of arguments.
 * @buffer: buffer array to handle print.
 * @flags:  calculates active flags.
 * @width: get width.
 * @precision: precision specification.
 * @size: size specifier.
 * Return: number of chars printed.
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[a--] = '0';

	a++;

	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/** PRINT UNSIGNED NUMBER IN HEXADECIMAL ****/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: list a of arguments.
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags.
 * @width: get width.
 * @precision: precision specification.
 * @size: size specifier.
 * Return: Number of chars printed.
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/** PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL ****/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: list a of arguments.
 * @buffer: buffer array to handle print.
 * @flags:  calculates active flags.
 * @width: get width.
 * @precision: precision specification.
 * @size: size specifier.
 * Return: number of chars printed.
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**** PRINT HEXX NUM IN LOWER OR UPPER *****/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: list a of arguments.
 * @map_to: array of values to map the number to
 * @buffer: buffer array to handle print.
 * @flags:  Calculates active flags
 * @flag_ch: calculates active flags.
 * @width: get width.
 * @precision: precision specification.
 * @size: size specifier.
 * @size: size specification.
 * Return: number of chars printed.
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[a--] = flag_ch;
		buffer[a--] = '0';
	}

	a++;

	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}
