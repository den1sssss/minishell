/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblackth <lblackth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:02:21 by lblackth          #+#    #+#             */
/*   Updated: 2021/10/18 19:03:53 by lblackth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pow10(int n)
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
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		zn;
	char	*arr;
	int		tlen;

	zn = 1;
	len = d_len(n);
	arr = (char *)malloc(len + 1);
	if (!arr)
		return (NULL);
	arr[len] = 0;
	tlen = len;
	if (n < 0)
	{
		zn = -1;
		len--;
		arr[0] = '-';
	}
	while (len--)
		arr[tlen - len - 1] = ((n / pow10(len)) % 10) * zn + '0';
	return (arr);
}
