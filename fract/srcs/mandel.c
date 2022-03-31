#include "fract.h"
#include "keycode_mac.h"
#include <stdio.h>

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp /8));
	*(unsigned int *)dst = color;
}

void	img_pix_put(t_data *data, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = data->bpp - 8;
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

int	key_hook(int keysym, t_data *data)
{
	(void)data;
	if (keysym == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	return (0);
}

int mouse_button(int button, int x, int y, void *p)
{
	(void)p;
	printf("button %d at %d x %d\n", button, x, y);
	return (0);
}

void  render_mandel(t_data *data)
{
	double  Cr1=-2.3;                                       // 定数実部 始点
	double  Cr2= 1;                                       // 定数実部 終点
	double  Ci1=-1.5;                                       // 定数虚部 始点
	double  Ci2= 1.5;                                       // 定数虚部 終点
	double  E = 4.0;                                          // 発散とする値
	int     imax = 400;                                       // 最大計算回数

	double  Cr,Ci,dCr,dCi;
	double  zr,zi,zrN,ziN;
	int     i,ix,iy,cl,nc;
//	char    c[128];

	dCr = (Cr2 - Cr1) / WIDTH;                                 // 実部(横)刻み幅
	dCi = (Ci2 - Ci1) / HEIGHT;                                 // 虚部(縦)刻み幅
	nc = imax / 256;
	if (nc <= 0)
		nc = 1;                     // 階調比率(256階調)
	for(Ci = Ci1,iy = HEIGHT; Ci <= Ci2; Ci += dCi, iy--)        // 定数虚部(縦)
	{
		for(Cr = Cr1, ix = 0; Cr <= Cr2; Cr += dCr, ix++)       // 定数実部(横)
		{
			zr = 0.0; zi = 0.0;
			//--収束検査--
			for(i = 0; i < imax; i++ )                     // 漸化式計算
			{
				zrN = zr * zr - zi * zi + Cr;                     // 実部漸化式計算
				if (zrN > E)
					break;                     // 発散する
				ziN = 2.0 * zr * zi + Ci;                       // 虚部漸化式計算
				if (ziN > E)
					break;                     // 発散する
				zr = zrN; zi = ziN;
			}
			cl = i/nc;                                    // 階調計算
			if ( cl > 255 ) 
				cl = 255;                       // 階調補正
			img_pix_put(data, ix, iy, cl);
			//SetPixelV(hdc, ix, iy, RGB(cl,cl,cl));         // ｶﾗｰ値で点を描画
		}
	}
	//	sprintf(c,"Cr:%8.5lf,%8.5lf  Ci:%8.5lf,%8.5lf",Cr1,Cr2,Ci1,Ci2);
	//	TextOut(hdc,0,0,c,strlen(c));                       // 文字列描画
}
/*

	 void  render_mandel(t_data *data)
	 {
	 size = 4;                                // 描く領域の一辺の長さ
	 pixel = 600;                             // 描く領域の一辺のピクセル数
	 for (i = 0; pixel > i; i++)
	 {            // x（実部）方向のループ
	 x = i * size / pixel - size / 2;     // 定数Cの実部
	 for (j = 0; pixel > j; j++)
	 {        // y（虚部）方向のループ
	 y = j * size / pixel - size / 2; // 定数Cの虚部
	 a = 0;                           // くり返し計算に使う複素数zの実部
	 b = 0;                           // くり返し計算に使う複素数zの虚部
	 for (k = 0; 50 > k; k++)
	 {       // 上限を50回とするくり返し計算
	 _a = a * a - b * b + x;      // z^2+Cの計算（実部）
	 _b = 2 * a * b + y;          // z^2+Cの計算（虚部）
	 a = _a;                      // zの値を更新（実部）
	 b = _b;                      // zの値を更新（虚部）
	 if (a * a + b * b > 4)
	 {     // もし絶対値が2を（絶対値の2乗が4を）超えていたら
	 img_pix_put(data, i, j, color);
	 break;                   // 次の点の計算へ
	 }
	 }
	 }
	 }
	 }
	 */

int	render(t_data *data)
{
	if (data->win == NULL)
		return (1);
	render_background(data, WHITE_PIXEL);
	render_mandel(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

void ft_free_all(t_data *data)
{
	if (data->mlx)
		free(data->mlx);
	if (data->win)
		free(data->win);
	if (data->img)
		free(data->img);
	if (data->addr)
		free(data->addr);
}

void ft_free_all_and_exit_with_perror(t_data *data)
{
	ft_free_all(data);
	perror("ERROR");
	exit(ERROR);
}

void init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->img = NULL;
	data->addr = NULL;
}

int	main(void)
{
	t_data	data;

	init_data(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
		ft_free_all_and_exit_with_perror(&data);
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "my window");
	if (!data.win)
		ft_free_all_and_exit_with_perror(&data);
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (!data.img)
		ft_free_all_and_exit_with_perror(&data);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_len, &data.endian);
	if (!data.addr)
		ft_free_all_and_exit_with_perror(&data);

	mlx_loop_hook(data.mlx, &render, &data);
	mlx_mouse_hook(data.win, mouse_button, 0);
	mlx_hook(data.win, 2, 1L<<0, key_hook, &data);
	mlx_loop(data.mlx);

	mlx_destroy_image(data.mlx, data.img);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}
