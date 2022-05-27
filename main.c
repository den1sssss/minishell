/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblackth <lblackth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:40:44 by lblackth          #+#    #+#             */
/*   Updated: 2022/05/27 22:18:06 by lblackth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char		*str;
	t_comlist	*list;

	scanf("%s", str);
	printf("\n\n");
	list = ms_split(str);
	while (list)
	{
		if (list->type != 9)
			printf("%d ", list->type);
		else
			printf("%s", list->str);
		printf("\n");
		list = list->next;
	}
	return (0);
}
