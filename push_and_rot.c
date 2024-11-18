/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_rot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:05:09 by ykisibek          #+#    #+#             */
/*   Updated: 2024/04/13 14:05:10 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b, int i)
{
	t_list	*node;

	if (!stack_b || !(*stack_b))
		return ;
	node = *stack_b;
	*stack_b = (*stack_b)->next;
	node->next = *stack_a;
	*stack_a = node;
	if (i == 1)
		write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b, int i)
{
	t_list	*node;

	if (!stack_a || !(*stack_a))
		return ;
	node = *stack_a;
	*stack_a = (*stack_a)->next;
	node->next = *stack_b;
	*stack_b = node;
	if (i == 1)
		write(1, "pb\n", 3);
}

void	ra(t_list **stack_a, int i)
{
	t_list	*node;
	t_list	*last;

	if (!(*stack_a) || !((*stack_a)->next))
		return ;
	node = *stack_a;
	*stack_a = (*stack_a)->next;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = node;
	node->next = NULL;
	if (i == 1)
		write(1, "ra\n", 3);
}

void	rb(t_list **stack_b, int i)
{
	t_list	*node;
	t_list	*last;

	if (!(*stack_b) || !((*stack_b)->next))
		return ;
	node = *stack_b;
	*stack_b = (*stack_b)->next;
	last = *stack_b;
	while (last->next)
		last = last->next;
	last->next = node;
	node->next = NULL;
	if (i == 1)
		write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b, int i)
{
	t_list	*node;
	t_list	*last;
	t_list	*node1;
	t_list	*last1;

	if (!(*stack_a) || !((*stack_a)->next)
		|| !(*stack_b) || !((*stack_b)->next))
		return ;
	node = *stack_a;
	*stack_a = (*stack_a)->next;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = node;
	node->next = NULL;
	node1 = *stack_b;
	*stack_b = (*stack_b)->next;
	last1 = *stack_b;
	while (last1->next)
		last1 = last1->next;
	last1->next = node1;
	node1->next = NULL;
	if (i == 1)
		write(1, "rr\n", 3);
}
