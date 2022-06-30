/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:59:12 by dshirely          #+#    #+#             */
/*   Updated: 2022/06/30 15:56:57 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			write(fd, s, 1);
			s++;
		}
	}
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c && *s != 0)
		s++;
	if (c != 0 && *s == 0)
		return (NULL);
	return ((char *)s);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && i < n - 1)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sum;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	sum = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!sum)
		return (NULL);
	while (*s1)
		sum[i++] = *s1++;
	while (*s2)
		sum[i++] = *s2++;
	sum[i] = 0;
	return (sum);
}
