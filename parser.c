/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:59:23 by dshirely          #+#    #+#             */
/*   Updated: 2022/06/30 14:59:23 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	info_init(t_info *info)
{
	info->fork = 0;
	info->std_r = 4;
	info->std_w = 3;
}

char	**list_to_arr(t_comlist *list)
{
	int			i;
	t_comlist	*tmp;
	char		**arr;

	i = 0;
	tmp = list;
	while (tmp && tmp->type != 4)
	{
		i++;
		tmp = tmp->next;
	}
	arr = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	tmp = list;
	while (tmp && tmp->type != 4)
	{
		arr[i] = tmp->str;
		i++;
		tmp = tmp->next;
	}
	arr[i] = NULL;
	return (arr);
}

void	set_pipe(t_info *info)
{
	int	fd[2];

	pipe(fd);
	info->std_w = fd[1];
	info->std_r = fd[0];
	info->fork = 1;
}

void	parsing(t_comlist *list, t_info *info)
{
	while (list->next)
	{
		if (list->next->type == 4)
			break ;
		else if (!list->next->type)
		{
			b_redir(list, info);
			continue ;
		}
		else if (list->next->type == 2)
		{
			f_redir(list, info);
			continue ;
		}
		else if (list->next->type == 3)
		{
			d_f_redir(list, info);
			continue ;
		}
		list = list->next;
		if (!list)
			break ;
	}
}

char	**parse(t_comlist *list, t_info *info)
{
	t_comlist	*start;
	char		**arr;

	start = list;
	parsing(list, info);
	arr = list_to_arr(start);
	if (list && list->next && list->next->type == 4)
		set_pipe(info);
	return (arr);
}
