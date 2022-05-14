/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblackth <lblackth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:02:40 by lblackth          #+#    #+#             */
/*   Updated: 2021/10/20 19:40:07 by lblackth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*dst1;
	unsigned char	*s;
	size_t			i;

	if (!src && !dst)
		return (NULL);
	if (src < dst)
		return (ft_memcpy(dst, src, n));
	else
	{
		d = (unsigned char *)dst;
		dst1 = d;
		s = (unsigned char *)src;
		i = 0;
		while (i < n)
		{
			*d++ = *s++;
			i++;
		}
	}
	return (dst1);
}
