/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:49:56 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/09 14:49:56 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	long	*array;

	stack_a = NULL;
	stack_b = NULL;
	array = NULL;
	if (ac < 2)
		return (0);
	else if (ac == 2)
		stack_a = ft_init_stack_1(av, stack_a);
	else
		stack_a = ft_init_stack_2(ac, av, stack_a);
	array = createarray(stack_a);
	ft_index(stack_a, array);
	if (stack_size(stack_a) == 3)
		ft_sort_small_3(&stack_a);
	else if (stack_size(stack_a) == 4 || stack_size(stack_a) == 5)
		ft_sort_small_5(&stack_a, &stack_b);
	else
		ft_radix_sort(&stack_a, &stack_b);
	free_stack(stack_a, stack_b, array);
	return (0);
}
