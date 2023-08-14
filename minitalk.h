#ifndef MINITALK_H
    #define MINITALK_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <signal.h>
#include "./includes/libft/libft.h"
#include "./includes/getnextline/get_next_line.h"
#include "./includes/printf/ft_printf.h"


// Client auxiliary functions
bool	checker_client(int argc);
void	string_to_bin(char *str, int pid);
// Server auxiliar functions
// Shared auxiliary functions
void	destroyer(void);
void	*xmalloc(size_t size);
char	bin_to_char(char *c, int pid);
int	    char_to_bin(char c, int pid);

//Signal handling server
void sig_handler_server(int signum, siginfo_t* info, void *context);
//signal handling client
void sig_handler_client(int signum, siginfo_t* info, void *context);
#endif