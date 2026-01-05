/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:20:39 by jutrera-          #+#    #+#             */
/*   Updated: 2022/09/21 12:44:37 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    *ft_memchr(const void *str, int c, size_t n)
{
    const unsigned char *p = str;

    while (n--)
    {
        if (*p == (unsigned char)c)
            return ((void *)p);
        p++;
    }
    return (NULL);
}
