/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:43:57 by jutrera-          #+#    #+#             */
/*   Updated: 2022/09/27 18:46:09 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t  i;
    size_t  j;
    size_t  n_len;

    if (!haystack && len == 0)
        return (NULL);
    n_len = ft_strlen(needle);
    if (n_len == 0)
        return ((char *)haystack);
    i = 0;
    while (haystack[i] && i + n_len <= len)
    {
        j = 0;
        while (j < n_len && haystack[i + j] == needle[j])
            j++;
        if (j == n_len)
            return ((char *)(haystack + i));
        i++;
    }
    return (NULL);
}
