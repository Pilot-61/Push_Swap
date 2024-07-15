/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 23:55:21 by mes-salh          #+#    #+#             */
/*   Updated: 2024/07/15 01:27:20 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libc.h"

typedef struct s_list
{
	int				content;
	int				pos;
	struct s_list	*next;
}	t_list;

# define RA	0
# define RB	1
# define RR	2
# define RRA	3
# define RRB	4
# define RRR	5
# define SA	6
# define SB	7
# define SS	8

// print stack
void	print_stack(t_list *stack, int state);

void	ft_lstadd_back(t_list **lst, t_list *news);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int content);
char	*ft_strjoin(int size, char **strs, char *sep);
void	ft_putstr(int fd, char *s);
char	**ft_split(char const *s, char c);
int		mes_pars(char *str);
int		ft_atoi(const char *str);
void	free_arr(char **arr);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	swap(int *a, int *b);
int		check_dup(int *nbrs, int n);
int		fill_stack(t_list **stack, char **av);
int		mes_len(const char *s, char c);
int		push_it(t_list **s_from, t_list **s_to);
int		push_a(t_list **stack_a, t_list **stack_b);
int		push_b(t_list **stack_a, t_list **stack_b);
void	free_stack(t_list **stack);
int		rev(t_list **stack);
int		reverse(t_list **stack_a, t_list **stack_b, int flag);
t_list	*ft_lstlast(t_list *lst);
int		reverse_rt(t_list **stack_a, t_list **stack_b, int flag);
int		rev_rot(t_list **stack);
int		swap_s(t_list **stack);
int		swap_x(t_list **stack_a, t_list **stack_b, int flag);
int		is_sorted(t_list *stack);
void	sort_it(t_list **stack_a, t_list **stack_b, int size);
void	sort_fo(t_list **stack_a, t_list **stack_b);
int		find_smallest(t_list	*head);
void	positioning(t_list *stack);
int		find_smallest(t_list	*head);
int		find_position(t_list *stack, int smallest);
void	sort_fi(t_list **stack_a, t_list **stack_b);
#endif