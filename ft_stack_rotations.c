/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_rotations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:03:33 by mschulme          #+#    #+#             */
/*   Updated: 2023/06/19 17:16:35 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_list_bottom(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

void	do_ra(t_list **stack_a)
{
	if (stack_size(*stack_a) <= 1)
		return ;
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	do_rb(t_list **stack_b)
{
	if (stack_size(*stack_b) <= 1)
		return ;
	rotate(stack_b);
	write(1, "rb\n", 3);
}
