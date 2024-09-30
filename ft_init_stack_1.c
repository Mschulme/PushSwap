/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:46:14 by mschulme          #+#    #+#             */
/*   Updated: 2023/06/18 18:27:57 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack1(char **str, t_list *stack_free)
{
	t_list	*temp;
	int		i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
	while (stack_free != NULL)
	{
		temp = stack_free;
		stack_free = stack_free->next;
		free(temp);
	}
	exit (1);
}

char	**ft_split_helper(char *av, char **str)
{
	str = ft_split(av, ' ');
	if (str[0] == NULL)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	return (str);
}

t_list	*ft_init_stack_1(char **av, t_list *stack_a)
{
	char	**str;
	int		i;
	int		*checkptr;
	int		check;

	checkptr = &check;
	str = NULL;
	str = ft_split_helper(av[1], str);
	i = 0;
	while (str[i] != NULL)
	{
		ft_atoi(str[i], checkptr);
		if (*checkptr == -1)
			ft_free_stack1(str, stack_a);
		if (i == 0)
			stack_a = newstack(ft_atoi(str[i], checkptr));
		else
			stack_add_bottom(&stack_a, newstack(ft_atoi(str[i], checkptr)));
		i++;
	}
	i = 0;
	while (str[i] != NULL)
		free(str[i++]);
	free(str);
	return (stack_a);
}
