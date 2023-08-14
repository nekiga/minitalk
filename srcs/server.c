#include "../minitalk.h"

int	main(void)
{
	// needs to display its own PID at startup
	pid_t pid;
	struct sigaction s_sa;

	pid = getpid();
	sigemptyset(&s_sa.sa_mask);
    s_sa.sa_flags = SA_RESTART | SA_SIGINFO;
	s_sa.__sigaction_u.__sa_sigaction = sig_handler_server;
	
	sigaction(SIGUSR1, &s_sa, NULL);
	sigaction(SIGUSR2, &s_sa, NULL);
	ft_printf("Server pid: %i\n", pid);
	while (1)
		pause();
	return (0);
}