/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:04:43 by ykisibek          #+#    #+#             */
/*   Updated: 2024/04/13 14:04:45 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack_a, int i)
{
	t_list	*node;
	t_list	*node1;

	if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return ;
	node = (*stack_a);
	while (node->next->next != NULL)
		node = node->next;
	node1 = node->next;
	node->next = NULL;
	node1->next = *stack_a;
	*stack_a = node1;
	if (i == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b, int i)
{
	t_list	*node;
	t_list	*node1;

	if (!stack_b || !(*stack_b) || !((*stack_b)->next))
		return ;
	node = (*stack_b);
	while (node->next->next != NULL)
		node = node->next;
	node1 = node->next;
	node->next = NULL;
	node1->next = *stack_b;
	*stack_b = node1;
	if (i == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b, int i)
{
	t_list	*node;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	if (!stack_a || !(*stack_a) || !((*stack_a)->next)
		|| !stack_b || !(*stack_b) || !((*stack_b)->next))
		return ;
	node = (*stack_a);
	while (node->next->next != NULL)
		node = node->next;
	node1 = node->next;
	node->next = NULL;
	node1->next = *stack_a;
	*stack_a = node1;
	node2 = (*stack_b);
	while (node2->next->next != NULL)
		node2 = node2->next;
	node3 = node2->next;
	node2->next = NULL;
	node3->next = *stack_b;
	*stack_b = node3;
	if (i == 1)
		write(1, "rrr\n", 4);
}
