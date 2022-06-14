/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblackth <lblackth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:03:03 by lblackth          #+#    #+#             */
/*   Updated: 2021/10/20 20:41:02 by lblackth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;

	temp = NULL;
	while (*s != 0)
	{
		if (*s == (unsigned char)c)
			temp = (char *)s;
		s++;
	}
	if (c == 0 && s)
		return ((char *)s);
	return (temp);
}
