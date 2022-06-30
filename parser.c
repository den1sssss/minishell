#include "minishell.h"

void	b_redir(t_comlist *list, t_info *info)
{
	int			fd;
	t_comlist	*tmp;

	// if (!list->next->next)
	// 	ft_error();
	// if (list->next->next->type < 7)
	// 	ft_error();
	fd = open(list->next->next->str, O_RDONLY, 0644);
	info->std_r = fd;
	tmp = list->next;
	list->next = list->next->next->next;
	free(tmp->next->str);
	free(tmp->next);
	free(tmp);
}

void	f_redir(t_comlist *list, t_info *info)
{
	int			fd;
	t_comlist	*tmp;

	// if (!list->next->next)
	// 	ft_error();
	// if (list->next->next->type < 7)
	// 	ft_error();
	fd = open(list->next->next->str, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	info->std_w = fd;
	tmp = list->next;
	list->next = list->next->next->next;
	free(tmp->next->str);
	free(tmp->next);
	free(tmp);
}

void	d_f_redir(t_comlist *list, t_info *info)
{
	int			fd;
	t_comlist	*tmp;

	// if (!list->next->next)
	// 	ft_error();
	// if (list->next->next->type < 7)
	// 	ft_error();
	fd = open(list->next->next->str, O_CREAT | O_APPEND | O_WRONLY, 0644);
	info->std_w = fd;
	tmp = list->next;
	list->next = list->next->next->next;
	free(tmp->next->str);
	free(tmp->next);
	free(tmp);
}

void	info_init(t_info *info)
{
	info->fork = 0;
	info->std_r = 4;
	info->std_w = 3;
}

char	**list_to_arr(t_comlist *list)
{
	int			i;
	t_comlist	*tmp;
	char		**arr;

	i = 0;
	tmp = list;
	while (tmp && tmp->type != 4)
	{
		i++;
		tmp = tmp->next;
	}
	arr = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	tmp = list;
	while (tmp && tmp->type != 4)
	{
		arr[i] = tmp->str;
		i++;
		tmp = tmp->next;
	}
	arr[i] = NULL;
	return (arr);
}

void	set_pipe(t_info *info)
{
	int	fd[2];

	pipe(fd);
	info->std_w = fd[1];
	info->std_r = fd[0];
	info->fork = 1;
}

char	**parse(t_comlist *list, t_info *info)
{
	t_comlist	*start;
	char		**arr;

	start = list;
	while (list->next)
	{
		if (list->next->type == 4)
			break ;
		else if (!list->next->type)
		{
			b_redir(list, info);
			continue;
		}
		else if (list->next->type == 2)
		{
			f_redir(list, info);
			continue;
		}
		else if (list->next->type == 3)
		{
			d_f_redir(list, info);
			continue;
		}
		list = list->next;
		if (!list)
			break ;
	}
	arr = list_to_arr(start);
	if (list && list->next && list->next->type == 4)
		set_pipe(info);
	return (arr);
}
