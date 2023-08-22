#include "main.h"

/* Function prototype */

void print_buffer(char buffer[], int *buff_ind);

/**
 * my_printf - Custom printf function
 * @format: The format string.
 * Return: Number of characters printed.
*/

int my_printf(const char *format, ...)
{
	if (format == NULL)
	return (-1);

	int total_printed_chars = 0;
	va_list list;

	va_start(list, format);

	char output_buffer[BUFF_SIZE];
	int buff_ind = 0;

	for (int i = 0; format[i]; i++)
	{
	if (format[i] != '%')
	{
		output_buffer[buff_ind++] = format[i];
		if (buff_ind == BUFF_SIZE)
		{
		print_buffer(output_buffer, &buff_ind);
		}
		total_printed_chars++;
		}
	else
	{
		print_buffer(output_buffer, &buff_ind);
		i++;

		int printed_chars = handle_print(format, &i, list

		, output_buffer, get_flags(format, &i)
		, get_width(format, &i, list)
		, get_precision(format, &i, list), get_size(format, &i));

		if (printed_chars == -1)
		{
			va_end(list)
			return (-1);
		}
		total_printed_chars += printed_chars;
		}
	}

	print_buffer(output_buffer, &buff_ind);
	va_end(list);

	return (total_printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of characters
 * @buff_ind: Index at which to add the next character, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
	write(1, buffer, *buff_ind);
	*buff_ind = 0;
	}
}
