/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblackth <lblackth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:02:11 by lblackth          #+#    #+#             */
/*   Updated: 2021/10/23 14:22:28 by lblackth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
