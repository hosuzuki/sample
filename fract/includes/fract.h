#ifndef FRACT_H
# define FRACT_H

typedef struct s_data
{
	void	*img;
	void	*mlx;
	void	*win;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_data;

# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"
//void			ft_putnbr_fd(int n, int fd);

#endif
