#include "../minitalk.h"


// Make function to set the sa flags outside to make it look prettier
// checker functions looks a bit not needed
int	main(int argc, char **argv)
{
    pid_t             pid;
    struct sigaction sa;

    pid = ft_atoi(argv[1]);
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.__sigaction_u.__sa_sigaction = &sig_handler_client;
	checker_client(argc);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    string_to_bin(argv[2], pid);
    while (1)
        pause();
	return (0);
}