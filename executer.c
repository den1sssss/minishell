#include "minishell.h"

int ft_strcmp(const char *str1, const char *str2)
{
    while(*str1)
    {
        if(*str1!=*str2)
            return(*str1-*str2);
        str1++;
        str2++;
    }
    return(*str1-*str2);
}
int builtins(char **arr)
{
	int	flag;

	flag = 1;
	if (!ft_strcmp("echo", *arr))
		ms_echo(arr);
	else if (!ft_strcmp("cd", *arr))
		ms_cd(arr);
	else if (!ft_strcmp("pwd", *arr))
		ms_pwd();
	else if (!ft_strcmp("export", *arr))
		ms_export(arr);
	else if (!ft_strcmp("unset", *arr))
		ms_unset(arr);
	else if (!ft_strcmp("env", *arr))
		ms_env();
	else if (!ft_strcmp("exit", *arr))
		ms_exit(arr);
	else
		flag = 0;
	return (flag);
}

char	*get_current_path(char **paths, char *cur, char *arr)
{
	int	fd;

	fd = 0;
	free(arr);
	while (*paths)
	{
		arr = ft_strjoin(*paths++, cur);
		if ((fd = open(arr, O_RDONLY)) != -1)
			break ;
		free(arr);
		arr = NULL;
	}
	if (fd != -1)
		close(fd);
	return (arr);
}
char **get_paths(void)
{
	t_envlist	*tmp;

	tmp = g_env_list;
	while(tmp)
	{
		if(!ft_strcmp(tmp->key,"PATH"))
			return (ft_split(tmp->val, ':'));
		tmp=tmp->next;
	}
	return(NULL);
}
int		check_full_path(const char *s)
{
		return (!ft_strncmp("../", s, 3) ||
			!ft_strncmp("/", s, 1) || !ft_strncmp("./", s, 2));
}
int check_path(char **arr)
{
	char	*tmp;
	char	*cur;
	char	**paths;
	int		fd;

	if (!**arr || check_full_path(*arr))
	{
		fd = open(*arr, O_RDONLY);
		if(fd == -1)
			return(1);
		else
			return(close(fd));
	}
	tmp = ft_strdup(*arr);
	if ((paths = get_paths()))
	{
		cur = ft_strjoin("/", tmp);
		*arr = get_current_path(paths, cur, *arr);
		free_arr(paths);
		free(cur);
	}
	if (*arr == NULL)
	{
		*arr = tmp;
		return (1);
	}
	free(tmp);
	return (0);
}

void free_arr(char **arr)
{
	char	*tmp;

	if (!arr)
		return ;
	while (*arr)
	{
		tmp = *arr;
		free(tmp);
		++arr;
	}
}

void	execute(char **arr)
{
    pid_t	pid;
    int		status;
    char	**env;

	if (builtins(arr))
		return ;
	env = list_to_env(g_env_list);
	if ((pid = fork()))
	{
		wait(&status);
		free_arr(env);
		free(env);
	}
	else if (pid < 0)
		exit(1);
	else
	{
		if (!check_path(arr))
			execve(*arr, arr, env);
		exit(2);
		// exit_with_error(arg);
	}
}

void fork_execute(char **arr, t_info info)
{
    if (fork() == 0)
	{
		dup2(info.std_w, STDOUT_FILENO);
		execute(arr);
		close(info.std_r);
		close(STDOUT_FILENO);
		exit(0);
	}
	else
	{
		dup2(info.std_r, STDIN_FILENO);
		close(info.std_w);
		wait(0);
		close(info.std_r);
	}
}

int is_fork(t_info info)
{
    return ((info.std_w != 3 || info.std_r != 4) && info.fork);
}
