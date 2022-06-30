/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:24:24 by dshirely          #+#    #+#             */
/*   Updated: 2022/06/30 16:40:34 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_full_path(const char *s)
{
	return (!ft_strncmp("../", s, 3) || \
		!ft_strncmp("/", s, 1) || !ft_strncmp("./", s, 2));
}

void	exp_err(char *key_val)
{
	write(2, "MS: export: '", 13);
	ft_putstr_fd(key_val, 2);
	write(2, "': not valid identifier\n", 24);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
