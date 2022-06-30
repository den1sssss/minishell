/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:59:21 by dshirely          #+#    #+#             */
/*   Updated: 2022/06/30 14:59:21 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>

typedef struct s_comlist
{
	int					type;
	char				*str;
	struct s_comlist	*next;
}				t_comlist;

typedef struct s_info
{
	int	std_r;
	int	std_w;
	int	fork;
}				t_info;

typedef struct s_envlist
{
	char				*key;
	char				*val;
	struct s_envlist	*next;
}				t_envlist;

t_envlist	*g_env_list;

void		envp_copy(char **envp);
char		*prompt(void);
void		ft_ctrlc(int signum);
void		ft_ctrld(int signum);
int			dquot_ind(char *str, int i);
int			squot_ind(char *str, int i);
char		**arr_join(char **arr_f, char **arr_s);
int			ft_isspace(int c);
t_comlist	*comlist_last(t_comlist *start);
void		list_insert(t_comlist *tek, int type);
void		micro_split(t_comlist *tek, int i, int type);
int			str_check(t_comlist *tek);
int			space_skip(char *str, int i);
int			skip_to_space(char *str, int i);
void		str_func(t_comlist **tek);
void		ccont_split(char *str, int *i, t_comlist **tek);
void		cont_split(char *str, int *i, t_comlist **tek);
t_comlist	*ms_split(char *str);
t_comlist	*skip_to_pipe(t_comlist *list);
char		**parse(t_comlist *list, t_info *info);
char		**list_to_arr(t_comlist *list);
void		info_init(t_info *info);
void		d_f_redir(t_comlist *list, t_info *info);
void		f_redir(t_comlist *list, t_info *info);
void		b_redir(t_comlist *list, t_info *info);
void		ms_echo(char **arr);
void		ms_pwd(void);
void		home_exp(char *str);
void		ms_cd(char **arr);
void		ms_exit(char **arr);
void		exp_print(void);
int			is_valid(char *key);
void		exp_err(char *key_val);
int			ms_export(char **arr);
void		ms_env(void);
void		unset_env(t_envlist *cur, t_envlist *prev);
void		env_check(char *str);
void		ms_unset(char **arr);
char		*get_val(char *str);
t_envlist	*new_envlist(char **arr);
t_envlist	*envlist_last(t_envlist *envlist);
t_envlist	*env_to_list(char **envp);
char		**list_to_env(t_envlist *env_list);
int			ft_strcmp(const char *str1, const char *str2);
int			builtins(char **arr);
char		*get_current_path(char **paths, char *cur, char *arr);
char		**get_paths(void);
int			check_full_path(const char *s);
int			check_path(char **arr);
void		free_arr(char **arr);
void		execute(char **arr);
void		fork_execute(char **arr, t_info info);
int			is_fork(t_info info);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_atoi(const char *str);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split(char const *s, char c);
void		parsing(t_comlist *list, t_info *info);
void		exporting(char **arr);
int			sizing(t_envlist *env_list);
void		add_node(t_comlist **start, int type, char *str);

#endif