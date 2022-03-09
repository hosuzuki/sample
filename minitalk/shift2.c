#include <stdio.h>

void printb(unsigned int v) {
  unsigned int mask = (int)1 << (sizeof(v) * CHAR_BIT - 1);
  do putchar(mask & v ? '1' : '0');
  while (mask >>= 1);
}

void putb(unsigned int v) {
	putchar('0'), putchar('b'), printb(v), putchar('\n');
}


static void main(pid_t server_pid, char c)
{
	int	shift;
	int	sig_to_send;

	shift = 7;
	while (0 <= shift)
	{
		if ((c & (0b00000001 << shift)) == 0)
			sig_to_send = SIGUSR1;
		else
			sig_to_send = SIGUSR2;
		if (kill(server_pid, sig_to_send) != 0)
			ft_print_error_and_exit("kill Error\n");
		while (received_signal == 0)
			usleep(100);
		if (received_signal != sig_to_send)
			ft_print_error_and_exit("received or send signal Error\n");
		received_signal = 0;
		shift--;
	}
}

