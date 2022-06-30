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
		j = *i + 1;
		*i = squot_ind(str, *i);
		add_node(main, 7, ft_substr(str, j, *i - j));
	}
	else if (str[*i] == '\"')
	{
		j = *i + 1;
		*i = dquot_ind(str, *i);
		add_node(main, 8, ft_substr(str, j, *i - j));
	}
	else
	{
		j = *i;
		*i = skip_to_space(str, *i);
		add_node(main, 9, ft_substr(str, j, *i - j + 1));
	}
}

void	cont_split_plus(char *str, int *i, t_comlist **main)
{
	int	j;

	if (str[*i] == '|')
		add_node(main, 4, NULL);
	else if (str[*i] == '$')
	{
		if (str[*i + 1] == '?')
			add_node(main, 5, NULL);
		else if (!ft_isspace(str[*i + 1]))
		{
			j = *i;
			*i = skip_to_space(str, *i);
			add_node(main, 6, ft_substr(str, j, *i - j + 1));
		}
	}
	else
		ccont_split(str, i, main);
}

void	cont_split(char *str, int *i, t_comlist **main)
{
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
	else
		cont_split_plus(str, i, main);
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
