/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radixsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:38:32 by mschulme          #+#    #+#             */
/*   Updated: 2023/06/20 18:15:34 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *head)
{	
	while (head->next != NULL)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

void	ft_radix_helper(t_list **stack_a, t_list **stack_b, int j, int num_bits)
{
	int	b_size;

	b_size = stack_size(*stack_b);
	while (b_size-- && j <= num_bits)
	{
		if ((((*stack_b)->index >> j) & 1) == 1)
			do_pa(stack_a, stack_b);
		else
			do_rb(stack_b);
	}
}

void	ft_radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	j;
	int	num_bits;
	int	size;

	num_bits = 0;
	size = stack_size(*stack_a);
	while (size > 1 && ++num_bits)
		size /= 2;
	j = 0;
	while (j <= num_bits)
	{
		size = stack_size(*stack_a);
		while (size-- && !is_sorted(*stack_a))
		{
			if ((((*stack_a)->index >> j) & 1) == 0)
				do_pb(stack_a, stack_b);
			else
				do_ra(stack_a);
		}
		ft_radix_helper(stack_a, stack_b, j + 1, num_bits);
		j++;
	}
	while (*stack_b)
		do_pa(stack_a, stack_b);
}
