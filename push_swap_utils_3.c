/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:33:22 by ykisibek          #+#    #+#             */
/*   Updated: 2024/04/17 18:33:23 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list **stack_a)
{
	t_list	*node;

	if (!stack_a || !((*stack_a)))
		return (0);
	node = *stack_a;
	while (node->next != NULL)
	{
		if (node->index == node->next->index - 1)
			node = node->next;
		else
			return (0);
	}
	return (1);
}

unsigned int	get_position(unsigned int index, t_list **stack_a)
{
	unsigned int	position;
	t_list			*node;

	position = 1;
	node = *stack_a;
	while (node)
	{
		if (node->index == index)
			return (position);
		node = node->next;
		position++;
	}
	return (0);
}

unsigned int	get_max_index(t_list **stack_a)
{
	unsigned int	i;
	t_list			*node;

	if (!stack_a || !(*stack_a))
		return (0);
	i = 0;
	node = *stack_a;
	while (node)
	{
		if (node->index > i)
			i = node->index;
		node = node->next;
	}
	return (i);
}

unsigned int	get_min_index(t_list **stack_a)
{
	unsigned int	i;
	t_list			*node;

	if (!stack_a || !(*stack_a))
		return (0);
	i = get_max_index(stack_a);
	node = *stack_a;
	while (node)
	{
		if (node->index < i)
			i = node->index;
		node = node->next;
	}
	return (i);
}

int	is_empty(int argc, char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	j = 0;
	while (i < argc)
	{
		count = 0;
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				count++;
			j++;
		}
		if (count == 0)
			return (0);
		i++;
	}
	return (1);
}
