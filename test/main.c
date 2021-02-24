#include <stdio.h>

long unsigned	my_strlen(const char *s);

int				main(void)
{
	printf("length: %lu\n", my_strlen("test"));
	printf("length: %lu\n", my_strlen(""));
	printf("length: %lu\n", my_strlen("hello world"));
	return (0);
}
