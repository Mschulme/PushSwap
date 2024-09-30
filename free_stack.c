/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:25:23 by mschulme          #+#    #+#             */
/*   Updated: 2023/06/19 19:23:23 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list *stack_a, t_list *stack_b, long *array)
{
	t_list	*stack_free;

	while (stack_a != NULL)
	{
		stack_free = stack_a;
		stack_a = stack_a->next;
		free(stack_free);
	}
	while (stack_b != NULL)
	{
		stack_free = stack_b;
		stack_b = stack_b->next;
		free(stack_free);
	}
	free(array);
}
