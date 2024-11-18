/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:05:18 by ykisibek          #+#    #+#             */
/*   Updated: 2024/04/13 14:05:19 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *stack_a, int i)
{
	int				temp;
	unsigned int	tmp;

	if (!stack_a || !stack_a->next)
		return ;
	temp = stack_a->content;
	tmp = stack_a->index;
	stack_a->content = stack_a->next->content;
	stack_a->index = stack_a->next->index;
	stack_a->next->content = temp;
	stack_a->next->index = tmp;
	if (i == 1)
		write(1, "sa\n", 3);
}

void	sb(t_list *stack_b, int i)
{
	int				temp;
	unsigned int	tmp;

	if (!stack_b || !stack_b->next)
		return ;
	temp = stack_b->content;
	tmp = stack_b->index;
	stack_b->content = stack_b->next->content;
	stack_b->index = stack_b->next->index;
	stack_b->next->content = temp;
	stack_b->next->index = tmp;
	if (i == 1)
		write(1, "sa\n", 3);
}

void	ss(t_list *stack_a, t_list *stack_b, int i)
{
	int				temp;
	unsigned int	tmp;
	int				temp1;
	unsigned int	tmp1;

	if (!stack_a || !stack_a->next || !stack_b || !stack_b->next)
		return ;
	temp = stack_a->content;
	tmp = stack_a->index;
	stack_a->content = stack_a->next->content;
	stack_a->index = stack_a->next->index;
	stack_a->next->content = temp;
	stack_a->next->index = tmp;
	temp1 = stack_b->content;
	tmp1 = stack_b->index;
	stack_b->content = stack_b->next->content;
	stack_b->index = stack_b->next->index;
	stack_b->next->content = temp1;
	stack_b->next->index = tmp1;
	if (i == 1)
		write(1, "ss\n", 3);
}

void	printf_list_nodes(t_list *list)
{
	while (list)
	{
		printf("content = %d\n", list->content);
		printf("index = %d\n", list->index);
		list = list->next;
	}
}
