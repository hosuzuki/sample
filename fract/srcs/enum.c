#include <stdio.h>

enum e_fractal_type {
	JULIA,
	MANDELBROT,
	BURNINGSHIP,
};

enum e_input_type {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

int main(void)
{
	printf("%d, %d, %d\n", JULIA, ON_EXPOSE, BURNINGSHIP);
	return (0);
}
