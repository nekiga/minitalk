#ifndef MINITALK_H
    #define MINITALK_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include "./includes/libft/libft.h"
#include "./includes/getnextline/get_next_line.h"
#include "./includes/printf/ft_printf.h"


typedef struct s_siginfo
{
    
} t_siginfo;

// Aux functions
bool	checker(int argc, char **argv);
void	destroyer(void);
void	*xmalloc(size_t size);


#endif