/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 02:17:20 by mes-salh          #+#    #+#             */
/*   Updated: 2024/07/17 01:51:20 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	is_sorted(t_list *stack)
{
	if (!stack)
		return (-1);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_putstr(int fd, char *s)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	check_it(t_opp *tmp, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strcmp(tmp->ptr, "pa\n"))
		push_a(stack_a, stack_b);
	else if (!ft_strcmp(tmp->ptr, "pb\n"))
		push_b(stack_a, stack_b);
	else if (!ft_strcmp(tmp->ptr, "sa\n"))
		swap_x(stack_a, stack_b, SA);
	else if (!ft_strcmp(tmp->ptr, "sb\n"))
		swap_x(stack_a, stack_b, SB);
	else if (!ft_strcmp(tmp->ptr, "ss\n"))
		swap_x(stack_a, stack_b, SS);
	else if (!ft_strcmp(tmp->ptr, "ra\n"))
		reverse(stack_a, stack_b, RA);
	else if (!ft_strcmp(tmp->ptr, "rb\n"))
		reverse(stack_a, stack_b, RB);
	else if (!ft_strcmp(tmp->ptr, "rr\n"))
		reverse_rt(stack_a, stack_b, RR);
	else if (!ft_strcmp(tmp->ptr, "rra\n"))
		reverse_rt(stack_a, stack_b, RRA);
	else if (!ft_strcmp(tmp->ptr, "rrb\n"))
		reverse_rt(stack_a, stack_b, RRB);
	else if (!ft_strcmp(tmp->ptr, "rrr\n"))
		reverse_rt(stack_a, stack_b, RRR);
}

void	make_instractions(t_list **stack_a, t_list **stack_b, t_opp **opp)
{
	t_opp	*tmp;

	tmp = *opp;
	while (tmp)
	{
		check_it(tmp, stack_a, stack_b);
		tmp = tmp->next;
	}
}
