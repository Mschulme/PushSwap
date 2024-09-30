/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createarray_and_index.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:27:50 by mschulme          #+#    #+#             */
/*   Updated: 2023/06/19 18:24:00 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index(t_list *stack_a, long *array)
{
	int	i;
	int	j;
	int	size;

	size = stack_size(stack_a);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (stack_a->value != array[j])
		{
			j++;
		}
		stack_a->index = j;
		stack_a = stack_a->next;
		i++;
	}
}

void	ft_free_array(t_list *stack_free)
{
	t_list	*temp;

	while (stack_free != NULL)
	{
		temp = stack_free;
		stack_free = stack_free->next;
		free(temp);
	}
	return ;
}

static void	ft_helper(t_list *temp, long *array)
{
	write(2, "Error\n", 6);
	ft_free_array(temp);
	free(array);
	exit (1);
}

long	*createarray(t_list *stack_a)
{
	int		size;
	int		i;
	long	*array;
	t_list	*temp;

	temp = stack_a;
	size = stack_size(stack_a);
	array = malloc(sizeof(long) * size);
	i = 0;
	while (i < size)
	{
		array[i++] = stack_a->value;
		stack_a = stack_a->next;
	}
	array = selectionsort(array, size);
	i = 0;
	while (i < size - 1)
	{
		if (array[i] == array[i + 1])
			ft_helper(temp, array);
		i++;
	}
	return (array);
}
