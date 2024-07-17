/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpersv2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:08:54 by mes-salh          #+#    #+#             */
/*   Updated: 2024/07/17 01:27:33 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	ft_cmp(char *line)
{
	if (!ft_strcmp(line, "ra\n") || !ft_strcmp(line, "rb\n")
		|| !ft_strcmp(line, "pa\n") || !ft_strcmp(line, "pb\n")
		|| !ft_strcmp(line, "rra\n") || !ft_strcmp(line, "rrb\n")
		|| !ft_strcmp(line, "rr\n") || !ft_strcmp(line, "rrr\n")
		|| !ft_strcmp(line, "sa\n") || !ft_strcmp(line, "sb\n")
		|| !ft_strcmp(line, "ss\n"))
		return (0);
	return (1);
}

t_opp	*ft_lstnewv2(char *content)
{
	t_opp	*pp;

	pp = (t_opp *)malloc(sizeof(t_opp));
	if (!pp)
		return (NULL);
	pp->ptr = content;
	pp->next = NULL;
	return (pp);
}

void	ft_lstadd_backv2(t_opp **lst, t_opp *news)
{
	t_opp	*last;

	if (lst != NULL && news != NULL)
	{
		last = *lst;
		if (last == NULL)
			*lst = news;
		else
		{
			while (last->next != NULL)
				last = last->next;
			last->next = news;
		}
		news->next = NULL;
	}
}

void	free_stackv2(t_opp **opp)
{
	t_opp	*tmp;

	if (!opp || !*opp)
		return ;
	while (*opp)
	{
		tmp = (*opp)->next;
		free((*opp)->ptr);
		free(*opp);
		*opp = tmp;
	}
	*opp = NULL;
}

int	check_opp(t_opp **opp)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			return (1);
		if (!ft_cmp(line))
			ft_lstadd_backv2(opp, ft_lstnewv2(line));
		else
		{
			free_stackv2(opp);
			free(line);
			return (-1);
		}
	}
	return (1);
}
