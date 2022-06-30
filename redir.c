/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:57:46 by dshirely          #+#    #+#             */
/*   Updated: 2022/06/30 15:58:07 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	b_redir(t_comlist *list, t_info *info)
{
	int			fd;
	t_comlist	*tmp;

	fd = open(list->next->next->str, O_RDONLY, 0644);
	info->std_r = fd;
	tmp = list->next;
	list->next = list->next->next->next;
	free(tmp->next->str);
	free(tmp->next);
	free(tmp);
}

void	f_redir(t_comlist *list, t_info *info)
{
	int			fd;
	t_comlist	*tmp;

	fd = open(list->next->next->str, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	info->std_w = fd;
	tmp = list->next;
	list->next = list->next->next->next;
	free(tmp->next->str);
	free(tmp->next);
	free(tmp);
}

void	d_f_redir(t_comlist *list, t_info *info)
{
	int			fd;
	t_comlist	*tmp;

	fd = open(list->next->next->str, O_CREAT | O_APPEND | O_WRONLY, 0644);
	info->std_w = fd;
	tmp = list->next;
	list->next = list->next->next->next;
	free(tmp->next->str);
	free(tmp->next);
	free(tmp);
}
