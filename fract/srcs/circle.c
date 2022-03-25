#include "fract.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel /8));
	*(unsigned int *)dst = color;
}

void draw_circle(t_data img, unsigned int width, unsigned int height, unsigned int radius, unsigned int x1, unsigned int y1)
{
	unsigned int x, y;
	unsigned int dx, dy;

	for(y = 0; y < height; y++)
	{
		for(x = 0; x < width; x++)
		{
			dx = (int)x - (int)x1;
			dy = (int)y - (int)y1;
			if((dx * dx) + (dy * dy) <= radius * radius)
				my_mlx_pixel_put(&img, x, y, 0x00FFFF00);
		}
	}
}

int main(void)
{
	void	  *mlx;
	void	  *mlx_win;
	t_data  img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 400, "Circle");
	img.img = mlx_new_image(mlx, 600, 400);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw_circle(img, 600, 400, 100, 300, 200);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
