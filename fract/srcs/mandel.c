#include "fract.h"
#include "keycode_mac.h"
#include <stdio.h>

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel /8));
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

int	key_hook(int keysym, t_data *data)
{
	//	(void)keysym;
	(void)data;
	printf("Hello from key_hook!\n");
	printf("key: %d\n", keysym);
	return (0);
}

/*
	 int mouse_hook(int key, t_data *data)
	 {
	 if (key == 4 || key == 1)
	 printf("Hello from mouse_hook!\n");
	 (void)data;
	 return (0);
	 }
	 */
int mouse_button(int button, int x, int y, void *p)
{
	(void)p;
	printf("button %d at %d x %d\n", button, x, y);
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

#include <stdio.h>

#define  XMAX  800                                      // ｳｨﾝﾄﾞｳ Xmax
#define  YMAX  800                                      // ｳｨﾝﾄﾞｳ Ymax

HWND    hWnd=NULL;                                      // ｳｨﾝﾄﾞｳのﾊﾝﾄﾞﾙ
MSG     msg;                                            // ｳｨﾝﾄﾞｳﾒｯｾｰｼﾞ
int     endFG=0;                                        // 終了ﾌﾗｸﾞ

double  Cr1=-2.3;                                       // 定数実部 始点
double  Cr2= 0.7;                                       // 定数実部 終点
double  Ci1=-1.5;                                       // 定数虚部 始点
double  Ci2= 1.5;                                       // 定数虚部 終点
double  E=4.0;                                          // 発散とする値
int     imax=400;                                       // 最大計算回数

//void  SETwindow(void);                                  // ｳｨﾝﾄﾞｳ初期設定
//void  Display(void);                                    // 図形描画

//LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);      // ｳｨﾝﾄﾞｳﾌﾟﾛｼｰｼﾞｬ

void  main( )
{
	SETwindow( );                                       // ｳｨﾝﾄﾞｳ初期設定

	while ( 1 )
	{
		if ( PeekMessage(&msg,hWnd,0,0,PM_REMOVE)==0 )  // windowsﾒｯｾｰｼﾞ取得
			continue;                                  // ﾒｯｾｰｼﾞなし
		TranslateMessage(&msg);                         // ﾒｯｾｰｼﾞ変換
		DispatchMessage (&msg);                         // ﾒｯｾｰｼﾞ送出
		if ( endFG!=0 ) break;
	}

	DestroyWindow(hWnd);                                // ｳｨﾝﾄﾞｳ破棄
}


void  SETwindow( )
	/*------------------------*/
	/*  ウィンドウ  初期設定  */
	/*------------------------*/
{
	WNDCLASS  wc;        // ｳｨﾝﾄﾞｳ ｸﾗｽ
	DWORD     Wstyle;    // ｳｨﾝﾄﾞｳ･ｽﾀｲﾙ

	//--ｳｨﾝﾄﾞｳｸﾗｽ--
	wc.lpszClassName="マンデルブロー集合";              // ｳｨﾝﾄﾞｳ･ｸﾗｽ名
	wc.lpszMenuName =NULL;                              // ｸﾗｽ･ﾒﾆｭｰ･ﾘｿｰｽ名
	wc.hInstance    =GetModuleHandle(NULL);             // ｲﾝｽﾀﾝｽ･ﾊﾝﾄﾞﾙ
	wc.lpfnWndProc  =WndProc;                           // ｳｨﾝﾄﾞｳ･ﾌﾟﾛｼｰｼﾞｬ
	wc.hCursor      =LoadCursor(NULL,IDC_ARROW);        // ｸﾗｽ･ｶｰｿﾙ
	wc.hIcon        =NULL;                              // ｸﾗｽ･ｱｲｺﾝ
	wc.hbrBackground=GetStockObject(WHITE_BRUSH);       // ｸﾗｽ背景ﾌﾞﾗｼ
	wc.style        =CS_OWNDC|                          // ｸﾗｽ･ｽﾀｲﾙ
		CS_BYTEALIGNCLIENT|
		CS_BYTEALIGNWINDOW;
	wc.cbClsExtra   =0;                                 // 補足ｸﾗｽ･ﾒﾓﾘ
	wc.cbWndExtra   =0;                                 // 補足ｳｨﾝﾄﾞｳ･ﾒﾓﾘ

	RegisterClass(&wc);                                 // ｳｨﾝﾄﾞｳ･ｸﾗｽ登録

	//--ｳｨﾝﾄﾞｳ･ｽﾀｲﾙ--
	Wstyle= WS_OVERLAPPED|                              // 自動表示位置
		WS_SYSMENU|                                 // 閉じる可能
		WS_MINIMIZEBOX;                             // 最小化可

	//--ｳｨﾝﾄﾞｳ生成--
	hWnd=CreateWindow(wc.lpszClassName,                 // クラス名
			wc.lpszClassName,                 // ｳｨﾝﾄﾞｳ名(実行ﾌｧｲﾙ)
			Wstyle,                           // ｳｨﾝﾄﾞｳ･ｽﾀｲﾙ
			0,                                // ｳｲﾝﾄﾞｳ水平位置
			0,                                // ｳｲﾝﾄﾞｳ垂直位置
			XMAX,                             // ｳｨﾝﾄﾞｳXｻｲｽﾞ(枠含む)
			YMAX+18,                          // ｳｨﾝﾄﾞｳYｻｲｽﾞ(枠含む)
			NULL,                             // 親ｳｨﾝﾄﾞｳ･ﾊﾝﾄﾞﾙ
			NULL,                             // ﾒﾆｭｰﾊﾝﾄﾞﾙ
			wc.hInstance,                     // ｱﾌﾟﾘｹｰｼｮﾝ･ｲﾝｽﾀﾝｽ･ﾊﾝﾄﾞﾙ
			NULL);                            // ｳｨﾝﾄﾞｳ作成ﾃﾞｰﾀ

	ShowWindow(hWnd,SW_SHOWDEFAULT);                    // ｳｨﾝﾄﾞｳ表示状態設定
}


void  Display( )
	/*----------------------------------*/
	/*  マンデルブロ集合  図形描画      */
	/*                                  */
	/*  漸化式が発散するまでの計算回数  */
	/*  によって、対応する画素の階調を  */
	/*  を求め、画面に描画する          */
	/*  画素は 0～255 のグレースケール  */
	/*----------------------------------*/
{
	HDC     hdc;      // ﾃﾞﾊﾞｲｽｺﾝﾃｷｽﾄ ﾊﾝﾄﾞﾙ
	double  Cr,Ci,dCr,dCi;
	double  zr,zi,zrN,ziN;
	int     i,ix,iy,cl,nc;
	char    c[128];

	dCr=(Cr2-Cr1)/XMAX;                                 // 実部(横)刻み幅
	dCi=(Ci2-Ci1)/YMAX;                                 // 虚部(縦)刻み幅
	nc=imax/256; if ( nc<=0 ) nc=1;                     // 階調比率(256階調)

	hdc=GetDC(hWnd);                                    // ｳｨﾝﾄﾞｳのDC取得

	for( Ci=Ci1,iy=YMAX; Ci<=Ci2; Ci+=dCi,iy-- )        // 定数虚部(縦)
	{
		for( Cr=Cr1,ix=0; Cr<=Cr2; Cr+=dCr,ix++ )       // 定数実部(横)
		{
			zr=0.0; zi=0.0;

			//--収束検査--
			for( i=0; i<imax; i++ )                     // 漸化式計算
			{
				zrN=zr*zr-zi*zi+Cr;                     // 実部漸化式計算
				if ( zrN>E ) break;                     // 発散する
				ziN=2.0*zr*zi+Ci;                       // 虚部漸化式計算
				if ( ziN>E ) break;                     // 発散する

				zr=zrN; zi=ziN;
			}

			cl=i/nc;                                    // 階調計算
			if ( cl>255 ) cl=255;                       // 階調補正
			SetPixelV(hdc,ix,iy,RGB(cl,cl,cl));         // ｶﾗｰ値で点を描画
		}
	}

	sprintf(c,"Cr:%8.5lf,%8.5lf  Ci:%8.5lf,%8.5lf",Cr1,Cr2,Ci1,Ci2);
	TextOut(hdc,0,0,c,strlen(c));                       // 文字列描画

	ReleaseDC(hWnd,hdc);                                // ｳｨﾝﾄﾞｳのDC 解放
}


LRESULT CALLBACK  WndProc(
		/*---------------------------*/
		/*  ウィンドウ プロシージャ  */
		/*---------------------------*/
		HWND     hwnd,      // ｳｨﾝﾄﾞｳ･ﾊﾝﾄﾞﾙ
		UINT     uMsg,      // ﾒｯｾｰｼﾞID
		WPARAM   wParam,    // 第1ﾒｯｾｰｼﾞ･ﾊﾟﾗﾒｰﾀ(無符号)
		LPARAM   lParam)    // 第2ﾒｯｾｰｼﾞ･ﾊﾟﾗﾒｰﾀ(有符号)
{
	PAINTSTRUCT hpaint;    // 描画情報
	BOOL        ir=0;

	switch ( uMsg )
	{
		case WM_CLOSE://--ｳｨﾝﾄﾞｳ閉--
			PostQuitMessage(0);                     // 実行を終了
			endFG=1;
			break;

		case WM_PAINT://--ｳｨﾝﾄﾞｳ更新--
		case WM_SETFOCUS://--ﾌｫｰｶｽ取得--
			if ( GetUpdateRect(hWnd,NULL,FALSE)==NULL )
				break;                             // 更新ﾘｰｼﾞｮﾝなし
			BeginPaint(hWnd,&hpaint);
			Display( );                             // 図形描画
			EndPaint(hWnd,&hpaint);
			break;

		default://--その他--
			ir=DefWindowProc(hwnd,uMsg,wParam,lParam);
	}

	return(ir);
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

	mlx_mouse_hook(data.win, mouse_button, 0);
	mlx_hook(data.win, 2, 1L<<0, key_hook, &data);
	//	mlx_hook(data.win, ON_DESTORY, 0, &keypress, &data);

	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.img);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}
