/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblackth <lblackth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:03:01 by lblackth          #+#    #+#             */
/*   Updated: 2021/10/18 20:59:28 by lblackth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*arr;

	if (!f || !s)
		return (NULL);
	len = ft_strlen(s);
	arr = (char *)malloc(len + 1);
	if (!arr)
		return (NULL);
	arr[len] = 0;
	while (len--)
		arr[len] = (*f)(len, s[len]);
	return (arr);
}
