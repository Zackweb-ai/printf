#includ#include <stdarg.h>
#include <stddef.h>

int get_function(char con_spec, va_list args)
{
	int i = 0;
	int count_fun = 0;

	specifiers_t spec[] = {
		{'c', print_char},
	{'s', print_string},
		{'%', print_mod},
		{'d', print_digit},
		{'i', print_digit},
		{'r', print_rev_string},
		{0, NULL}
	};

	while (spec[i].specifiers)
	
		if (con_spe
