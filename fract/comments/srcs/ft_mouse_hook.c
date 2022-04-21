/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 07:58:18 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/04/21 21:54:00 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_translation_back(t_data *data, double x_cp, double y_cp)
{
	data->min_r = data->min_r + x_cp;
	data->max_r = data->max_r + x_cp;
	data->min_i = data->min_i + y_cp;
	data->max_i = data->max_i + y_cp;
}

static void	ft_translation_to_zero(t_data *data, double x_cp, double y_cp)
{
	data->min_r = data->min_r - x_cp;
	data->max_r = data->max_r - x_cp;
	data->min_i = data->min_i - y_cp;
	data->max_i = data->max_i - y_cp;
}

static void	ft_scale(t_data *data, double ratio)
{
	data->min_r = data->min_r * ratio;
	data->max_r = data->max_r * ratio;
	data->min_i = data->min_i * ratio;
	data->max_i = data->max_i * ratio;
}

int	ft_mouse_hook(int button, int x, int y, t_data *data)
{
	double	x_cp;
	double	y_cp;

	if (button == SCROLL_UP || button == SCROLL_DOWN)
	{
		//change pixel(got from mouse's position) to complex number;
		x_cp = ((data->max_r - data->min_r) * (double)x)
			/ (double)WIDTH + data->min_r;
		y_cp = ((data->max_i - data->min_i) * (double)y)
			/ (double)HEIGHT + data->min_i;
//logic
//https://imagingsolution.blog.fc2.com/blog-entry-287.html?sp
		ft_translation_to_zero(data, x_cp, y_cp);
		if (button == SCROLL_UP)
		{
			ft_scale(data, ZOOM_IN_RATIO);
			data->max_it += 2;
		}
		else
		{
			ft_scale(data, ZOOM_OUT_RATIO);
			if (4 < data->max_it)
				data->max_it -= 2;
		}
		ft_translation_back(data, x_cp, y_cp);
	}
	return (0);
}
