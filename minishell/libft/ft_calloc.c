/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblackth <lblackth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:02:14 by lblackth          #+#    #+#             */
/*   Updated: 2021/10/18 19:04:42 by lblackth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*dst;
	size_t			s;

	s = count * size;
	dst = (unsigned char *)malloc(s);
	if (!dst)
		return (NULL);
	return (ft_bzero(dst, s));
}
