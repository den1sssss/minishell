/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblackth <lblackth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:02:53 by lblackth          #+#    #+#             */
/*   Updated: 2021/10/18 19:03:29 by lblackth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
