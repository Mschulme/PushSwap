/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:57:03 by mschulme          #+#    #+#             */
/*   Updated: 2023/06/18 17:48:19 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack2(t_list *stack_free)
{
	t_list	*temp;

	while (stack_free != NULL)
	{
		temp = stack_free;
		stack_free = stack_free->next;
		free(temp);
	}
	exit (1);
}

t_list	*ft_init_stack_2(int ac, char **av, t_list *stack_a)
{
	int	i;
	int	nb;
	int	*checkptr;
	int	check;

	check = 1;
	checkptr = &check;
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i], checkptr);
		if (*checkptr == -1)
			ft_free_stack2(stack_a);
		if (i == 1)
			stack_a = newstack(nb);
		else
			stack_add_bottom(&stack_a, newstack(nb));
		i++;
	}
	return (stack_a);
}
