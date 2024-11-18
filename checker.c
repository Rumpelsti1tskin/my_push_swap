/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:38:40 by ykisibek          #+#    #+#             */
/*   Updated: 2024/04/19 18:38:41 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_error(int i)
{
	i = 0;
	write(2, "Error\n", 6);
	exit (0);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t			a;
	unsigned char	*s1;
	unsigned char	*s2;

	a = 0;
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (s1[a] != '\0' || s2[a] != '\0')
	{
		if (s1[a] != s2[a])
			return (s1[a] - s2[a]);
		a++;
	}
	return (0);
}

void	do_swap(char *str, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(str, "sa\n") == 0)
		sa(*stack_a, 0);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb(*stack_b, 0);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(*stack_a, *stack_b, 0);
	else if (ft_strcmp(str, "pa\n") == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "ra\n") == 0)
		ra(stack_a, 0);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb(stack_b, 0);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra(stack_a, 0);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb(stack_b, 0);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(stack_a, stack_b, 0);
	else
		do_error(1);
}

int	main(int argc, char **argv)
{
	char	*str;
	t_list	*stack_a;
	t_list	*stack_b;

	if (validate(argc, argv) == 0)
		do_error(1);
	stack_a = NULL;
	stack_b = NULL;
	if (fill_stack_a(argc, argv, &stack_a) == 0)
		do_error(1);
	str = get_next_line(0);
	while (str)
	{
		do_swap(str, &stack_a, &stack_b);
		free(str);
		str = get_next_line(0);
	}
	if (is_sorted(&stack_a) == 1 && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
