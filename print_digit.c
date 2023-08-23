#include "main.h"
#include <unistd.h>


int print_digit(va_list args) {
	int dc = 1;
	int cf = 0;
	long int digit = va_arg(args, int);
	long int digitaux;

	if (digit < 0) {
		cf += _putchar('-');
		digit *= -1;
	}

	if (digit < 10) return (cf += _putchar(digit + '0'));

	digitaux = digit;

	while (digitaux > 9) {
		dc *= 10;
		digitaux /= 10;
	}
	while (dc >= 1) {
		cf += _putchar(((digit / dc) % 10) + '0');
		dc /= 10;
	}

	return (cf);
}

