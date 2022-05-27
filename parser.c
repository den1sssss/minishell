/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblackth <lblackth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:40:37 by lblackth          #+#    #+#             */
/*   Updated: 2022/05/27 22:13:08 by lblackth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

char	**arr_join(char **arr_f, char **arr_s)
{
	int		i;
	int		j;
	char	**arr;

	i = 0;
	j = 0;
	while (arr_f[i])
		++i;
	while (arr_s[j])
		++j;
	arr = (char **)malloc(i + j + 1);
	i = 0;
	j = 0;
	while (arr_f[i])
	{
		arr[i] = arr_f[i];
		++i;
	}
	while (arr_s[j])
	{
		arr[j + i] = arr_s[j];
		++j;
	}
	arr[j + i] = NULL;
	return (arr);
}

int	ft_isspace(int c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (1);
	return (0);
}

t_comlist	*comlist_last(t_comlist *start)
{
	while (start->next)
		start = start->next;
	return (start);
}

void	list_insert(t_comlist *tek, int type)
{
	t_comlist	*tmp;
	t_comlist	*new;

	new = (t_comlist *)malloc(sizeof(t_comlist));
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
	t_comlist	*tmp;
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
	while (ft_isspace(str[i]) && str[i])
		++i;
	return (i);
}

int	skip_to_space(char *str, int i)
{
	while (!ft_isspace(str[i + 1]) && str[i])
		++i;
	return (i);
}

void	str_func(t_comlist **tek)
{
	while (str_check(*tek)) {;}
	*tek = comlist_last(*tek);
}

void	ccont_split(char *str, int *i, t_comlist *tek)
{
	int	j;

	if (str[*i] == '\'')
	{
		tek->type = 7;
		j = *i + 1;
		*i = squot_ind(str, *i);
		tek->str = ft_substr(str, j, *i - j);
	}
	else if (str[*i] == '\"')
	{
		tek->type = 8;
		j = *i + 1;
		*i = dquot_ind(str, *i);
		tek->str = ft_substr(str, j, *i - j);
	}
	else
	{
		tek->type = 9;
		j = *i;
		*i = skip_to_space(str, *i);
		tek->str = ft_substr(str, j, *i - j + 1);
	}
}

void	cont_split(char *str, int *i, t_comlist *tek)
{
	int	j;

	if (str[*i] == '>')
	{
		tek->type = 2;
		if (str[*i + 1] == '>')
		{
			++(*i);
			tek->type++;
		}
	}
	else if (str[*i] == '|')
		tek->type = 4;
	else if (str[*i] == '$')
	{
		tek->type = 5;
		if (str[*i + 1] == '?')
			++(*i);
		else if (!ft_isspace(str[*i + 1]))
		{
			j = *i;
			tek->type++;
			*i = skip_to_space(str, *i);
			tek->str = ft_substr(str, j, *i - j + 1);
		}
	}
	else
		ccont_split(str, i, tek);
}

t_comlist	*ms_split(char *str)
{
	t_comlist	*main;
	t_comlist	*tek;
	int			i;

	main = (t_comlist *)malloc(sizeof(t_comlist));
	main->next = NULL;
	tek = main;
	i = 0;
	while (str[i])
	{
		if (str[i] == '<')
		{
			tek->type = 0;
			if (str[i + 1] == '<')
			{
				++i;
				tek->type++;
			}
		}
		else
			cont_split(str, &i, tek);
		++i;
		i = space_skip(str, i);
		tek = (t_comlist *)malloc(sizeof(t_comlist));
		comlist_last(main)->next = tek;
	}
	return (main);
}
