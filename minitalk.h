/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:41:03 by garibeir          #+#    #+#             */
/*   Updated: 2023/09/10 11:40:37 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./includes/libft/libft.h"
# include "./includes/printf/ft_printf.h"
# include <limits.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Client auxiliary functions

bool	checker_client(int argc, char **argv);
void	string_to_bin(char *str, int pid);
// Server auxiliar functions

char	bin_to_char(char *c, int signum);
// Shared auxiliary functions

void	destroyer(char *str);
void	*xmalloc(size_t size);
char	bin_to_char(char *c, int pid);
int		char_to_bin(char c, int pid);

//Signal handling server
void	sig_handler_server(int signum, siginfo_t *info, void *context);

//signal handling client
void	sig_handler_client(int signum, siginfo_t *info, void *context);
#endif