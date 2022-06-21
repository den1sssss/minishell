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

void	ms_loop(void)
{
	char		*str;
	char		*tmp;
	t_comlist	*list;

	tmp = prompt();
	str = readline(tmp);
	free(tmp);
	while (1)
	{
		list = ms_split(str);
		printf("\n%p   %p\n", list, list->next);
		str = readline(prompt());
		while (list)
		{
			if (list->type < 7)
				printf("%d\n", list->type);
			else
				printf("%d %s\n", list->type, list->str);
			list = list->next;
		}
		str = readline(prompt());
	}
	printf("\n121\n");
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
