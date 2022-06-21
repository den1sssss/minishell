/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblackth <lblackth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:02:33 by lblackth          #+#    #+#             */
/*   Updated: 2021/10/23 18:08:59 by lblackth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tlist;

	if (!lst)
		return (NULL);
	tlist = ft_lstnew(f(lst->content));
	if (!tlist)
	{
		ft_lstclear(&tlist, del);
		return (NULL);
	}
	tlist->next = ft_lstmap(lst->next, f, del);
	return (tlist);
}
