/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:59:14 by dshirely          #+#    #+#             */
/*   Updated: 2022/06/30 14:59:14 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*prompt(void)
{
	char	*cwd;
	char	*str;
	char	*tmp;

	cwd = getcwd(NULL, 0);
	tmp = cwd;
	cwd = ft_strjoin(cwd, " ");
	free(tmp);
	str = ft_strjoin("MS ", cwd);
	free(cwd);
	return (str);
}

t_comlist	*skip_to_pipe(t_comlist *list)
{
	t_comlist	*tmp;

	while (list)
	{
		if (list->type == 4)
			break ;
		tmp = list;
		list = list->next;
		free(tmp);
	}
	if (list)
	{
		if (list->type == 4)
		{
			tmp = list;
			list = list->next;
			free(tmp);
		}
	}
	return (list);
}

void	ms_loop(void)
{
	char		*str;
	char		*tmp;
	t_comlist	*list;
	t_info		info;
	char		**arr;

	while (1)
	{
		tmp = prompt();
		str = readline(tmp);
		free(tmp);
		list = ms_split(str);
		while (list)
		{
			info_init(&info);
			arr = parse(list, &info);
			list = skip_to_pipe(list);
			if (is_fork(info))
				fork_execute(arr, info);
			else
				execute(arr);
			free_arr(arr);
			free(arr);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	g_env_list = env_to_list(envp);
	signal(SIGINT, ft_ctrlc);
	signal(SIGQUIT, ft_ctrld);
	ms_loop();
	return (0);
}
