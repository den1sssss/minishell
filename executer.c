#include "minishell.h"

//exec_builtin
void printerror(char **arg)
{
    char	*error;
	ft_putstr_fd("\e[31m\e[1mminishell: ", STDERR_FILENO);
	while (arg && *arg)
	{
		ft_putstr_fd(*arg++, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	error = strerror(errno);
	if (errno)
		ft_putendl_fd(error, STDERR_FILENO);
	else
		ft_putendl_fd("command not found", STDERR_FILENO);
	ft_putstr_fd("\e[0m", STDERR_FILENO);
}

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
// int exec_builtin(t_arguments arg, t_list *env_list)
// {
//     int				index;
// 	const t_builtin	builtins[] = {{"echo", &echo},{"cd", &cd},\
//     {"pwd", &pwd},{"export", &export},{"unset", &unset},\
//     {"env", &env},{"exit", &exitt}};

// 	index = 0;
// 	while (index < 7)
// 	{
// 		if (!ft_strcmp(builtins[index].func_name, *(arg.argv)))
// 		{
// 			arg.argv++;
// 			if (builtins[index].func(&arg, env_list))
// 				printerror(--arg.argv);
// 			return (1);
// 		}
// 		index++;
// 	}
// 	return (0);
// }
//check_path
char	*get_current_path(char **paths, char *current_command, char *command)
{
	int		fd;

	fd = 0;
	free(command);
	while (*paths)
	{
		command = ft_strjoin(*paths++, current_command);
		if ((fd = open(command, O_RDONLY)) != -1)
			break ;
		free(command);
		command = NULL;
	}
	if (fd != -1)
		close(fd);
	return (command);
}
char **get_paths(t_list *list)
{
	t_env *env;
	while(list)
	{
		env=list->content;
		if(!ft_strcmp(env->key,"PATH"))
			return (ft_split(env->value, ':'));
		list=list->next;
	}
	return(NULL);
}
int		check_full_path(const char *s)
{
		return (!ft_strncmp("../", s, 3) ||
			!ft_strncmp("/", s, 1) || !ft_strncmp("./", s, 2));
}
int check_path(char **command, t_list *env_list)
{
	char		*temp_command;
	char		*current_command;
	char		**paths;
	int			fd;

	if (!**command || check_full_path(*command))
	{
		fd = open(*command, O_RDONLY);
		if(fd == -1)
			return(1);
		else
			return(close(fd));
	}
	temp_command = ft_strdup(*command);
	if ((paths = get_paths(env_list)))
	{
		current_command = ft_strjoin("/", temp_command);
		*command = get_current_path(paths, current_command, *command);
		free_arr(paths);
		free(paths);
		free(current_command);
	}
	if (*command == NULL)
	{
		errno = 0;
		*command = temp_command;
		return (1);
	}
	free(temp_command);
	return (0);
}
//
void free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

char	**list_to_arr(t_list *list)
{
	char	*temp;
	char	**array;
	t_env	*env;
	int		size;
	int		i;

	size = ft_lstsize(list);
	i = 0;
	if ((array = (char**)malloc(sizeof(char*) * (size + 1))) == NULL)
		return (NULL);
	while (list)
	{
		env = list->content;
		if (env->value && *env->value)
		{
			temp = ft_strjoin(env->key, "=");
			array[i++] = ft_strjoin(temp, env->value);
			free(temp);
		}
		list = list->next;
	}
	array[i] = NULL;
	return (array);
}
void	execute(char **arr, t_info info)
{
    pid_t pid;
    int status;
    char **env;

	// if (exec_builtin(*arg, env_list))
	// 	return ;
	// env = list_to_arr(env_list);
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
		//
		if (!check_path(arr, env_list))
			execve(*arr, arr, g_envp);
		exit(0);
	}
}
//
void fork_execute(char **arr, t_info info)
{
    if (fork() == 0)
	{
		dup2(info.std_w, STDOUT_FILENO);
		execute(arr, info);
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
//
int is_fork(t_info info)
{
    return ((info.std_w != 3 || info.std_r != 4) && info.fork);
}
//
