#include "../minitalk.h"


// Aux functions

//Checks if arguments are valid
bool	checker(int argc, char **argv)
{
	if (argc != 3)
		destroyer();
}

//Exits the program gracefully
void	destroyer(void)
{
	ft_printf("Something went wrong and the program ended.");
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

//Handles signals
void sig_hangler(int signum, t_siginfo* info, void *context)
{
	
}

//convers character to its binary form and stores it in an int
int	char_to_bin(char c, int pid)
{

}

//converts binary into its char represetantion
char	bin_to_char(int c, int pid)
{

}