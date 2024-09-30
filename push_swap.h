/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:05:48 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/09 17:05:48 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}	t_list;

void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_split(char const *s, char sep);
int		ft_atoi(const char *str, int *checkptr);

t_list	*ft_init_stack_1(char **av, t_list *stack_a);
t_list	*ft_init_stack_2(int ac, char **av, t_list *stack_a);

void	ft_index(t_list *stack_a, long *array);
long	*createarray(t_list *stack_a);
long	*selectionsort(long *array, int size);

t_list	*get_list_bottom(t_list *stack);
t_list	*newstack(int value);
void	stack_add_bottom(t_list **stack, t_list *new);
int		stack_size(t_list *head);

void	rotate(t_list **stack);
void	do_ra(t_list **stack_a);
void	do_rb(t_list **stack_b);
void	do_pa(t_list **stack_a, t_list **stack_b);
void	do_pb(t_list **stack_a, t_list **stack_b);
void	do_sa(t_list **stack_a);

int		is_sorted(t_list *head);
void	ft_radix_sort(t_list **stack_a, t_list **stack_b);
void	ft_sort_small_3(t_list **stack_a);
void	ft_sort_small_5(t_list **stack_a, t_list **stack_b);

void	free_stack(t_list *stack_a, t_list *stack_b, long *array);

#endif