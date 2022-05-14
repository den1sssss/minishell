/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblackth <lblackth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:40:37 by lblackth          #+#    #+#             */
/*   Updated: 2022/05/14 18:44:22 by lblackth         ###   ########.fr       */
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

char	*arr_join(char **arr_f, char **arr_s)
{
	int		i;
	int		j;
	char	*arr;

	i = 0;
	j = 0;
	while (arr_f[i])
		++i;
	while (arr_s[j])
		++j;
	arr = (char *)malloc(i + j + 1);
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
