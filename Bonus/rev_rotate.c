/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 04:46:36 by mes-salh          #+#    #+#             */
/*   Updated: 2024/07/17 00:29:19 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

int	rev_rot(t_list **stack)
{
	t_list	*tmp;
	t_list	*curr;

	if (!(*stack) || !stack)
		return (0);
	curr = *stack;
	tmp = ft_lstlast(*stack);
	while (curr->next->next)
		curr = curr->next;
	curr->next = NULL;
	ft_lstadd_front(stack, tmp);
	return (1);
}

int	reverse_rt(t_list **stack_a, t_list **stack_b, int flag)
{
	if (flag == 3)
	{
		if (!rev_rot(stack_a))
			return (0);
	}
	else if (flag == 4)
	{
		if (!rev_rot(stack_b))
			return (0);
	}
	else if (flag == 5)
	{
		if (!rev_rot(stack_b) || !rev_rot(stack_a))
			return (0);
	}
	return (1);
}
