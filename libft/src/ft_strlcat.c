/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 09:11:45 by rbeaufre          #+#    #+#             */
/*   Updated: 2022/09/27 18:44:44 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t  dst_len;
    size_t  src_len;
    size_t  i;

    dst_len = 0;
    src_len = ft_strlen(src);
    while (dst_len < size && dst[dst_len])
        dst_len++;
    if (dst_len == size)
        return (size + src_len);
    i = 0;
    while (src[i] && dst_len + i + 1 < size)
    {
        dst[dst_len + i] = src[i];
        i++;
    }
    dst[dst_len + i] = '\0';
    return (dst_len + src_len);
}

