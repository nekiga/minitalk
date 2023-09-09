/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:48:00 by garibeir          #+#    #+#             */
/*   Updated: 2023/09/09 15:44:59 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

// Make function to set the sa flags outside to make it look prettier
// checker functions looks a bit not needed
int	main(int argc, char **argv)
{
	pid_t pid;
	struct sigaction s_sa;

	checker_client(argc, argv);
	pid = ft_atoi(argv[1]);
	sigemptyset(&s_sa.sa_mask);
	s_sa.sa_flags = SA_RESTART | SA_SIGINFO;
	s_sa.sig_handler = &sig_handler_client;
	sigaction(SIGUSR1, &s_sa, NULL);
	sigaction(SIGUSR2, &s_sa, NULL);
	string_to_bin(argv[2], pid);
	while (1)
		pause();
	return (0);
}