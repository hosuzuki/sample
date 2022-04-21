/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 07:58:17 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/04/21 21:31:37 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;
	int		i;

	//data->bpp =32
	i = data->bpp - 8; //i = 24 bits = 3 bytes 
										 //these 3 bytes represent colors(rgb)
	//want to know the offset from data->addr
	//data->addr = where the pixel starts
	//it is just a line memory so that y and x can be calculated in a same formula.
	pixel = data->addr + (
			y * data->line_len //y * 1200 // 
			+
			x * (data->bpp / 8)); //4
	while (i >= 0)//24, 16, 8, 0
	{
		if (data->endian != 0) //big endian
			//0xFF = 11111111
			//color = 4 bytes 
			*pixel++ = (color >> i) & 0xFF;
			//0 255 255 255 >> i(24) = 0
			//0 255 255 255 >> i(18) = 255
			//0 255 255 255 >> i(8) = 255
			//0 255 255 255 >> i(0) = 255
		else // endian = 0 = little endian
			*pixel++ = (color >> (data->bpp - 8 - i)) & 0xFF;
			//0 255 255 255 >> (32 - 8 - 24 = 0) = 255
			//0 255 255 255 >> (32 - 8 - 18 = 8) = 255
			//0 255 255 255 >> (32 - 8 - 8 = 16) = 255
			//0 255 255 255 >> (32 - 8 - 0 = 24) = 0
		i -= 8;
	}
}

unsigned int	ft_pick_color(t_data *data)
{
	int		i;
	int		color;
	double	tmp_r;

	i = 0;
	//max_it = 100 (initial)
	while (pow(data->z_r, 2.0) + pow(data->z_i, 2.0) <= 4 && i < data->max_it)
	{
		tmp_r = pow(data->z_r, 2.0) - pow(data->z_i, 2.0) + data->c_r;
		data->z_i = 2 * data->z_r * data->z_i + data->c_i;
		data->z_r = tmp_r;
		i++;
	}
	if (i == data->max_it)
		color = ft_rgb(255, 255, 255);
	else
		color = ft_gradation(data, (double)i
				/ (double)data->max_it, pow(data->z_r, 2.0));
	return (color);
}

int	ft_draw_mandelbrot(t_data *data)
{
	int	x;
	int	y;

	//get delta of how much one pixel move in complex plain.
	data->delta_r = (data->max_r - data->min_r) / (double)WIDTH;
	data->delta_i = (data->max_i - data->min_i) / (double)HEIGHT;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			// start from min_r. move by one pixel.
			data->c_r = data->min_r + 
				x * data->delta_r;
			data->c_i = data->min_i + y * data->delta_i;
			data->z_r = 0;
			data->z_i = 0;
			ft_my_mlx_pixel_put(data, x, y, ft_pick_color(data));
			x++;
		}
		y++;
	}
	return (0);
}
