/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 03:52:49 by mes-salh          #+#    #+#             */
/*   Updated: 2024/07/15 06:08:32 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_biggest(t_list	*head)
{
	int		bigesst;

	bigesst = INT_MIN;
	while (head)
	{
		if (head->content > bigesst)
			bigesst = head->content;
		head = head->next;
	}
	return (bigesst);
}

void    ft_repeate(t_list **stack, int pos)
{
    int size;
    int half;
    int i;

    size = ft_lstsize(*stack);
    half = size / 2;
    i = size - pos;
    if (pos <= half)
        while (pos--)
            reverse(NULL, stack, RB);
    else if (pos > half)
        while (i--)
            reverse_rt(NULL, stack, RRB);
}

void    ft_sendback(t_list **stack_a, t_list **stack_b)
{
	int		bigesst;
	int		pos;
    int     half;

    while (ft_lstsize(*stack_b))
    {
	    positioning(*stack_b);
	    bigesst = find_biggest(*stack_b);
	    pos = find_position(*stack_b, bigesst);
        half = ft_lstsize(*stack_b)/2;
        ft_repeate(stack_b, pos);
        push_a(stack_a, stack_b);
    }
}


void    sort_l(t_list **stack_a, t_list **stack_b)
{
    int i;
    int pv;
    int size;
    
    i = 0;
    size = ft_lstsize(*stack_b);
    if (size <= 100)
        pv = 16;
    else
        pv = 33;
    while (*stack_a)
    {
        if((*stack_a)->index <= i)
        {
            push_b(stack_a, stack_b);
            i++;
        }
        else if ((*stack_a)->index <= i + pv)
        {
            push_b(stack_a, stack_b);
            reverse(stack_a, stack_b, RB);
            i++;
        }
        else
            reverse(stack_a, stack_b, RA);
    }
    ft_sendback(stack_a, stack_b);
}