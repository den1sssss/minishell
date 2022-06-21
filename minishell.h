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
# include "libft/libft.h"

typedef struct s_comlist
{
	int					type;
	char				*str;
	struct s_comlist	*next;
}				t_comlist;

char	**g_envp;

void		envp_copy(char **envp);
char		*prompt(void);
void		ft_ctrlc(int signum);
void		ft_exit(int signum);
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
void		ms_loop(void);

#endif