#include <unistd.h>

int main(void)
{
	int i = "123";
	write(1, &i, 4);
}
