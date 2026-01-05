/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:02:29 by jutrera-          #+#    #+#             */
/*   Updated: 2022/09/27 19:31:59 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *new_list;
    t_list  *node;
    void    *content;

    if (!lst || !f || !del)
        return (NULL);

    new_list = NULL;
    while (lst)
    {
        content = f(lst->content);
        node = ft_lstnew(content);
        if (!node)
        {
            del(content);
            ft_lstclear(&new_list, del);
            return (NULL);
        }
        ft_lstadd_back(&new_list, node);
        lst = lst->next;
    }
    return (new_list);
}
