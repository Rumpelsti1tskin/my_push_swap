/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:19:30 by ykisibek          #+#    #+#             */
/*   Updated: 2024/04/17 17:19:31 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_list **stack_a)
{
	t_list	*node;

	node = *stack_a;
	if (node->index > node->next->index)
		sa(*stack_a, 1);
}

void	sort_3(t_list **stack_a)
{
	t_list			*node;
	unsigned int	max_index;
	unsigned int	min_index;

	max_index = get_max_index(stack_a);
	min_index = get_min_index(stack_a);
	while (is_sorted(stack_a) == 0)
	{
		node = *stack_a;
		if (node->index == max_index)
			ra(stack_a, 1);
		else if (node->index == min_index && node->next->index == max_index)
			sa(*stack_a, 1);
		else if ((node->index > min_index && node->index < max_index)
			&& node->next->index == min_index)
			sa(*stack_a, 1);
		else if (node->next->next->index == min_index)
			rra(stack_a, 1);
	}
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	unsigned int	i;
	unsigned int	size;
	unsigned int	min_index;

	min_index = get_min_index(stack_a);
	i = get_position(min_index, stack_a);
	size = ft_lstsize(stack_a);
	if (i <= size / 2)
	{
		while ((*stack_a)->index != min_index)
			ra(stack_a, 1);
	}
	else
	{
		while ((*stack_a)->index != min_index)
			rra(stack_a, 1);
	}
	if (!is_sorted(stack_a))
	{
		pb(stack_a, stack_b, 1);
		sort_3(stack_a);
		pa(stack_a, stack_b, 1);
	}
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	unsigned int	i;
	unsigned int	size;
	unsigned int	min_index;

	min_index = get_min_index(stack_a);
	i = get_position(min_index, stack_a);
	size = ft_lstsize(stack_a);
	if (i <= size / 2)
	{
		while ((*stack_a)->index != min_index)
			ra(stack_a, 1);
	}
	else
	{
		while ((*stack_a)->index != min_index)
			rra(stack_a, 1);
	}
	if (!is_sorted(stack_a))
	{
		pb(stack_a, stack_b, 1);
		sort_4(stack_a, stack_b);
		pa(stack_a, stack_b, 1);
	}
}

void	do_sort(t_list **stack_a, t_list **stack_b)
{
	unsigned int	size;

	size = ft_lstsize(stack_a);
	if (size == 1)
		return ;
	else if (size == 2)
		sort_2(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
	else
		butterfly(stack_a, stack_b);
}
