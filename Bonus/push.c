/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 00:57:34 by mes-salh          #+#    #+#             */
/*   Updated: 2024/07/17 04:00:57 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

int	push_it(t_list **s_from, t_list **s_to)
{
	t_list	*tmp;

	if (!*s_from || !s_from)
		return (0);
	tmp = *s_from;
	*s_from = (*s_from)->next;
	tmp->next = NULL;
	ft_lstadd_front(s_to, tmp);
	return (1);
}

int	push_a(t_list **stack_a, t_list **stack_b)
{
	if (!push_it(stack_b, stack_a))
		return (0);
	return (1);
}

int	push_b(t_list **stack_a, t_list **stack_b)
{
	if (!push_it(stack_a, stack_b))
		return (0);
	return (1);
}
