#include "minishell.h"

void	envp_copy(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		++i;
	g_envp = (char **)malloc(sizeof(char *) * i + 1);
	if (!g_envp)
	{
		printf("malloc error");
		exit(0);
	}
	i = 0;
	while (envp[i])
	{
		g_envp[i] = ft_strdup(envp[i]);
		if (!g_envp[i])
		{
			printf("malloc error");
			exit(0);
		}
		i++;
	}
	g_envp[i] = NULL;
}

char	*prompt(void)
{
	char	*cwd;
	char	*str;
	char	*tmp;

	cwd = getcwd(NULL, 0);
	tmp = cwd;
	cwd = ft_strjoin(cwd, " ");
	free(tmp);
	str = ft_strjoin("MS ", cwd);
	free(cwd);
	return (str);
}

t_comlist	*skip_to_pipe(t_comlist *list)
{
	t_comlist	*tmp;

	while (list && list->type != 4)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
	if (list->type == 4)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
	return (list);
}

void	ms_loop(void)
{
	char		*str;
	char		*tmp;
	t_comlist	*list;

	while (1)
	{
		signal(SIGINT, ft_ctrlc);
		tmp = prompt();
		str = readline(tmp);
		free(tmp);
		list = ms_split(str);
		while (list)
		{
			parse_exec(list);
			list = skip_to_pipe(list);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	envp_copy(envp);
	signal(SIGINT, ft_ctrlc);
	ms_loop();
	return (0);
}
