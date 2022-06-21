#include "minishell.h"

void	ft_ctrlc(int signum)
{
	(void)signum;
	printf("\n");
	ms_loop();
}
