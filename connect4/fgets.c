#include <stdio.h>

int main(void)
{
	int number;
	char str[5];

	while (1)
	{
		fgets(str, sizeof(str), stdin);
		sscanf(str, "%d", &number);
		if (1 <= number  && number <= 6)
			return (number);
		printf("Wrong input. Please enter a number. (1 ~ 6)\n");
	}
}
