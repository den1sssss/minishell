#include "minishell.h"

char	*get_val(char *str)
{
	t_envlist	*envlist;

	envlist = g_env_list;
	while (envlist)
	{
		if (!ft_strcmp(envlist->key, str))
			return (envlist->val);
		envlist = envlist->next;
	}
	return (NULL);
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

t_envlist	*envlist_last(t_envlist *envlist)
{
	t_envlist	*tmp;

	tmp = envlist;
	if (!tmp)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_envlist	*env_to_list(char **envp)
{
	char		**arr;
	t_envlist	*start;
	t_envlist	*tmp;
	int			i;

	i = 0;
	arr = ft_split(envp[i], '=');
	start = new_envlist(arr);
	free(arr);
	tmp = start;
	++i;
	while (envp[i])
	{
		arr = ft_split(envp[i], '=');
		tmp->next = new_envlist(arr);
		free(arr);
		tmp = tmp->next;
		++i;
	}
	return (start);
}

char	**list_to_env(t_envlist *env_list)
{
	char		**arr;
	char		*tmp;
	t_envlist	*tmp_list;
	int			size;
	int			i;

	tmp_list = env_list;
	size = 0;
	while (tmp_list)
	{	
		++size;
		tmp_list = tmp_list->next;
	}
	arr = (char**)malloc(sizeof(char *) * (size + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (env_list)
	{
		tmp = ft_strjoin(env_list->key, "=");
		arr[i] = ft_strjoin(tmp, env_list->val);
		free(tmp);
		++i;
		env_list = env_list->next;
	}
	arr[i] = NULL;
	return (arr);
}
