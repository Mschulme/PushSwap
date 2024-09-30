/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:55:23 by mschulme          #+#    #+#             */
/*   Updated: 2023/06/19 20:31:54 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_small_3(t_list **stack_a)
{
	if (is_sorted(*stack_a) == 1)
		return ;
	else if ((*stack_a)->index == 0 && (*stack_a)->next->index == 2)
		write(1, "pb\nra\npa\n", 9);
	else if ((*stack_a)->index == 1 && (*stack_a)->next->index == 0)
		write(1, "sa\n", 3);
	else if ((*stack_a)->index == 1 && (*stack_a)->next->index == 2)
		write(1, "rra\n", 4);
	else if ((*stack_a)->index == 2 && (*stack_a)->next->index == 1)
		write(1, "sa\nrra\n", 7);
	else if ((*stack_a)->index == 2 && (*stack_a)->next->index == 0)
		write(1, "rra\nrra\n", 8);
}

void	ft_sort_small_3_rev(t_list **stack_b)
{
	if ((*stack_b)->index == 0 && (*stack_b)->next->index == 1)
		write(1, "sb\nrrb\n", 7);
	else if ((*stack_b)->index == 0 && (*stack_b)->next->index == 2)
		write(1, "rb\n", 3);
	else if ((*stack_b)->index == 1 && (*stack_b)->next->index == 0)
		write(1, "rrb\n", 4);
	else if ((*stack_b)->index == 1 && (*stack_b)->next->index == 2)
		write(1, "sb\n", 3);
	else if ((*stack_b)->index == 2 && (*stack_b)->next->index == 1)
		return ;
	else if ((*stack_b)->index == 2 && (*stack_b)->next->index == 0)
		write(1, "pa\nsb\npb\n", 9);
}

void	ft_sort_small_4(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if ((*stack_a)->index == 3)
			do_ra(stack_a);
		else
			do_pb(stack_a, stack_b);
		i++;
	}
	ft_sort_small_3_rev(stack_b);
	write(1, "pa\npa\npa\n", 9);
}

void	ft_sort_small_5(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	if (is_sorted(*stack_a) == 1)
		return ;
	if (stack_size(*stack_a) == 4)
	{
		ft_sort_small_4(stack_a, stack_b);
		return ;
	}
	while (i < 5)
	{
		if ((*stack_a)->index == 4 || (*stack_a)->index == 3)
			do_ra(stack_a);
		else
			do_pb(stack_a, stack_b);
		i++;
	}
	if ((*stack_a)->index == 4 && (*stack_a)->next->index == 3)
		write(1, "sa\n", 3);
	ft_sort_small_3_rev(stack_b);
	write(1, "pa\npa\npa\n", 9);
}
