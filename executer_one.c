/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:59:06 by dshirely          #+#    #+#             */
/*   Updated: 2022/06/30 14:59:06 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

int	builtins(char **arr)
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
		fd = open(arr, O_RDONLY);
		if (fd != -1)
			break ;
		free(arr);
		arr = NULL;
	}
	if (fd != -1)
		close(fd);
	return (arr);
}

char	**get_paths(void)
{
	t_envlist	*tmp;

	tmp = g_env_list;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, "PATH"))
			return (ft_split(tmp->val, ':'));
		tmp = tmp->next;
	}
	return (NULL);
}

int	is_fork(t_info info)
{
	return ((info.std_w != 3 || info.std_r != 4) && info.fork);
}
