/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:15:23 by jutrera-          #+#    #+#             */
/*   Updated: 2022/09/27 18:43:25 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int  count_words(const char *str, char c)
{
    int count;
    int in_word;

    count = 0;
    in_word = 0;
    while (*str)
    {
        if (*str != c && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (*str == c)
            in_word = 0;
        str++;
    }
    return (count);
}

static char *word_dup(const char *str, size_t start, size_t finish)
{
    char    *word;
    size_t  i;

    word = malloc((finish - start + 1) * sizeof(char));
    if (!word)
        return (NULL);
    i = 0;
    while (start < finish)
        word[i++] = str[start++];
    word[i] = '\0';
    return (word);
}

static void *ft_free(char **split, size_t j)
{
    size_t  i;

    i = 0;
    while (i < j)
        free(split[i++]);
    free(split);
    return (NULL);
}

static char **processing(char **split, const char *s, char c)
{
    size_t  i;
    size_t  j;
    size_t  index;
    size_t  len;

    len = ft_strlen(s);
    i = 0;
    j = 0;
    index = (size_t)-1;
    while (i <= len)
    {
        if (s[i] != c && index == (size_t)-1)
            index = i;
        else if ((s[i] == c || i == len) && index != (size_t)-1)
        {
            split[j] = word_dup(s, index, i);
            if (!split[j])
                return (ft_free(split, j));
            j++;
            index = (size_t)-1;
        }
        i++;
    }
    split[j] = NULL;
    return (split);
}

char    **ft_split(const char *s, char c)
{
    char    **split;

    if (!s)
        return (NULL);
    split = malloc((count_words(s, c) + 1) * sizeof(char *));
    if (!split)
        return (NULL);
    return (processing(split, s, c));
}
