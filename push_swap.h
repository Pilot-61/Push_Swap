/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 23:55:21 by mes-salh          #+#    #+#             */
/*   Updated: 2024/07/12 01:36:17 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libc.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	ft_lstadd_back(t_list **lst, t_list *news);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(void *content);
char	*ft_strjoin(int size, char **strs, char *sep);
void	ft_putstr(char *s);
char	**ft_split(char const *s, char c);
void	mes_pars(char *str);
int		ft_atoi(const char *str);
#endif