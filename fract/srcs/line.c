#include "fract.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
#define PI 3.14

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel /8));
	*(unsigned int *)dst = color;
}

int rgb_to_int(double r, double g, double b)
{
	int color;

	color = 0;
	color |= (int)(b * 255); // 255 = 1111 1111
	color |= (int)(g * 255) << 8; // |= means results of | will be affected to the one in the left. in this case color.
	color |= (int)(r * 255) << 16;
	return (color);
}
*/

int draw_line(void * mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
	double deltaX = endX - beginX;
	double deltaY = endY - beginY;
	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	double pixelX = beginX;
	double pixelY = beginY;
	while (pixels)
	{
//		my_mlx_pixel_put(data, pixelX, pixelY, color);
		mlx_pixel_put(mlx, win, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
	return (0);
}

int main(void)
{
	void	  *mlx;
	void	  *mlx_win;
//	t_data  img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 400, "Line");
//	img.img = mlx_new_image(mlx, 600, 400);
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw_line(mlx, mlx_win, 600, 400, 0, 0, 0xFFFFFF);
//	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
