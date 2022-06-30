/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:59:26 by dshirely          #+#    #+#             */
/*   Updated: 2022/06/30 14:59:26 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_ctrlc(int signum)
{
	int	pid;
	int	stat;

	pid = waitpid(-1, &stat, WNOHANG);
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		if (pid)
		{
			rl_on_new_line();
			rl_redisplay();
		}
	}
}

void	ft_ctrld(int signum)
{
	int		stat;
	int		pid;

	(void)signum;
	pid = waitpid(-1, &stat, WNOHANG);
	if (!pid)
		write(1, "quit\n", 5);
}
