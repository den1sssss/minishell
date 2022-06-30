/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_two.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:22:24 by dshirely          #+#    #+#             */
/*   Updated: 2022/06/30 16:22:43 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_val(char *str)
{
	t_envlist	*envlist;

	envlist = g_env_list;
	while (envlist)
	{
		if (!ft_strcmp(envlist->key, str))
			return (envlist->val);
		envlist = envlist->next;
	}
	return (NULL);
}

t_envlist	*new_envlist(char **arr)
{
	t_envlist	*new;

	new = (t_envlist *)malloc(sizeof(t_envlist));
	new->key = arr[0];
	new->val = arr[1];
	new->next = NULL;
	return (new);
}

t_envlist	*envlist_last(t_envlist *envlist)
{
	t_envlist	*tmp;

	tmp = envlist;
	if (!tmp)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
