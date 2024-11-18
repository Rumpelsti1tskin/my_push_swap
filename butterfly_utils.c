/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:29:07 by ykisibek          #+#    #+#             */
/*   Updated: 2024/04/19 18:29:10 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	ft_tqrt(unsigned int nb)
{
	unsigned int	min;
	unsigned int	max;
	unsigned int	a;

	min = 1;
	max = nb;
	if (nb == 1)
		return (1);
	while (max - min > 1)
	{
		a = (min + max) / 2;
		if (a >= 46341)
			max = a;
		else if (a * a * a == nb)
			return (a);
		else if (a * a * a < nb)
			min = a;
		else if (a * a * a > nb)
			max = a;
	}
	return (a);
}

unsigned int	ft_sqrt(unsigned int nb)
{
	unsigned int	min;
	unsigned int	max;
	unsigned int	a;

	min = 1;
	max = nb;
	if (nb == 1)
		return (1);
	while (max - min > 1)
	{
		a = (min + max) / 2;
		if (a >= 46341)
			max = a;
		else if (a * a == nb)
			return (a);
		else if (a * a < nb)
			min = a;
		else if (a * a > nb)
			max = a;
	}
	return (a);
}

unsigned int	find_n(unsigned int size)
{
	unsigned int	num;

	num = ft_sqrt(size) + ft_tqrt(size);
	return (num);
}
