#include "fract.h"

void	img_pix_put(t_data *data, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = img->bpp - 8;
    pixel = data->addr + (y * data->line_len + x * (data->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (data->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (data->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}
/* The x and y coordinates of the rect corresponds to its upper left corner. */
int render_rect(t_data *data, t_rect rect)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(data, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	render_background(t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			img_pix_put(data, j++, i, color);
		}
		++i;
	}
}

int	handle_keypress(int keysym, t_data *data) //
{
	if (keysym == XK_Escape) //
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	return (0);
}

int	render(t_data *data)
{
	if (data->win == NULL)
		return (1);
	render_background(data, WHITE_PIXEL);
	render_rect(data, (t_rect){WIDTH - 100, HEIGHT - 100, 100, 100, GREEN_PIXEL});
	render_rect(data, (t_rect){0, 0, 100, 100, RED_PIXEL});

	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);

	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (ERROR);
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "my window");
	if (data.win == NULL)
	{
		free(data.mlx);
		return (ERROR);
	}
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_len, &data.endian);
	mlx_loop_hook(data.mlx, &render, &data);

	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);

	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.img);
	mlx_destroy_display(data.mlx);
	free(data.mlx_ptr);
}
