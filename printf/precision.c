#include <stdio.h>

int main(void)
{
	printf("[%2.0d]\n", -12);
	printf("[%5.0d]\n", -12);
	printf("[%2.1d]\n", -12);
	printf("[%5.1d]\n", -12);
	printf("[%10.5d]\n", -12);

	printf("[%0-2.0d]\n", 2);
	printf("[%0-2.2d]\n", 2);
	printf("[%0-2.4d]\n", 2);
	printf("[%1.2d]\n", 2);
	printf("[%2.1d]\n", 2);
	printf("[%1.5d]\n", -2);
// 整数の場合 （変換指定子が`d`や`o`など） 
	printf("[%d]\n", 1234567);
	printf("[%d]\n", -1234567);

	printf("[%.0d]\n", 1234567);
	printf("[%.5d]\n", 1234567);

	printf("[%.10d]\n", 1234567);
	printf("[%.10d]\n", -1234567);

// 変換指定子が`f`, `e`, `E`の場合
	printf("[%f]\n", 123.321);
	printf("[%f]\n", -123.321);
	printf("[%f]\n", 1234567.7654321);
	printf("[%f]\n", -1234567.7654321);

	printf("[%e]\n", 123.321);
	printf("[%e]\n", -123.321);
	printf("[%e]\n", 1234567.7654321);
	printf("[%e]\n", -1234567.7654321);

	printf("[%E]\n", 123.321);
	printf("[%E]\n", -123.321);
	printf("[%E]\n", 1234567.7654321);
	printf("[%E]\n", -1234567.7654321);

	printf("[%.0f]\n", 123.321);
	printf("[%.0f]\n", 1234567.7654321);
	printf("[%.5f]\n", 1234567.7654321);

	printf("[%.0e]\n", 123.321);
	printf("[%.0e]\n", 1234567.7654321);
	printf("[%.5e]\n", 1234567.7654321);

	printf("[%.0E]\n", 123.321);
	printf("[%.0E]\n", 1234567.7654321);
	printf("[%.5E]\n", 1234567.7654321);

	printf("[%.5f]\n", 123.321);
	printf("[%.10f]\n", 123.321);
	printf("[%.10f]\n", -123.321);
	printf("[%.10f]\n", 1234567.7654321);
	printf("[%.10f]\n", -1234567.7654321);

	printf("[%.5e]\n", 123.321);
	printf("[%.10e]\n", 123.321);
	printf("[%.10e]\n", -123.321);
	printf("[%.10e]\n", 1234567.7654321);
	printf("[%.10e]\n", -1234567.7654321);

	printf("[%.5E]\n", 123.321);
	printf("[%.10E]\n", 123.321);
	printf("[%.10E]\n", -123.321);
	printf("[%.10E]\n", 1234567.7654321);
	printf("[%.10E]\n", -1234567.7654321);

//変換指定子が`g`, `G`の場合
	printf("[%g]\n", 123.321);
	printf("[%G]\n", 123.321);
	printf("[%g]\n", -123.321);
	printf("[%G]\n", -123.321);

	printf("[%.0g]\n", 123.321);
	printf("[%.0G]\n", 123.321);
	printf("[%.1g]\n", 123.321);
	printf("[%.1G]\n", 123.321);
	printf("[%.2g]\n", 123.321);
	printf("[%.2G]\n", 123.321);
	printf("[%.3g]\n", 123.321);
	printf("[%.3G]\n", 123.321);
	printf("[%.4g]\n", 123.321);
	printf("[%.4G]\n", 123.321);
	printf("[%.5g]\n", 123.321);
	printf("[%.5G]\n", 123.321);
	printf("[%.6g]\n", 123.321);
	printf("[%.6G]\n", 123.321);


	printf("[%.10g]\n", 123.321);
	printf("[%.10G]\n", 123.321);
	printf("[%.10g]\n", -123.321);
	printf("[%.10G]\n", -123.321);

	printf("[%.20g]\n", 123.321);
	printf("[%.20G]\n", 123.321);
	printf("[%.20g]\n", -123.321);
	printf("[%.20G]\n", -123.321);

	printf("[%.20g]\n", 1234567.7654321);
	printf("[%.20G]\n", 1234567.7654321);
	printf("[%.20g]\n", -1234567.7654321);
	printf("[%.20G]\n", -1234567.7654321);
//文字列の場合
	printf("[%.1s]\n", "apple");
	printf("[%.3s]\n", "apple");
	printf("[%.10s]\n", "apple");

//'.'を使用したケース
printf("[%.d]\n", 1234567);

	//以下'*'の場合
// 整数の場合 （変換指定子が`d`や`o`など） 
	printf("[%.*d]\n", 0, 1234567);
	printf("[%.*d]\n", 5, 1234567);

	printf("[%.*d]\n", 10, 1234567);
	printf("[%.*d]\n", 10, -1234567);

// 変換指定子が`f`, `e`, `E`の場合
	printf("[%.*f]\n", 0, 123.321);
	printf("[%.*f]\n", 0, 1234567.7654321);
	printf("[%.*f]\n", 5, 1234567.7654321);

	printf("[%.*e]\n", 0, 123.321);
	printf("[%.*e]\n", 0, 1234567.7654321);
	printf("[%.*e]\n", 5, 1234567.7654321);

	printf("[%.*E]\n", 0, 123.321);
	printf("[%.*E]\n", 0, 1234567.7654321);
	printf("[%.*E]\n", 5, 1234567.7654321);

	printf("[%.*f]\n", 5, 123.321);
	printf("[%.*f]\n", 10, 123.321);
	printf("[%.*f]\n", 10, -123.321);
	printf("[%.*f]\n", 10, 1234567.7654321);
	printf("[%.*f]\n", 10, -1234567.7654321);

	printf("[%.*e]\n", 5, 123.321);
	printf("[%.*e]\n", 10, 123.321);
	printf("[%.*e]\n", 10, -123.321);
	printf("[%.*e]\n", 10, 1234567.7654321);
	printf("[%.*e]\n", 10, -1234567.7654321);

	printf("[%.*E]\n", 5, 123.321);
	printf("[%.*E]\n", 10, 123.321);
	printf("[%.*E]\n", 10, -123.321);
	printf("[%.*E]\n", 10, 1234567.7654321);
	printf("[%.*E]\n", 10, -1234567.7654321);

//変換指定子が`g`, `G`の場合
	printf("[%.*g]\n", 0, 123.321);
	printf("[%.*G]\n", 0, 123.321);
	printf("[%.*g]\n", 1, 123.321);
	printf("[%.*G]\n", 1, 123.321);
	printf("[%.*g]\n", 2, 123.321);
	printf("[%.*G]\n", 2, 123.321);
	printf("[%.*g]\n", 3, 123.321);
	printf("[%.*G]\n", 3, 123.321);
	printf("[%.*g]\n", 4, 123.321);
	printf("[%.*G]\n", 4, 123.321);
	printf("[%.*g]\n", 5, 123.321);
	printf("[%.*G]\n", 5, 123.321);
	printf("[%.*g]\n", 6, 123.321);
	printf("[%.*G]\n", 6, 123.321);

	printf("[%.*g]\n", 10, 123.321);
	printf("[%.*G]\n", 10, 123.321);
	printf("[%.*g]\n", 10, -123.321);
	printf("[%.*G]\n", 10,  -123.321);

	printf("[%.*g]\n", 20, 123.321);
	printf("[%.*g]\n", 20, 123.321);
	printf("[%.*g]\n", 20, -123.321);
	printf("[%.*G]\n", 20, -123.321);

	printf("[%.*g]\n", 20, 1234567.7654321);
	printf("[%.*G]\n", 20,  1234567.7654321);
	printf("[%.*g]\n", 20, -1234567.7654321);
	printf("[%.*G]\n", 20, -1234567.7654321);
//文字列の場合
	printf("[%.*s]\n", 1, "apple");
	printf("[%.*s]\n", 3, "apple");
	printf("[%.*s]\n", 10, "apple");
//精度0で0を出力した場合
	printf("[%.0d]\n", 0);
	return (0);
}
