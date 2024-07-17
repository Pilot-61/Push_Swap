/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 04:46:15 by mes-salh          #+#    #+#             */
/*   Updated: 2024/07/17 00:29:53 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

int	swap_s(t_list **stack)
{
	t_list	*tmp;

	if (!(*stack) || !stack)
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	return (1);
}

int	swap_x(t_list **stack_a, t_list **stack_b, int flag)
{
	if (flag == 6)
	{
		if (!swap_s(stack_a))
			return (0);
	}
	else if (flag == 7)
	{
		if (!swap_s(stack_b))
			return (0);
	}
	else if (flag == 8)
	{
		if (!swap_s(stack_a) || !swap_s(stack_b))
			return (0);
	}
	return (1);
}
