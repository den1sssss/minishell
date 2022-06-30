/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:58:59 by dshirely          #+#    #+#             */
/*   Updated: 2022/06/30 14:58:59 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exp_print(void)
{
	t_envlist	*tmp;

	tmp = g_env_list;
	while (tmp)
	{
		write(1, "declare -x ", 11);
		ft_putstr_fd(tmp->key, 1);
		if (tmp->val)
		{
			write(1, "=\"", 2);
			ft_putstr_fd(tmp->val, 1);
			write(1, "\"\n", 2);
		}
		else
			write(1, "\n", 1);
		tmp = tmp->next;
	}
}

int	is_valid(char *key)
{
	if (*key == '0' || ft_atoi(key))
		return (0);
	while (*key)
	{
		if (!ft_isalnum(*key) && *key != '_')
			return (0);
		key++;
	}
	return (1);
}

void	exporting(char **arr)
{
	char	**key_val;

	while (*arr)
	{
		key_val = ft_split(*arr, '=');
		if (!is_valid(key_val[0]))
			exp_err(*arr);
		else
		{
			if (!key_val[1])
			{
				if (ft_strchr(*arr, '='))
					key_val[1] = ft_strdup("");
			}
			if (!g_env_list)
				g_env_list = new_envlist(key_val);
			else
				envlist_last(g_env_list)->next = new_envlist(key_val);
			free(key_val);
		}
		++arr;
	}
}

int	ms_export(char **arr)
{
	++arr;
	if (!(*arr))
		exp_print();
	else
		exporting(arr);
	return (errno);
}

void	ms_env(void)
{
	t_envlist	*tmp;

	tmp = g_env_list;
	while (tmp)
	{
		if (tmp->val)
		{
			ft_putstr_fd(tmp->key, 1);
			write(1, "=", 1);
			ft_putstr_fd(tmp->val, 1);
			write(1, "\n", 1);
		}
		tmp = tmp->next;
	}
}
