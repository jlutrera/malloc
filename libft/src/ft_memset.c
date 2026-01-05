/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:41:30 by jutrera-          #+#    #+#             */
/*   Updated: 2022/09/23 10:49:23 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    *ft_memset(void *str, int c, size_t n)
{
    unsigned char   *p;

    if (!str)
        return (NULL);
    p = (unsigned char *)str;
    while (n--)
        *p++ = (unsigned char)c;
    return (str);
}

