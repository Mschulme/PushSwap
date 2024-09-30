/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:31:36 by mschulme          #+#    #+#             */
/*   Updated: 2023/06/19 18:02:53 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isblank(char str)
{
	return (str == ' ' || (str >= 9 && str <= 13));
}

void	ft_atoi_helper(const char *str, int *checkptr)
{
	if (str[0] == 0 || (str[0] == '-' && str[1] == 0) \
		|| (str[0] == '+' && str[1] == 0))
	{
		write(2, "Error\n", 6);
		*checkptr = -1;
	}
}

int	ft_atoi(const char *str, int *checkptr)
{
	int			sign;
	long long	res;

	res = 0;
	sign = 1;
	ft_atoi_helper(str, checkptr);
	while (ft_isblank(*str) == 1 && *str)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	res = res * sign;
	if (*str != '\0' || res > 2147483647 || res < -2147483648)
	{
		write(2, "Error\n", 6);
		*checkptr = -1;
	}
	return (res);
}
