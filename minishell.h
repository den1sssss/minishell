/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblackth <lblackth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:17:47 by lblackth          #+#    #+#             */
/*   Updated: 2022/05/27 22:11:29 by lblackth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <curses.h>
# include <term.h>
# include <fcntl.h>
# include <sys/types.h>

typedef struct s_atree
{
	int				type;
	void			*act;
	struct s_atree	*left;
	struct s_atree	*right;
}				t_atree;

typedef struct s_comlist
{
	int					type;
	char				*str;
	struct s_comlist	*next;
}				t_comlist;

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
void		ccont_split(char *str, int *i, t_comlist *tek);
void		cont_split(char *str, int *i, t_comlist *tek);
t_comlist	*ms_split(char *str);
void		str_func(t_comlist **tek);

#endif