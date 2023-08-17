#include "../minitalk.h"


// Aux functions

//Checks if arguments are valid
bool	checker_client(int argc, char **argv)
{
	size_t	i;

	i = 0;
	if (argc < 3)
		destroyer("Not enough arguments");
	while (i < ft_strlen(argv[1]))
		{
			if (!ft_isdigit(argv[1][i]))
				destroyer("Invalid PID");
			i++;
		}
	i = 0;
	if (!argv[2][0])
		destroyer("Empty string");
	return (true);
}

//Exits the program gracefully
void	destroyer(char *str)
{
	ft_printf("%s\n", str);
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
	if (signum == SIGUSR2)
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

	(void)context;
	if(!client_pid)
		client_pid = s_info->si_pid;
	bin_to_char(&c, signum);
	if (++i == CHAR_BIT)
	{
		i = 0;
		if (!c)
		{
			if (kill(client_pid, SIGUSR2) == -1)
				destroyer("Error sending feedback signal to client");
			client_pid = 0;
			ft_printf("\n");
			return ;
		}
		ft_printf("%c", c);
		c = 0;
	}
	if(kill(client_pid, SIGUSR1) == -1)
		destroyer("Error sending feedback signal to client");
}
//convers character to its binary form and stores it in an int
int	char_to_bin(char c, int pid)
{
	int	i;

	i = CHAR_BIT;
	while( i--)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				destroyer("Error sending signal to server\n(Did you input the right pid?)");
		}
		else
			if (kill(pid, SIGUSR2) == -1)
				destroyer("Error sending signal to server\n(Did you input the right pid?)");
		usleep(500);
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
		usleep(500);
	}
	char_to_bin('\0', pid);
}