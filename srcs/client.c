/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:48:00 by garibeir          #+#    #+#             */
/*   Updated: 2023/09/10 11:17:26 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

// Main function sets the signal handling settings for SIGUSR1 and SIGUSR2
// Checks for validity of arguments 
// sends string through binary to a client using its pid and sending signals
int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	s_sa;

	checker_client(argc, argv);
	pid = ft_atoi(argv[1]);
	sigemptyset(&s_sa.sa_mask);
	s_sa.sa_flags = SA_RESTART | SA_SIGINFO;
	s_sa.sa_sigaction = &sig_handler_client;
	sigaction(SIGUSR1, &s_sa, NULL);
	sigaction(SIGUSR2, &s_sa, NULL);
	string_to_bin(argv[2], pid);
	while (1)
		pause();
	return (0);
}

//convers character to its binary form and stores it in an int
int	char_to_bin(char c, int pid)
{
	int	i;

	i = CHAR_BIT;
	while (i--)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				destroyer("Error\n(Did you input the right pid?)");
		}
		else if (kill(pid, SIGUSR2) == -1)
			destroyer("Error\n(Did you input the right pid?)");
		usleep(500);
	}
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

//Checks if arguments are valid
bool	checker_client(int argc, char **argv)
{
	size_t	i;

	i = 0;
	if (argc < 3)
		destroyer("Not enough arguments");
	if (argc > 3)
		destroyer("Too many arguments");
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
