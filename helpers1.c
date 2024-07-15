/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:23:53 by mes-salh          #+#    #+#             */
/*   Updated: 2024/07/15 01:24:29 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *stack, int state)
{
	if (state == 0)
		printf("stack_a: ");
	else if (state == 1)
		printf("stack_b: ");
	while (stack)
	{
		printf("%d\t", stack->content);
		stack = stack->next;
	}
	printf("\n");
}

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
