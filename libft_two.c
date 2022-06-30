/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:22:11 by dshirely          #+#    #+#             */
/*   Updated: 2022/06/30 15:24:52 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!*s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(s1);
	dst = (char *)malloc(len + 1);
	if (!dst)
		return (NULL);
	dst[len] = 0;
	if (len)
	{
		while (len--)
			dst[len] = s1[len];
	}
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	i = 0;
	dst = (char *)malloc(len + 1);
	if (!dst)
		return (NULL);
	while (i < len)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

int	ft_atoi(const char *str)
{
	unsigned long	s;
	int				zn;

	s = 0;
	zn = 1;
	while (*str == '\f' || *str == '\t' || *str == '\r' \
	|| *str == '\v' || *str == '\n' || *str == ' ')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		zn = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		s = s * 10 + *str - '0';
		str++;
		if (s > 2147483647 && zn + 1)
			return (-1);
		if (s > 2147483648)
			return (0);
	}
	return ((int) s * zn);
}

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
