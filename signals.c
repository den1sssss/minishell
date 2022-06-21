#include "minishell.h"

void	ft_ctrlc(int signum)
{
	(void)signum;
	write(1, "\n", 1);
	prompt();
}
