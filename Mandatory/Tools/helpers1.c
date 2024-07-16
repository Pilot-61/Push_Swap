/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:23:53 by mes-salh          #+#    #+#             */
/*   Updated: 2024/07/16 04:01:32 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_smallest(t_list	*head)
{
	int		smallest;

	smallest = INT_MAX;
	while (head)
	{
		if (head->content < smallest)
			smallest = head->content;
		head = head->next;
	}
	return (smallest);
}

void	positioning(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->pos = i;
		i++;
		stack = stack->next;
	}
}

int	find_position(t_list *stack, int smallest)
{
	while (stack)
	{
		if (stack->content == smallest)
			return (stack->pos);
		stack = stack->next;
	}
	return (-1);
}
