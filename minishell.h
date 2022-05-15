/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblackth <lblackth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:17:47 by lblackth          #+#    #+#             */
/*   Updated: 2022/05/15 19:52:01 by lblackth         ###   ########.fr       */
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
	char				*cont;
	struct s_comlist	*next;
}				t_comlist;

#endif