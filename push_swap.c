/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:21:07 by ykisibek          #+#    #+#             */
/*   Updated: 2024/03/26 16:21:10 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (validate(argc, argv) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (fill_stack_a(argc, argv, &stack_a) == 0)
	{
		write(2, "Error\n", 6);
		ft_lstclear(&stack_a);
		return (0);
	}
	do_sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
