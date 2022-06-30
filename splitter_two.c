/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:15:37 by dshirely          #+#    #+#             */
/*   Updated: 2022/06/30 20:09:09 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_to_space(char *str, int i)
{
	while (!ft_isspace(str[i + 1]) && str[i + 1])
		++i;
	return (i);
}

int	dquot_ind(char *str, int i)
{
	++i;
	while (str[i] && (str[i] != '\"' || str[i - 1] == '\\'))
		++i;
	if (!str[i])
		return (0);
	return (i);
}

int	squot_ind(char *str, int i)
{
	++i;
	while (str[i] && (str[i] != '\'' || str[i - 1] == '\\'))
		++i;
	if (!str[i])
		return (0);
	return (i);
}

t_comlist	*comlist_last(t_comlist *start)
{
	if (!start->next)
		return (NULL);
	while (start->next)
		start = start->next;
	return (start);
}

void	add_node(t_comlist **start, int type, char *str)
{
	t_comlist	*new;

	new = (t_comlist *)malloc(sizeof(t_comlist *));
	new->next = NULL;
	new->str = str;
	new->type = type;
	if (!*start)
		*start = new;
	else
		comlist_last(*start)->next = new;
}
