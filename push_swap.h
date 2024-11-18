/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:21:13 by ykisibek          #+#    #+#             */
/*   Updated: 2024/03/26 16:21:15 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	int				content;
	unsigned int	index;
	struct s_list	*next;
}		t_list;

int				ft_strcmp(const char *str1, const char *str2);
void			do_swap(char *str, t_list **stack_a, t_list **stack_b);
unsigned int	ft_tqrt(unsigned int nb);
unsigned int	ft_sqrt(unsigned int nb);
unsigned int	find_n(unsigned int size);
void			sort_in_stack_a(t_list **stack_a, t_list **stack_b);
void			pass_to_stack_b(t_list **stack_a, t_list **stack_b);
int				is_empty(int argc, char **argv);
void			butterfly(t_list **stack_a, t_list **stack_b);
unsigned int	get_max_index(t_list **stack_a);
unsigned int	get_min_index(t_list **stack_a);
unsigned int	get_position(unsigned int index, t_list **stack_a);
int				is_sorted(t_list **stack_a);
void			sort_2(t_list **stack_a);
void			sort_3(t_list **stack_a);
void			sort_4(t_list **stack_a, t_list **stack_b);
void			sort_5(t_list **stack_a, t_list **stack_b);
void			do_sort(t_list **stack_a, t_list **stack_b);
void			printf_list_nodes(t_list *list);
void			fin_sort(int *sort, unsigned int size);
void			get_index(int *sort, t_list **stack_a);
int				*sorted_stack(t_list **stack_a);
int				fill_node(t_list **stack_a, char **num);
long long int	ps_atoi(char *str, t_list **stack_a);
int				ft_count(char const *str);
char			*ft_fill_words(const char *s);
char			**ft_split(char const *s);
int				validate(int argc, char **argv);
int				fill_stack_a(int size, char **nums, t_list **stack_a);
void			free_array(char **num);
unsigned int	ft_lstsize(t_list **lst);
t_list			*ft_lstnew(int content);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstclear(t_list **lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				find_similar(t_list **stack_a, int n);
void			sa(t_list *stack_a, int i);
void			sb(t_list *stack_b, int i);
void			ss(t_list *stack_a, t_list *stack_b, int i);
void			pa(t_list **stack_a, t_list **stack_b, int i);
void			pb(t_list **stack_a, t_list **stack_b, int i);
void			ra(t_list **stack_a, int i);
void			rb(t_list **stack_b, int i);
void			rr(t_list **stack_a, t_list **stack_b, int i);
void			rra(t_list **stack_a, int i);
void			rrb(t_list **stack_b, int i);
void			rrr(t_list **stack_a, t_list **stack_b, int i);
char			*get_next_line(int fd);
int				ft_strlcpy(char *dest, char *src, int size);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(char *s1);
char			*ft_strchr(char *str, int c);
int				ft_strlen(char *str);
char			*free_from_nl(char *line);
int				count_nl(char *line);
char			*fill_line(char *line, int fd);
void			free_line(char *str);

#endif