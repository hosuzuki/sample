#ifndef FRACT_H
# define FRACT_H

# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"

#define WIDTH 1200
#define HEIGHT 1200
#define ERROR 1

#define RED_PIXEL 0x00FF0000
#define GREEN_PIXEL 0x0000FF00
#define BLUE_PIXEL 0x000000FF
#define WHITE_PIXEL 0x00FFFFFF

//#define  XMAX  600                                      // ｳｨﾝﾄﾞｳ Xmax
//#define  YMAX  300                                      // ｳｨﾝﾄﾞｳ Ymax


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

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

#endif
