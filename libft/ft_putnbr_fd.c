/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblackth <lblackth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:02:45 by lblackth          #+#    #+#             */
/*   Updated: 2021/10/20 19:27:32 by lblackth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	powww10(int n)
{
	int	s;

	s = 1;
	while (n--)
		s *= 10;
	return (s);
}

static int	d_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	zn;
	int	len;
	int	temp;

	zn = 1;
	if (n < 0)
	{
		zn = -1;
		write(fd, "-", 1);
	}
	len = d_len(n);
	while (len--)
	{
		temp = ((n / powww10(len)) % 10) * zn + '0';
		write(fd, &temp, 1);
	}
}
