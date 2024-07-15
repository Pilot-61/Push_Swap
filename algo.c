/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 03:52:49 by mes-salh          #+#    #+#             */
/*   Updated: 2024/07/15 23:40:10 by mes-salh         ###   ########.fr       */
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

void ft_sendback(t_list **stack_a, t_list **stack_b)
{
    int biggest;
    int pos;
    int size;

    while (*stack_b)
    {
        positioning(*stack_b);
        biggest = find_biggest(*stack_b);
        pos = find_position(*stack_b, biggest);
        size = ft_lstsize(*stack_b);

        if (pos <= size / 2)
        {
            while ((*stack_b)->content != biggest)
                reverse(NULL, stack_b, RB);
        }
        else
        {
            while ((*stack_b)->content != biggest)
                reverse_rt(NULL, stack_b, RRB);
        }
        push_a(stack_a, stack_b);
    }
}

void sort_l(t_list **stack_a, t_list **stack_b)
{
    int i = 0;
    int chunk_size;
    int size = ft_lstsize(*stack_a);
    
    if (size <= 100)
        chunk_size = 15;
    else
        chunk_size = 30;
    
    while (*stack_a)
    {
        if ((*stack_a)->index <= i)
        {
            push_b(stack_a, stack_b);
            reverse(NULL, stack_b, RB);
            i++;
        }
        else if ((*stack_a)->index <= i + chunk_size)
        {
            push_b(stack_a, stack_b);
            i++;
        }
        else
            reverse(stack_a, NULL, RA);
    }
    ft_sendback(stack_a, stack_b);
}