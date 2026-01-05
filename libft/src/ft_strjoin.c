/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:43:08 by jutrera-          #+#    #+#             */
/*   Updated: 2022/09/27 18:44:23 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *dest;
    size_t  len_s1;
    size_t  len_s2;

    if (!s1 || !s2)
        return (NULL);
    len_s1 = ft_strlen(s1);
    len_s2 = ft_strlen(s2);
    dest = malloc(len_s1 + len_s2 + 1);
    if (!dest)
        return (NULL);
    ft_memcpy(dest, s1, len_s1);
    ft_memcpy(dest + len_s1, s2, len_s2);
    dest[len_s1 + len_s2] = '\0';
    return (dest);
}
