/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:29:01 by ykisibek          #+#    #+#             */
/*   Updated: 2024/04/10 20:29:03 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ps_atoi(char *str, t_list **stack_a)
{
	long long int	number;
	long long int	sign;

	sign = 1;
	number = 0;
	while (*str == 32 || (9 <= *str && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		number = 10 * number + (*str - '0');
		str++;
	}
	if ((sign * number) < INT_MIN || (sign * number) > INT_MAX)
	{
		write(2, "Error\n", 6);
		ft_lstclear(stack_a);
		exit(0);
	}
	return (sign * number);
}

int	find_similar(t_list **stack_a, int n)
{
	t_list	*check;

	check = *stack_a;
	while (*stack_a != NULL)
	{
		if (n == (*stack_a)->content)
		{
			*stack_a = check;
			return (0);
		}
		*stack_a = (*stack_a)->next;
	}
	*stack_a = check;
	return (1);
}

void	fin_sort(int *sort, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (sort[j] > sort[j + 1])
			{
				tmp = sort[j + 1];
				sort[j + 1] = sort[j];
				sort[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*sorted_stack(t_list **stack_a)
{
	int				*sort;
	unsigned int	i;
	unsigned int	size;
	t_list			*node;

	i = 0;
	node = *stack_a;
	size = ft_lstsize(stack_a);
	sort = (int *)malloc(size * sizeof(int));
	if (!sort)
		return (NULL);
	while (i < size)
	{
		sort[i] = node->content;
		node = node->next;
		i++;
	}
	fin_sort(sort, size);
	return (sort);
}

void	get_index(int *sort, t_list **stack_a)
{
	unsigned int	i;
	unsigned int	size;
	t_list			*node;

	i = 0;
	size = ft_lstsize(stack_a);
	node = *stack_a;
	while (node)
	{
		while (i < size)
		{
			if (sort[i] == node->content)
			{
				node->index = i;
				break ;
			}
			i++;
		}
		node = node->next;
		i = 0;
	}
}
