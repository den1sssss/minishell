/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:59:09 by dshirely          #+#    #+#             */
/*   Updated: 2022/06/30 15:23:58 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	*ft_clear(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i]);
	free(arr);
	return (NULL);
}

static int	next(const char *s, char c, int i)
{
	while (s[i] == c && s[i])
		i++;
	return (i);
}

static int	words(const char *s, char c)
{
	int	count;
	int	i;

	if (!*s)
		return (0);
	i = 0;
	count = 0;
	i = next(s, c, i);
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		i = next(s, c, i);
		count++;
	}
	return (count);
}

static int	word_len(const char *s, char c, int start)
{
	int	i;

	i = 0;
	while (s[start + i] && s[start + i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		start;
	int		i;
	int		count;

	if (!s)
		return (NULL);
	count = words(s, c);
	arr = (char **)malloc((count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = -1;
	start = 0;
	while (++i < count)
	{
		start = next(s, c, start);
		arr[i] = ft_substr(s, start, word_len(s, c, start));
		if (!arr[i])
			return (ft_clear(arr));
		while (s[start] && s[start] != c)
			start++;
	}
	arr[i] = NULL;
	return (arr);
}
