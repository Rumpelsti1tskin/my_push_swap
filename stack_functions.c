/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:05:46 by ykisibek          #+#    #+#             */
/*   Updated: 2024/04/10 18:05:49 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	ft_lstsize(t_list **lst)
{
	int		count;
	t_list	*node;

	node = *lst;
	count = 0;
	while (node)
	{
		count++;
		node = node->next;
	}
	return (count);
}

t_list	*ft_lstnew(int content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*nextnode;

	if (!lst || *lst == NULL)
		return ;
	if ((*lst)->next == NULL)
	{
		free(*lst);
		return ;
	}
	while (*lst != NULL)
	{
		nextnode = (*lst)->next;
		free(*lst);
		*lst = nextnode;
	}
	lst = NULL;
}

void	free_array(char **num)
{
	char	**ptr;

	if (!num)
		return ;
	ptr = num;
	while (*ptr)
	{
		free (*ptr);
		ptr++;
	}
	free (num);
}
