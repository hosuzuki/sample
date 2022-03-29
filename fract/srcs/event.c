#include "fract.h"

int mouse_event(int button, int x, int y, void *param)
{
	(void)x;
	(void)y;
	(void)param;
	ft_putnbr_fd(button, 2);
	return (0);
}

int main(void)
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 640, 360, "Event");
	mlx_mouse_hook(win, &mouse_event, 0);
	mlx_loop(mlx);
}

