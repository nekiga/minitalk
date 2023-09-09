/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:48:08 by garibeir          #+#    #+#             */
/*   Updated: 2023/09/09 13:53:47 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	s_sa;

	(void)argv;
	pid = getpid();
	if (argc != 1)
		destroyer("Too many arguments");
	sigemptyset(&s_sa.sa_mask);
	s_sa.sa_flags = SA_RESTART | SA_SIGINFO;
	s_sa.sigaction_u = &sig_handler_server;
	sigaction(SIGUSR1, &s_sa, NULL);
	sigaction(SIGUSR2, &s_sa, NULL);
	ft_printf("Server pid: %i\n", pid);
	while (1)
		pause();
	return (0);
}