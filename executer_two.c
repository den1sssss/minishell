/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:54:52 by dshirely          #+#    #+#             */
/*   Updated: 2022/06/30 16:40:28 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	checking(char **arr)
{
	char	**paths;
	char	*cur;
	char	*tmp;

	tmp = ft_strdup(*arr);
	paths = get_paths();
	if (paths)
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

int	check_path(char **arr)
{
	int		fd;

	if (!**arr || check_full_path(*arr))
	{
		fd = open(*arr, O_RDONLY);
		if (fd == -1)
			return (1);
		else
			return (close(fd));
	}
	if (checking(arr))
		return (1);
	else
		return (0);
}

void	free_arr(char **arr)
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
	pid = fork();
	if (pid)
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
	}
}

void	fork_execute(char **arr, t_info info)
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
