#ifndef FRACT_H
# define FRACT_H

# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"

#define WIDTH 600
#define HEIGHT 300
#define ERROR 1

#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0x00FF00
#define WHITE_PIXEL 0xFFFFFF

/*
typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_data;
*/

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	int		cur_img;
	char	*addr;
	int	bpp;
	int	line_len;
	int	endian;
}	t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

#endif
