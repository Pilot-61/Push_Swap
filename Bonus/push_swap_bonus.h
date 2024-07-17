/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:19:27 by mes-salh          #+#    #+#             */
/*   Updated: 2024/07/17 04:15:29 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				pos;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_opp
{
	char			*ptr;
	struct s_opp	*next;
}	t_opp;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# define RA	0
# define RB	1
# define RR	2
# define RRA 3
# define RRB 4
# define RRR 5
# define SA	6
# define SB	7
# define SS	8

char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
int		ft_strcmp(char	*s1, char *s2);
void	ft_free(char **ptr);
char	*ft_get_the_next(char *buffer);
char	*ft_get_the_line(char *buffer);
char	*ft_read_line(int fd, char *resultat);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoinv1(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
int		ft_lstadd_back(t_list **lst, t_list *news);
int		ft_lstsize(t_list *lst);
t_opp	*ft_lstnewv2(char *content);
t_list	*ft_lstnew(int content);
void	make_instractions(t_list **stack_a, t_list **stack_b, t_opp **opp);
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
int		check_opp(t_opp **opp);
void	free_stack(t_list **stack);
void	fr_stack(t_opp **opp);
int		rev(t_list **stack);
int		reverse(t_list **stack_a, t_list **stack_b, int flag);
t_list	*ft_lstlast(t_list *lst);
int		reverse_rt(t_list **stack_a, t_list **stack_b, int flag);
int		rev_rot(t_list **stack);
int		swap_s(t_list **stack);
int		swap_x(t_list **stack_a, t_list **stack_b, int flag);
int		is_sorted(t_list *stack);
#endif