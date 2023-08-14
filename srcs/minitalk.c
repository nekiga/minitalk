#include "../minitalk.h"


// Aux functions

//Checks if arguments are valid
bool	checker_client(int argc)
{
	if (argc != 3)
		destroyer();
	return (true);
}

//Exits the program gracefully
void	destroyer(void)
{
	ft_printf("Something went wrong and the program ended.");
	exit(1);
}

// depracated
/* void	init_sigaction_struct(int option)
{
	struct sigaction sa;

	sigemptyset(&sa.sa_mask);
	if(option == 0)
		sa.__sigaction_u.__sa_handler = SIG_IGN;
	else
	{
		sa.sa_flags = SA_RESTART | SA_SIGINFO;
		sa.__sigaction_u.__sa_sigaction = sig_handler;
	}
	sigaction(SIGINT, &sa, NULL); */

//cmalloc with built in protection from null pointers
void	*xmalloc(size_t size)
{
	void	*result;

	result = malloc(size);
	if (result == NULL)
		exit(1);
	ft_bzero(result, size);
	return (result);
}

//Handles signals for client
 void sig_handler_client(int signum, siginfo_t* s_info, void *context)
{
	static	int	bits_read;
	
	(void)s_info;
	(void)context;
	if (signum == SIGUSR1)
		bits_read++; 
	else if (signum == SIGUSR2)
	{
		ft_printf("%d bytes received\n", bits_read / 8); 
		exit(0);
	}
} 

void sig_handler_server(int signum, siginfo_t* s_info, void *context)
{
	static int	client_pid;
	static int	i;
	static char	c;

	printf("sighandlersegr\n");
	(void)context;
	if(!client_pid)
		client_pid = s_info->si_pid;
	bin_to_char(&c, signum);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(client_pid, SIGUSR1);
			client_pid = 0;
			printf("going here\n");
		}
		c = 0;
		ft_printf("%c", c);
	}
	kill(client_pid, SIGUSR2);
}
//convers character to its binary form and stores it in an int
int	char_to_bin(char c, int pid)
{
	int	i;

	i = 7;
	while( i != 0)
	{
		if ((c << i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(100);
	}
	return (0);
}

//converts binary into its char represetantion
char	bin_to_char(char *c, int signum)
{
	if (signum == SIGUSR1)
		*c = (*c << 1) | 1;
	else if (signum == SIGUSR2)
		*c <<= 1;
	return (0);
}

// converts string into binary
void	string_to_bin(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		char_to_bin(str[i], pid);
		i++;
	}
}