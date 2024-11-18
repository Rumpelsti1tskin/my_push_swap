/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:13:32 by ykisibek          #+#    #+#             */
/*   Updated: 2024/04/19 19:13:33 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc == 1)
		exit (0);
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			if ((argv[i][j]) != 32 && !(argv[i][j] >= 9 && argv[i][j] <= 13)
				&& !(argv[i][j] >= '0' && argv[i][j] <= '9')
				&& !(argv[i][j] == '-' || argv[i][j] == '+'))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	if (is_empty(argc, argv) == 0)
		return (0);
	return (1);
}

int	check(char *str)
{
	int	len;

	len = 0;
	if ((*str == '+' || *str == '-') && *(str + 1) != '\0')
		str++;
	while (*str == '0' && (*(str + 1) >= '0' && *(str + 1) <= '9'))
		str++;
	while (*(str + len) >= '0' && *(str + len) <= '9')
		len++;
	if (*(str + len) != '\0' || len > 11)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	return (1);
}

int	fill_node(t_list **stack_a, char **num)
{
	int		i;
	int		n;
	t_list	*node;

	i = 0;
	while (num[i])
	{
		check(num[i]);
		n = (int)ps_atoi(num[i], stack_a);
		if (find_similar(stack_a, n) == 0)
		{
			write(2, "Error\n", 6);
			free_array(num);
			exit (0);
		}
		node = ft_lstnew(n);
		ft_lstadd_back(stack_a, node);
		i++;
	}
	return (1);
}

int	fill_stack_a(int size, char **nums, t_list **stack_a)
{
	int		i;
	char	**num;
	int		*sort;

	i = 1;
	while (i < size)
	{
		num = ft_split(nums[i]);
		if (!num)
			return (0);
		fill_node(stack_a, num);
		free_array(num);
		num = NULL;
		i++;
	}
	sort = sorted_stack(stack_a);
	if (!sort)
		return (0);
	get_index(sort, stack_a);
	free(sort);
	return (1);
}
