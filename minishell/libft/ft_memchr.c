/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblackth <lblackth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:02:36 by lblackth          #+#    #+#             */
/*   Updated: 2021/10/23 14:19:36 by lblackth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*ar;
	size_t			i;

	i = 0;
	if (!n)
		return (NULL);
	ar = (unsigned char *)arr;
	while (i < n)
	{
		if (ar[i] == (unsigned char)c)
			return (&ar[i]);
		i++;
	}
	return (NULL);
}
