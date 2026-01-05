/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 10:37:41 by jutrera-          #+#    #+#             */
/*   Updated: 2022/09/27 19:07:04 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t  s_len;
    char    *ret;

    if (!s)
        return (NULL);
    s_len = ft_strlen(s);
    if (start >= s_len)
    {
        ret = malloc(1);
        if (!ret)
            return (NULL);
        ret[0] = '\0';
        return (ret);
    }
    if (len > s_len - start)
        len = s_len - start;
    ret = malloc(len + 1);
    if (!ret)
        return (NULL);
    ft_strlcpy(ret, s + start, len + 1);
    return (ret);
}
