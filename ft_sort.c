/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:55:09 by mschulme          #+#    #+#             */
/*   Updated: 2023/06/19 18:03:47 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(long *array, long position1, long position2)
{
	long	temp;

	temp = array[position1];
	array[position1] = array[position2];
	array[position2] = temp;
}

long	*selectionsort(long *array, int size)
{
	int		i;
	int		j;
	long	min;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[min])
				min = j;
			j++;
		}
		swap(array, min, i);
		i++;
	}
	return (array);
}
