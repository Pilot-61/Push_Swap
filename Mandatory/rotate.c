/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 04:46:33 by mes-salh          #+#    #+#             */
/*   Updated: 2024/07/14 23:23:07 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rev(t_list **stack)
{
	t_list	*tmp;

	if (!*stack)
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
	return (1);
}

int	reverse(t_list **stack_a, t_list **stack_b, int flag)
{
	if (flag == 0)
	{
		if (!rev(stack_a))
			return (0);
		ft_putstr(1, "ra");
	}
	else if (flag == 1)
	{
		if (!rev(stack_b))
			return (0);
		ft_putstr(1, "rb");
	}
	else if (flag == 2)
	{
		if (!rev(stack_a) || !rev(stack_b))
			return (0);
		ft_putstr(1, "rr");
	}
	return (1);
}
