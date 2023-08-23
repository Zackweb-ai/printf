#include "main.h"
#include <unistd.h>


int print_mod(va_list args){
	(void)args;
	_putchar('%');
	return (1);
}

