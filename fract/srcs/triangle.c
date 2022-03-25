#include "fract.h"

#include <stdio.h>
#include <stdlib.h>

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel /8));
	*(unsigned int *)dst = color;
}

int main(void)
{
  void	  *mlx;
  void	  *mlx_win;
  t_data  img;
  int     i;
  int     j;
  int     k;

  mlx = mlx_init();
  mlx_win = mlx_new_window(mlx, 600, 400, "Triangle");
  img.img = mlx_new_image(mlx, 600, 400);
  img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
  for (i = 200, k = 99; i < 300; i++, k -= 1)
  {
    for (j = 150 + k; j < 250; j++)
      my_mlx_pixel_put(&img, i, j, 0x00FFFF00);
  }
  for (i = 300, k = 0; i < 350; i++, k += 2)
  {
    for (j = 150 + k; j < 250; j++)
	     my_mlx_pixel_put(&img, i, j, 0x000000FF);
  }
  for (i = 200, k = 99; i < 300; i++, k -= 1)
  {
    for (j = 350 - k; j > 250 ; j--)
      my_mlx_pixel_put(&img, i, j, 0x000000FF);
  }
  for (i = 300, k = 0; i < 350; i++, k += 2)
  {
    for (j = 350 - k; j > 250; j--)
	     my_mlx_pixel_put(&img, i, j, 0x00FFFF00);
  }
  mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
  mlx_loop(mlx);
  return (0);
}

/*

