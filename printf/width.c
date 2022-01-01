#include <stdio.h>

int main(void)
{
//1: '-'flag + '0'flag : ERROR
/*
	printf("[%-0d]\n", 1);
	printf("[%-0d]\n", -1);
	printf("[%-010d]\n", 1);
	printf("[%-010d]\n", -1);
*/

//2: '-'flag + '+'flag
	printf("[%-+d]\n", 1);
	printf("[%-+d]\n", -1);
	printf("[%-+10d]\n", 1);
	printf("[%-+10d]\n", -1);

	printf("[%-+f]\n", 1.0);
	printf("[%-+f]\n", -1.0);
	printf("[%-+10f]\n", 1.0);
	printf("[%-+10f]\n", -1.0);
//3: '-'flag + '(space)'flag
	printf("[%- d]\n", 1);
	printf("[%- d]\n", -1);
	printf("[%- 10d]\n", 1);
	printf("[%- 10d]\n", -1);

	printf("[%- f]\n", 1.0);
	printf("[%- f]\n", -1.0);
	printf("[%- 10f]\n", 1.0);
	printf("[%- 10f]\n", -1.0);

//4: '-'flag + '#'flag
	printf("[%-#o]\n", 10);
	printf("[%-#10o]\n", 10);

//5: '0'flag + '-'flag : ERROR
/*
	printf("[%0-d]\n", 1);
	printf("[%0-d]\n", -1);
	printf("[%0-10d]\n", 1);
	printf("[%0-10d]\n", -1);
*/

//6: '0'flag + '+'flag
	printf("[%0+d]\n", 1);
	printf("[%0+d]\n", -1);
	printf("[%0+10d]\n", 1);
	printf("[%0+10d]\n", -1);

	printf("[%0+f]\n", 1.0);
	printf("[%0+f]\n", -1.0);
	printf("[%0+10f]\n", 1.0);
	printf("[%0+10f]\n", -1.0);

//7: '0'flag + '(space)'flag
	printf("[%0 d]\n", 1);
	printf("[%0 d]\n", -1);
	printf("[%0 10d]\n", 1);
	printf("[%0 10d]\n", -1);

	printf("[%0 f]\n", 1.0);
	printf("[%0 f]\n", -1.0);
	printf("[%0 10f]\n", 1.0);
	printf("[%0 10f]\n", -1.0);

//8: '0'flag + '#'flag
	printf("[%0#o]\n", 10);
	printf("[%0#10o]\n", 10);

//9: '+'flag + '-'flag
	printf("[%+-d]\n", 1);
	printf("[%+-d]\n", -1);
	printf("[%+-10d]\n", 1);
	printf("[%+-10d]\n", -1);

	printf("[%+-f]\n", 1.0);
	printf("[%+-f]\n", -1.0);
	printf("[%+-10f]\n", 1.0);
	printf("[%+-10f]\n", -1.0);

//10: '+'flag + '0'flag
	printf("[%+0d]\n", 1);
	printf("[%+0d]\n", -1);
	printf("[%+010d]\n", 1);
	printf("[%+010d]\n", -1);

	printf("[%+0f]\n", 1.0);
	printf("[%+0f]\n", -1.0);
	printf("[%+010f]\n", 1.0);
	printf("[%+010f]\n", -1.0);

//11: '+'flag + '(space)'flag : ERROR
/*
	printf("[%+ d]\n", 1);
	printf("[%+ d]\n", -1);
	printf("[%+ 10d]\n", 1);
	printf("[%+ 10d]\n", -1);
*/

//12: '+'flag + '#'flag : ERROR
/*
	printf("[%+#o]\n", 10);
	printf("[%+#10o]\n", 10);
*/

//13: '(space)'flag + '-'flag
	printf("[% -d]\n", 1);
	printf("[% -d]\n", -1);
	printf("[% -10d]\n", 1);
	printf("[% -10d]\n", -1);

	printf("[% -f]\n", 1.0);
	printf("[% -f]\n", -1.0);
	printf("[% -10f]\n", 1.0);
	printf("[% -10f]\n", -1.0);


//14: '(space)'flag + '0'flag
	printf("[% 0d]\n", 1);
	printf("[% 0d]\n", -1);
	printf("[% 010d]\n", 1);
	printf("[% 010d]\n", -1);

	printf("[% 0f]\n", 1.0);
	printf("[% 0f]\n", -1.0);
	printf("[% 010f]\n", 1.0);
	printf("[% 010f]\n", -1.0);

//15: '(space)'flag + '+'flag : ERROR
/*
	printf("[% +d]\n", 1);
	printf("[% +d]\n", -1);
	printf("[% +10d]\n", 1);
	printf("[% +10d]\n", -1);
*/

//16: '(space)'flag + '#'flag : ERROR
/*
	printf("[% #o]\n", 10);
	printf("[% #10o]\n", 10);
*/

//17: '#'flag + '-'flag
	printf("[%#-o]\n", 10);
	printf("[%#-10o]\n", 10);

//18: ' #'flag + '0'flag
	printf("[%#0o]\n", 10);
	printf("[%#010o]\n", 10);

//19: '#'flag + '+'flag : ERROR
/*
	printf("[%#+o]\n", 10);
	printf("[%#+10o]\n", 10);
*/

//20: '#'flag + '(space)'flag : ERROR
/*
	printf("[%# o]\n", 10);
	printf("[%# 10o]\n", 10);
*/
	return (0);
}
