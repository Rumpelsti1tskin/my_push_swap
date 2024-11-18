/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:28:07 by ykisibek          #+#    #+#             */
/*   Updated: 2024/04/18 15:28:09 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pass_to_stack_b(t_list **stack_a, t_list **stack_b)
{
	unsigned int	counter;
	unsigned int	size;

	counter = 0;
	size = ft_lstsize(stack_a);
	while (counter < size)
	{
		while (*stack_a)
		{
			if ((*stack_a)->index <= counter)
			{
				pb(stack_a, stack_b, 1);
				rb(stack_b, 1);
				counter++;
			}
			else if ((*stack_a)->index <= counter + find_n(size))
			{
				pb(stack_a, stack_b, 1);
				counter++;
			}
			else
				ra(stack_a, 1);
		}
	}
}

void	sort_in_stack_a(t_list **stack_a, t_list **stack_b)
{
	unsigned int	max_index;
	unsigned int	position;
	unsigned int	size;

	while (*stack_b)
	{
		max_index = get_max_index(stack_b);
		position = get_position(max_index, stack_b);
		size = ft_lstsize(stack_b);
		if (position == 1)
			pa(stack_a, stack_b, 1);
		else if (position >= size / 2)
			rrb(stack_b, 1);
		else
			rb(stack_b, 1);
	}
}

void	butterfly(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(stack_a) == 1)
		return ;
	pass_to_stack_b(stack_a, stack_b);
	sort_in_stack_a(stack_a, stack_b);
}
