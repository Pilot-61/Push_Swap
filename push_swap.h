/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 23:55:21 by mes-salh          #+#    #+#             */
/*   Updated: 2024/07/13 00:49:29 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libc.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

void	ft_lstadd_back(t_list **lst, t_list *news);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int content);
char	*ft_strjoin(int size, char **strs, char *sep);
void	ft_putstr(int fd, char *s);
char	**ft_split(char const *s, char c);
int		mes_pars(char *str, t_list *stack_a);
int		ft_atoi(const char *str);
void	free_arr(char **arr);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	swap(int a, int b);
int		check_dup(int *nbrs, int n);
void	fill_stack(t_list *stack, int *nbrs, int size);
#endif