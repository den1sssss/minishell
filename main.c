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

void	prompt(void)
{
	char	*cwd;
	printf("MS ");
	cwd = getcwd(NULL, 0);
	printf("%s", cwd);
	free(cwd);
}

char	*ft_rl(void)
{
	char	*str;
	char	*buf;
	char	*tmpstr;
	int		tmp;

	buf = (char *)malloc(2);
	if (!buf)
		exit(0);
	buf[1] = 0;
	tmp = read(0, buf, 1);
	str = ft_strdup("");
	while (tmp)
	{
		if (*buf == '\n')
			break ;
		tmpstr = str;
		str = ft_strjoin(str, buf);
		free(tmpstr);
	}
	free(buf);
	return (str);
}

void	ms_loop(void);
{
	char	*str;

	while (1)
	{
		str = ft_rl();
	}
}

int	main(int argc, char **argv, char **envp)
{
	envp_copy(envp);
	signal(SIGINT, ft_ctrlc);
	signal(SIGQUIT, ft_exit);
	ms_loop();
	return (0);
}