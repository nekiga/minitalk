/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:48:04 by garibeir          #+#    #+#             */
/*   Updated: 2023/09/10 14:13:18 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

// Aux functions
//Exits the program gracefully
void	destroyer(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

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
void	sig_handler_client(int signum, siginfo_t *s_info, void *context)
{
	static int	bits_read;

	(void)s_info;
	(void)context;
	if (signum == SIGUSR1)
		bits_read++;
	if (signum == SIGUSR2)
	{
		ft_printf("\nMessage sent correctly. %d bytes received\n", bits_read / 8);
		exit(0);
	}
}

//Handles signals for server
void	sig_handler_server(int signum, siginfo_t *s_info, void *context)
{
	static int	client_pid;
	static int	i;
	static char	c;

	(void)context;
	if (!client_pid)
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
	if (kill(client_pid, SIGUSR1) == -1)
		destroyer("Error sending feedback signal to client");
}

//converts binary into its char representation
char	bin_to_char(char *c, int signum)
{
	if (signum == SIGUSR1)
		*c = (*c << 1) | 1;
	else if (signum == SIGUSR2)
		*c <<= 1;
	return (0);
}
