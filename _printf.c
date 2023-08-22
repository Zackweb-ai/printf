#include "main.h"

int _printf(const char *format, ...) {
	
	int count = 0;
	va_list args;
	va_start(args, format);


	while (*format != '\0') {
	if (*format == '%') {
	format++; 

            /* Handle the conversion specifiers*/
            if (*format == 'c') {
                char c = va_arg(args, int); /* Get a character argument */
                putchar(c);
                count++;
            } else if (*format == 's') {
                char *s = va_arg(args, char *); /* Get a string argument */
                while (*s != '\0') {
                    putchar(*s);
                    s++;
                    count++;
                }
            } else if (*format == '%') {
                putchar('%');
                count++;
            }
        } else {
            putchar(*format);
            count++;
        }
        format++; /* Move to the next character in the format string */
    }

    va_end(args);
    return count;
}

int main() {
    char c = 'A';
    char *str = "Hello, World!";
    
    int result = _printf("Character: %c, String: %s, Percent: %%\n", c, str);

	printf("\nNumber of characters printed: %d\n", result);
    
    return 0;
}
