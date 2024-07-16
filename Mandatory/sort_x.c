/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 01:24:09 by mes-salh          #+#    #+#             */
/*   Updated: 2024/07/16 03:37:23 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_fo(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		smallest;
	int		pos;

	tmp = *stack_a;
	positioning(*stack_a);
	smallest = find_smallest(tmp);
	pos = find_position(*stack_a, smallest);
	while ((*stack_a)->content != smallest)
	{
		if (pos < 2)
			reverse(stack_a, stack_b, RA);
		else if (pos >= 2)
			reverse_rt(stack_a, stack_b, RRA);
	}
	push_b(stack_a, stack_b);
	sort_it(stack_a, stack_b, 3);
	push_a(stack_a, stack_b);
}

void	sort_fi(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		smallest;
	int		pos;

	tmp = *stack_a;
	positioning(*stack_a);
	smallest = find_smallest(tmp);
	pos = find_position(*stack_a, smallest);
	while ((*stack_a)->content != smallest)
	{
		if (pos < 2)
			reverse(stack_a, stack_b, RA);
		else if (pos >= 2)
			reverse_rt(stack_a, stack_b, RRA);
	}
	push_b(stack_a, stack_b);
	sort_fo(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	sort_it(t_list **stack_a, t_list **stack_b, int size)
{
	t_list	*curr;

	if (size == 2)
	{
		swap_x(stack_a, NULL, SA);
		return ;
	}
	else if (size == 3)
	{
		curr = *stack_a;
		if (curr->content > curr->next->content
			&& curr->content > curr->next->next->content)
			reverse(stack_a, NULL, RA);
		else if (curr->next->content > curr->content
			&& curr->next->content > curr->next->next->content)
			reverse_rt(stack_a, NULL, RRA);
		if ((*stack_a)->content > (*stack_a)->next->content)
			swap_x(stack_a, NULL, SA);
	}
	else if (size == 4)
		sort_fo(stack_a, stack_b);
	else if (size == 5)
		sort_fi(stack_a, stack_b);
	else
		sort_l(stack_a, stack_b);
}
