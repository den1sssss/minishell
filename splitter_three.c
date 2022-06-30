/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:43:21 by dshirely          #+#    #+#             */
/*   Updated: 2022/06/30 20:45:46 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	list_insert(t_comlist *tek, int type)
{
	t_comlist	*tmp;
	t_comlist	*new;

	new = (t_comlist *)malloc(sizeof(t_comlist));
	new->type = type;
	tmp = tek->next;
	tek->next = new;
	new->next = tmp;
}

void	micro_split(t_comlist *tek, int i, int type)
{
	char	*tmp;
	int		len;

	tmp = tek->str;
	len = ft_strlen(tmp);
	tek->str = ft_substr(tmp, 0, len - i);
	free(tmp);
	list_insert(tek, type);
}

int	str_check(t_comlist *tek)
{
	int			len;

	len = ft_strlen(tek->str);
	if (tek->str[len - 1] == '|')
		micro_split(tek, 1, 4);
	else if (tek->str[len - 1] == '>')
	{
		if (tek->str[len - 2] == '>')
			micro_split(tek, 2, 3);
		else
			micro_split(tek, 1, 2);
	}
	else
		return (0);
	return (1);
}
