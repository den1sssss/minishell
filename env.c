#include "minishell.h"

char	*get_env_value(char *str, t_envlist *envlist)
{
	while (envlist)
	{
		if (!ft_strcmp(envlist->key, str))
			return (envlist->val);
		envlist = envlist->next;
	}
	return ("");
}

t_envlist	*new_envlist(char **arr)
{
	t_envlist	*new;

	new = (t_envlist *)malloc(sizeof(t_envlist));
	new->key = arr[0];
	new->val = arr[1];
	new->next = NULL;
	return (new);
}

t_envlist	*env_to_list(void)
{
	char		**arr;
	t_envlist	*start;
	t_envlist	*tmp;
	int			i;

	i = 0;
	arr = ft_split(g_envp[i], '=');
	start = new_envlist(arr);
	free(arr);
	tmp = start;
	++i;
	while (g_envp[i])
	{
		arr = ft_split(g_envp[i], '=');
		tmp->next = new_envlist(arr);
		free(arr);
		tmp = tmp->next;
		++i;
	}
	return (start);
}