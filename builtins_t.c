#include "minishell.h"

void	unset_env(t_envlist *cur, t_envlist *prev)
{
	t_envlist *tmp;

	free(cur->val);
	free(cur->key);
	free(cur);
	if (prev)
		prev->next = cur->next;
	else if (cur->next)
	{
		tmp = cur->next;
		cur->next = cur->next->next;
		free(tmp);
	}
}

void	env_check(char *str)
{
	t_envlist	*cur;
	t_envlist	*prev;

	prev = NULL;
	cur = g_env_list;
	while (cur)
	{
		if (!ft_strcmp(cur->key, str))
		{
			unset_env(cur, prev);
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
}

void	ms_unset(char **arr)
{
	if (*arr)
	{
		while (*arr)
		{
			env_check(*arr);
			++arr;
		}
	}
}
