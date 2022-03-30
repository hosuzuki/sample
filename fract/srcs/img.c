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

int handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	return (0);
}

int render(t_data * data)
{
	if (data->win != NULL)
		mlx_pixel_put(data->mlx, data->win, 640 / 2, 360 / 2, 0xFF0000);
	return (0);
}

int main(void)
{
	t_data data;
	
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (1);
	data.win = mlx_new_window(data.mlx, 640, 360, "window");
	if (data.win == NULL)
	{
		free (data.mlx);
		return (1);
	}
	data.img = mlx_new_image(mlx, 640, 360);
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

/*
 * int *buffer = (int *)mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	data.line_length /= 4;
	int color = 0xABCDEF;

	for(int y = 0; y < 360; ++y)
	for(int x = 0; x < 640; ++x)
	{
		buffer[(y * data.line_length) + x] = color;
	}
*/
	mlx_loop_hook(data.mlx, &render, &data);
//	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx);

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
//  	mlx_put_image_to_window(mlx, win, data.img, 0, 0);

//	while (1)
//	mlx_mouse_hook(win, &mouse_event, &img);
//	mlx_loop(mlx);
//	mlx_destroy_window(mlx, win);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}

