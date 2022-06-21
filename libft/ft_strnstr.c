/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblackth <lblackth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:03:04 by lblackth          #+#    #+#             */
/*   Updated: 2021/10/20 20:56:20 by lblackth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*dop(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;
	int	ln;
	int	lh;
	int	tlen;

	ln = ft_strlen(needle);
	lh = ft_strlen(haystack);
	i = 0;
	tlen = len - ln + 1;
	while (i < lh - ln + 2 && tlen--)
	{
		j = 0;
		while (j < ln)
		{
			if (needle[j] == haystack[i + j])
				j++;
			else
				break ;
		}
		if (j == ln)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (!(*needle))
		return ((char *)haystack);
	if (!len)
		return (NULL);
	return (dop(haystack, needle, len));
}
