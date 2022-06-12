#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include "libft/libft.h"

char	**g_envp;

void	envp_copy(char **envp);
void	prompt(void);
int		ft_in(char c, char *str);
void	ft_ctrlc(int signum);
void	ft_exit(int signum);

#endif