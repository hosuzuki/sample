#include "fract.h"

int mouse_event(int button, int x, int y, void *param)
{
	t_data *img = param;
	
	mlx_pixel_put(img->mlx, img->win, 640/2, 360/2, 0xFFFFFF);
	(void)x;
	(void)y;
	(void)button;
	//	ft_putnbr_fd(button, 2);
	return (1);
}

int main(void)
{
	t_data img;
	
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 640, 360, "Event");
	void *img1 = mlx_new_image(mlx, 640, 360);
	img.mlx = mlx;
	img.win = win;
	img.img = img1;
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	int *buffer = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	img.line_length /= 4;
	int color = 0xABCDEF;

	for(int y = 0; y < 360; ++y)
	for(int x = 0; x < 640; ++x)
	{
		buffer[(y * img.line_length) + x] = color;
	}
/*
	int color = 0xABCDEF;
	if (img.bits_per_pixel != 32)
		color = mlx_get_color_value(mlx, color);
	for (int y = 0; y < 360; ++y)
	for (int x = 0; x < 640; ++x)
	{
		int pixel = (y * img.line_length) + (x * 4);

		if (img.endian == 1)
		{
			img.addr[pixel + 0] = (color >> 24);
			img.addr[pixel + 1] = (color >> 16) & 0xFF;
			img.addr[pixel + 2] = (color >> 8) & 0xFF;
			img.addr[pixel + 3] = (color) & 0xFF;
		}
		else if (img.endian == 0)
		{
			img.addr[pixel + 0] = (color) & 0xFF;
			img.addr[pixel + 1] = (color >> 8) & 0xFF;
			img.addr[pixel + 2] = (color >> 16) & 0xFF;
			img.addr[pixel + 3] = (color >> 24);
		}
	}
*/
  	mlx_put_image_to_window(mlx, win, img.img, 0, 0);


	mlx_mouse_hook(win, &mouse_event, &img);
	mlx_loop(mlx);
}

