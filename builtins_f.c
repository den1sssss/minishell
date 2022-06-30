/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:58:56 by dshirely          #+#    #+#             */
/*   Updated: 2022/06/30 14:58:56 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_echo(char **arr)
{
	int	flag;

	arr++;
	flag = 1;
	if (*arr && !ft_strcmp(*arr, "-n"))
	{
		flag = 0;
		arr++;
	}
	while (*arr)
	{
		ft_putstr_fd(*(arr)++, 1);
		if (*arr)
			write(1, " ", 1);
	}
	if (flag)
		write(1, "\n", 1);
}

void	ms_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	ft_putstr_fd(cwd, 1);
	write(1, "\n", 1);
	free(cwd);
}

void	home_exp(char *str)
{
	char		*arr[2];
	char		*cwd;

	cwd = getcwd(NULL, 0);
	arr[0] = ft_strjoin(str, cwd);
	arr[1] = NULL;
	ms_export(arr);
	free(cwd);
	free(arr[0]);
}

void	ms_cd(char **arr)
{
	char	*str;

	++arr;
	home_exp("OLDPWD=");
	if (*arr == NULL)
	{
		str = get_val("HOME");
		if (*str)
			chdir(str);
		else
			write(2, "MS: cd: HOME not set", 20);
	}
	else
		chdir(*arr);
	home_exp("PWD=");
}

void	ms_exit(char **arr)
{
	int	i;

	write(1, "exit\n", 5);
	++arr;
	i = 0;
	while (arr[i])
		++i;
	if (!i)
		exit(0);
	exit(ft_atoi(arr[0]));
}
