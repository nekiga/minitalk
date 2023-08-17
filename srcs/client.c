#include "../minitalk.h"


// Make function to set the sa flags outside to make it look prettier
// checker functions looks a bit not needed
int	main(int argc, char **argv)
{
    pid_t             pid;
    struct sigaction s_sa;

	checker_client(argc, argv);
    pid = ft_atoi(argv[1]);
    sigemptyset(&s_sa.sa_mask);
    s_sa.sa_flags = SA_RESTART | SA_SIGINFO;
	s_sa.__sigaction_u.__sa_sigaction = &sig_handler_client;
    sigaction(SIGUSR1, &s_sa, NULL);
    sigaction(SIGUSR2, &s_sa, NULL);
    string_to_bin(argv[2], pid);
    while (1)
        pause();
	return (0);
}