void	ft_ctrlc(int signum)
{
	write(1, "\n", 1);
	prompt();
}

void	ft_exit(int signum)
{
	exit(0);
}