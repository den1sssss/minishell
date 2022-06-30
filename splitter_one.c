/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:59:28 by dshirely          #+#    #+#             */
/*   Updated: 2022/06/30 14:59:28 by dshirely         ###   ########.fr       */
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

int	space_skip(char *str, int i)
{
	if (!str)
		return (i);
	if (!str[i])
		return (i);
	while (ft_isspace(str[i]) && str[i])
		++i;
	return (i);
}

void	ccont_split(char *str, int *i, t_comlist **main)
{
	int	j;

	if (str[*i] == '\'')
	{
		add_node(main, 7, NULL);
		j = *i + 1;
		*i = squot_ind(str, *i);
		comlist_last(*main)->str = ft_substr(str, j, *i - j);
	}
	else if (str[*i] == '\"')
	{
		add_node(main, 8, NULL);
		j = *i + 1;
		*i = dquot_ind(str, *i);
		comlist_last(*main)->str = ft_substr(str, j, *i - j);
	}
	else
	{
		add_node(main, 9, NULL);
		j = *i;
		*i = skip_to_space(str, *i);
		comlist_last(*main)->str = ft_substr(str, j, *i - j + 1);
	}
}

void	cont_split(char *str, int *i, t_comlist **main)
{
	int	j;

	if (str[*i] == '>')
	{
		if (str[*i + 1] == '>')
		{
			++(*i);
			add_node(main, 3, NULL);
		}
		else
			add_node(main, 2, NULL);
	}
	else if (str[*i] == '|')
		add_node(main, 4, NULL);
	else if (str[*i] == '$')
	{
		if (str[*i + 1] == '?')
			add_node(main, 5, NULL);
		else if (!ft_isspace(str[*i + 1]))
		{
			j = *i;
			add_node(main, 6, NULL);
			*i = skip_to_space(str, *i);
			comlist_last(*main)->str = ft_substr(str, j, *i - j + 1);
		}
	}
	else
		ccont_split(str, i, main);
}

t_comlist	*ms_split(char *str)
{
	t_comlist	*main;
	int			i;

	main = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == '<')
		{
			if (str[i + 1] == '<')
			{
				++i;
				add_node(&main, 1, NULL);
			}
			else
				add_node(&main, 0, NULL);
		}
		else
			cont_split(str, &i, &main);
		++i;
		i = space_skip(str, i);
	}
	return (main);
}