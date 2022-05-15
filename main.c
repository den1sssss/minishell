/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblackth <lblackth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:40:44 by lblackth          #+#    #+#             */
/*   Updated: 2022/05/15 19:56:44 by lblackth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	term_str(void)
{
	printf("minishell%% ");
}

int	main(int argc, char **argv, char **env)
{
	char	*str;

	while (1)
	{
		term_str();
		scanf("%s", str);
		printf("\n%s\n", str);
	}
}
