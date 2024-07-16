/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 03:52:59 by mes-salh          #+#    #+#             */
/*   Updated: 2024/07/16 03:44:57 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallestv2(t_list *head)
{
	int	smallest;

	smallest = INT_MAX;
	while (head)
	{
		if (head->content < smallest && head->index == -3)
			smallest = head->content;
		head = head->next;
	}
	return (smallest);
}

void	find_positionv2(t_list *stack, int smallest, int index)
{
	while (stack)
	{
		if (stack->content == smallest && stack->index == -3)
		{
			stack->index = index;
			break ;
		}
		stack = stack->next;
	}
}

void	index_smallest(t_list **stack_a)
{
	t_list	*tmp;
	int		smallest;
	int		i;
	int		size;

	tmp = *stack_a;
	i = 0;
	size = ft_lstsize(tmp);
	while (i < size)
	{
		smallest = find_smallestv2(tmp);
		find_positionv2(tmp, smallest, i);
		i++;
	}
}
