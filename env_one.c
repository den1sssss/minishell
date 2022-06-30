/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:59:03 by dshirely          #+#    #+#             */
/*   Updated: 2022/06/30 14:59:03 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_envlist	*env_to_list(char **envp)
{
	char		**arr;
	t_envlist	*start;
	t_envlist	*tmp;
	int			i;

	i = 0;
	arr = ft_split(envp[i], '=');
	start = new_envlist(arr);
	free(arr);
	tmp = start;
	++i;
	while (envp[i])
	{
		arr = ft_split(envp[i], '=');
		tmp->next = new_envlist(arr);
		free(arr);
		tmp = tmp->next;
		++i;
	}
	return (start);
}

int	sizing(t_envlist *env_list)
{
	int			size;
	t_envlist	*tmp_list;

	tmp_list = env_list;
	size = 0;
	while (tmp_list)
	{	
		++size;
		tmp_list = tmp_list->next;
	}
	return (size);
}

char	**list_to_env(t_envlist *env_list)
{
	char		**arr;
	char		*tmp;
	int			i;

	arr = (char **)malloc(sizeof(char *) * (sizing(env_list) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (env_list)
	{
		tmp = ft_strjoin(env_list->key, "=");
		arr[i] = ft_strjoin(tmp, env_list->val);
		free(tmp);
		++i;
		env_list = env_list->next;
	}
	arr[i] = NULL;
	return (arr);
}
