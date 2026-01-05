/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:09:46 by jutrera-          #+#    #+#             */
/*   Updated: 2022/09/27 18:45:48 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int    i;
    size_t          len;
    char            *new_s;

    if (!s || !f)
        return (NULL);
    len = ft_strlen(s);
    new_s = malloc(len + 1);
    if (!new_s)
        return (NULL);
    i = 0;
    while (i < len)
    {
        new_s[i] = f(i, s[i]);
        i++;
    }
    new_s[i] = '\0';
    return (new_s);
}
