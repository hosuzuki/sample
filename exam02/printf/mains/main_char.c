#include <stdio.h>
#include "./includes/ft_printf.h"

int main(void)
{
	printf("\x1b[32mgeneral\n\x1b[39m");
	printf(" => %d\n", printf("[%c]", 'a'));
	printf(" => %d\n", ft_printf("[%c]", 'a'));
	printf("\n");

/*	printf("\x1b[32m'-'flag\n\x1b[39m");
	printf(" => %d\n", printf("[%-c]", 'a'));
	printf(" => %d\n", ft_printf("[%-c]", 'a'));
	printf(" => %d\n", printf("[%-10c]", 'a'));
	printf(" => %d\n", ft_printf("[%-10c]", 'a'));
	printf(" => %d\n", printf("[%-.10c]", 'a'));
	printf(" => %d\n", ft_printf("[%-.10c]", 'a'));
	printf("\x1b[33mundefined behavior\n\x1b[39m"); 
	printf(" => %d\n", printf("[%-15.10c]", 'a'));
	printf(" => %d\n", ft_printf("[%-15.10c]", 'a'));
	printf("\x1b[33mundefined behavior\n\x1b[39m"); 
	printf(" => %d\n", printf("[%-15.10c]", 'a'));
	printf(" => %d\n", ft_printf("[%-15.10c]", 'a'));
	printf("\n");

	printf("\x1b[32m' 'flag\n\x1b[39m");
	printf("\x1b[33mundefined behavior\n\x1b[39m"); 
	printf(" => %d\n", printf("[% c]", 'a'));
	printf(" => %d\n", ft_printf("[% c]", 'a'));
	printf("\x1b[33mundefined behavior\n\x1b[39m"); 
	printf(" => %d\n", printf("[% 10c]", 'a'));
	printf(" => %d\n", ft_printf("[% 10c]", 'a'));
	printf("\x1b[33mundefined behavior\n\x1b[39m"); 
	printf(" => %d\n", printf("[% .10c]", 'a'));
	printf(" => %d\n", ft_printf("[% .10c]", 'a'));
	printf("\x1b[33mundefined behavior\n\x1b[39m"); 
	printf(" => %d\n", printf("[% 15.10c]", 'a'));
	printf(" => %d\n", ft_printf("[% 15.10c]", 'a'));
	printf("\x1b[33mundefined behavior\n\x1b[39m"); 
	printf(" => %d\n", printf("[% 10.15c]", 'a'));
	printf(" => %d\n", ft_printf("[% 10.15c]", 'a'));
	printf("\n");
	
	printf("\x1b[32m'+'flag\n\x1b[39m");
	printf("\x1b[33mundefined behavior\n\x1b[39m"); 
	printf(" => %d\n", printf("[%+c]", 'a'));
	printf(" => %d\n", ft_printf("[%+c]", 'a'));
	printf("\x1b[33mundefined behavior\n\x1b[39m"); 
	printf(" => %d\n", printf("[%+10c]", 'a'));
	printf(" => %d\n", ft_printf("[%+10c]", 'a'));
	printf("\x1b[33mundefined behavior\n\x1b[39m"); 
	printf(" => %d\n", printf("[%+.10c]", 'a'));
	printf(" => %d\n", ft_printf("[%+.10c]", 'a'));
	printf("\x1b[33mundefined behavior\n\x1b[39m"); 
	printf(" => %d\n", printf("[%+15.10c]", 'a'));
	printf(" => %d\n", ft_printf("[%+15.10c]", 'a'));
	printf("\x1b[33mundefined behavior\n\x1b[39m"); 
	printf(" => %d\n", printf("[%+10.15c]", 'a'));
	printf(" => %d\n", ft_printf("[%+10.15c]", 'a'));
	printf("\n");

	printf("\x1b[32m'#'flag\n\x1b[39m");
	printf("\x1b[33mundefined behavior\n\x1b[39m"); 
	printf(" => %d\n", printf("[%#c]", 'a'));
	printf(" => %d\n", ft_printf("[%#c]", 'a'));
	printf("\x1b[33mundefined behavior\n\x1b[39m"); 
	printf(" => %d\n", printf("[%#10c]", 'a'));
	printf(" => %d\n", ft_printf("[%#10c]", 'a'));
	printf("\x1b[33mundefined behavior\n\x1b[39m"); 
	printf(" => %d\n", printf("[%#.10c]", 'a'));
	printf(" => %d\n", ft_printf("[%#.10c]", 'a'));
	printf("\x1b[33mundefined behavior\n\x1b[39m"); 
	printf(" => %d\n", printf("[%#15.10c]", 'a'));
	printf(" => %d\n", ft_printf("[%#15.10c]", 'a'));
	printf("\x1b[33mundefined behavior\n\x1b[39m"); 
	printf(" => %d\n", printf("[%#10.15c]", 'a'));
	printf(" => %d\n", ft_printf("[%#10.15c]", 'a'));
	printf("\n");

	printf("\x1b[32m'0'flag\n\x1b[39m");
	printf("\x1b[33mundefined behavior\n\x1b[39m"); 
	printf(" => %d\n", printf("[%0c]", 'a'));
	printf(" => %d\n", ft_printf("[%0c]", 'a'));
	printf("\x1b[33mundefined behavior\n\x1b[39m"); 
	printf(" => %d\n", printf("[%010c]", 'a'));
	printf(" => %d\n", ft_printf("[%010c]", 'a'));
	printf("\x1b[33mundefined behavior\n\x1b[39m"); 
	printf(" => %d\n", printf("[%0.10c]", 'a'));
	printf(" => %d\n", ft_printf("[%0.10c]", 'a'));
	printf("\x1b[33mundefined behavior\n\x1b[39m"); 
	printf(" => %d\n", printf("[%015.10c]", 'a'));
	printf(" => %d\n", ft_printf("[%015.10c]", 'a'));
	printf("\x1b[33mundefined behavior\n\x1b[39m"); 
	printf(" => %d\n", printf("[%010.15c]", 'a'));
	printf(" => %d\n", ft_printf("[%010.15c]", 'a'));
	printf("\n");
*/
	printf("\x1b[32mflag combo\n\x1b[39m");
	printf("\x1b[32m'-'flag + '+'flag\n\x1b[39m");
	printf("[%-+d]\n", 1);
	printf("[%-+d]\n", -1);
	printf("[%-+10d]\n", 1);
	printf("[%-+10d]\n", -1);

	printf("[%-+f]\n", 1.0);
	printf("[%-+f]\n", -1.0);
	printf("[%-+10f]\n", 1.0);
	printf("[%-+10f]\n", -1.0);

	printf("\n");

	printf("\x1b[32m'-'flag + ' 'flag\n\x1b[39m");
	printf("[%- d]\n", 1);
	printf("[%- d]\n", -1);
	printf("[%- 10d]\n", 1);
	printf("[%- 10d]\n", -1);

	printf("[%- f]\n", 1.0);
	printf("[%- f]\n", -1.0);
	printf("[%- 10f]\n", 1.0);
	printf("[%- 10f]\n", -1.0);
	printf("\n");

//4: '-'flag + '#'flag
	printf("[%-#o]\n", 10);
	printf("[%-#10o]\n", 10);
	printf("\n");

//6: '0'flag + '+'flag
	printf("[%0+d]\n", 1);
	printf("[%0+d]\n", -1);
	printf("[%0+10d]\n", 1);
	printf("[%0+10d]\n", -1);

	printf("[%0+f]\n", 1.0);
	printf("[%0+f]\n", -1.0);
	printf("[%0+10f]\n", 1.0);
	printf("[%0+10f]\n", -1.0);
	printf("\n");

//7: '0'flag + '(space)'flag
	printf("[%0 d]\n", 1);
	printf("[%0 d]\n", -1);
	printf("[%0 10d]\n", 1);
	printf("[%0 10d]\n", -1);

	printf("[%0 f]\n", 1.0);
	printf("[%0 f]\n", -1.0);
	printf("[%0 10f]\n", 1.0);
	printf("[%0 10f]\n", -1.0);
	printf("\n");

//8: '0'flag + '#'flag
	printf("[%0#o]\n", 10);
	printf("[%0#10o]\n", 10);
	printf("\n");

//9: '+'flag + '-'flag
	printf("[%+-d]\n", 1);
	printf("[%+-d]\n", -1);
	printf("[%+-10d]\n", 1);
	printf("[%+-10d]\n", -1);

	printf("[%+-f]\n", 1.0);
	printf("[%+-f]\n", -1.0);
	printf("[%+-10f]\n", 1.0);
	printf("[%+-10f]\n", -1.0);
	printf("\n");

//10: '+'flag + '0'flag
	printf("[%+0d]\n", 1);
	printf("[%+0d]\n", -1);
	printf("[%+010d]\n", 1);
	printf("[%+010d]\n", -1);

	printf("[%+0f]\n", 1.0);
	printf("[%+0f]\n", -1.0);
	printf("[%+010f]\n", 1.0);
	printf("[%+010f]\n", -1.0);
	printf("\n");

//13: '(space)'flag + '-'flag
	printf("[% -d]\n", 1);
	printf("[% -d]\n", -1);
	printf("[% -10d]\n", 1);
	printf("[% -10d]\n", -1);

	printf("[% -f]\n", 1.0);
	printf("[% -f]\n", -1.0);
	printf("[% -10f]\n", 1.0);
	printf("[% -10f]\n", -1.0);
	printf("\n");

//14: '(space)'flag + '0'flag
	printf("[% 0d]\n", 1);
	printf("[% 0d]\n", -1);
	printf("[% 010d]\n", 1);
	printf("[% 010d]\n", -1);

	printf("[% 0f]\n", 1.0);
	printf("[% 0f]\n", -1.0);
	printf("[% 010f]\n", 1.0);
	printf("[% 010f]\n", -1.0);
	printf("\n");

//17: '#'flag + '-'flag
	printf("[%#-o]\n", 10);
	printf("[%#-10o]\n", 10);
	printf("\n");

//18: ' #'flag + '0'flag
	printf("[%#0o]\n", 10);
	printf("[%#010o]\n", 10);
	printf("\n");

	return (0);
}
