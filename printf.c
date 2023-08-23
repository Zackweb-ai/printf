#include "main.h"
#include <unistd.h>
int _printf(const char *format, ...) {
	int c = 0, i = 0, cf; va_list args;
	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1])) return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2]) return (-1);
	while (format[i]) {
		cf = 0;
		if (format[i] == '%') {
			if (!format[i + 1] || (format[i + 1] == ' ' && !format[i + 2])) {
				c = -1;
				break;
			}
			cf += functionName(format[i + 1], args);
			if (cf == 0) c += _putchar(}
