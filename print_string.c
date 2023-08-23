#include "main.h"
#include <unistd.h>
#include <stdarg.h>

int print_string(va_list args) {
	int i,  cf = 0;
	char *str = va_arg(args, char *);

	if (!str) str = "(null)";

	if (str[0] == '\0') return (-1);

	for (i = 0; str[i] != '\0'; i++)
		cf += _putchar(str[i]);

	return (cf);
}

