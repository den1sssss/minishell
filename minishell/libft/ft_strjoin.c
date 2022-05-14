/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblackth <lblackth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:02:56 by lblackth          #+#    #+#             */
/*   Updated: 2021/10/18 20:56:53 by lblackth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sum;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	sum = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!sum)
		return (NULL);
	while (*s1)
		sum[i++] = *s1++;
	while (*s2)
		sum[i++] = *s2++;
	sum[i] = 0;
	return (sum);
}
