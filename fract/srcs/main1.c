#include "fract.h"

#include <stdio.h>
#include <stdlib.h>

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel /8));
	*(unsigned int *)dst = color;
}

void	press_esc_key(int key, void *p)
{
	(void)p;
	if (key == 0xFF1B)
		exit(0);
}

void	key_check(int key,void *p)
{
	(void)p;
  printf("Key in Win : %d\n",key);
  if (key==0xFF1B)
    exit(0);
}

int main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx_test");
	mlx_key_hook(win_ptr, press_esc_key, win_ptr);
	mlx_loop(mlx_ptr);
}
/*
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
*/

/*
int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int get_b(int trgb)
{
	return (trgb & 0xFF);
}

int create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]{b, g, r t});
}

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img	= mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 105, 105, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
*/

