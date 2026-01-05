/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:15:40 by jutrera-          #+#    #+#             */
/*   Updated: 2022/09/29 21:15:40 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int ft_atoi(const char *str)
{
    long    result;
    int     sign;

    if (!str)
        return (0);
    while ((*str >= 9 && *str <= 13) || *str == ' ')
        str++;
    sign = 1;
    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    result = 0;
    while (*str >= '0' && *str <= '9')
    {
        if (result > (LONG_MAX / 10)
            || (result == LONG_MAX / 10 && (*str - '0') > LONG_MAX % 10))
            return (sign == 1 ? INT_MAX : INT_MIN);

        result = result * 10 + (*str - '0');
        str++;
    }
    return ((int)(result * sign));
}
