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
	g_status = 1;
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
int exec_builtin(t_arguments arg, t_list *env_list)
{
    int				index;
	const t_builtin	builtins[] = {{"echo", &echo},{"cd", &cd},\
    {"pwd", &pwd},{"export", &export},{"unset", &unset},\
    {"env", &env},{"exit", &exitt}};

	index = 0;
	while (index < 7)
	{
		if (!ft_strcmp(builtins[index].func_name, *(arg.argv)))
		{
			arg.argv++;
			if (builtins[index].func(&arg, env_list))
				printerror(--arg.argv);
			return (1);
		}
		index++;
	}
	return (0);
}
//check_path
int check_path(char **command, t_list *env_list)
{

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
void check_exit_status(int status)
{
	if (WIFEXITED(status))
		g_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_status = WTERMSIG(status) + 128;

}
char **list_to_arr(t_list *list)
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
int start(t_arguments *arg,t_list *env_list)
{
    pid_t pid;
    int status;
    char **env;

    errno = 0;
	g_status = 0;
	if (exec_builtin(*arg, env_list))
		return ;
	env = list_to_arr(env_list);
	if ((pid = fork()))
	{
		wait(&status);
		check_exit_status(status);
		free_arr(env);
		free(env);
	}
	else if (pid < 0)
		exit(EXIT_FAILURE);
	else
	{
		//
		if (!check_path(arg->argv, env_list))
			execve(*arg->argv, arg->argv, env);
		exit_with_error(arg);
	}
}
//
int forking(t_arguments arg, t_list *env_list)
{
    if (fork() == 0)
	{
		dup2(arg.fds.std_write, STDOUT_FILENO);
		start(&arg, env_list);
		close(arg.fds.std_read);
		close(STDOUT_FILENO);
		exit(127);
	}
	else
	{
		dup2(arg.fds.std_read, STDIN_FILENO);
		close(arg.fds.std_write);
		wait(0);
		close(arg.fds.std_read);
	}
}
//
int is_fork(t_fds fd)
{
    return ((fd.std_write != 3 || fd.std_read != 4) && fd.fork == 1 && fd.back_redirect == 0);
}
//

void minishell(char *input,t_list *env_list)
{
    t_arguments arguments;

    while(*input)
    {
        if(*input==';')
            input++;
        else
        {
            arginit(&arguments);
            arguments.argv=parse(&input,env_list,&arguments.fds);
            //----------------
            if(arguments.argv)
            {
                if(is_fork(arguments.fds))
                    forking(arguments,env_list);
                else
                    start(&arguments,env_list);
            }
            //-------------------------
			free_arr(arguments.argv);
			free(arguments.argv);
        }
    }
}

int main(int argc,char **argv, char **env)
{
    char **str;
    minishell('ls',*env);
}