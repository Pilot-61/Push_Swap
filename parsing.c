/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 23:38:41 by mes-salh          #+#    #+#             */
/*   Updated: 2024/07/13 00:57:09 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	mes_len(const char *s, char c)
{
	int	existe;
	int	counter;

	existe = 0;
	counter = 0;
	while (*s != '\0')
	{
		if (*s != c && existe == 0)
		{
			existe = 1;
			counter++;
		}
		else if (*s == c)
			existe = 0;
		s++;
	}
	return (counter);
}

void	fill_stack(t_list *stack, int *nbrs, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_lstadd_back(&stack, ft_lstnew(nbrs[i]));
		i++;
	}
	while (stack)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
	}
}

void	swap(int a, int b)
{
	int	temp;

	temp = a;
	a = b;
	b = temp;
}

int	check_dup(int *nbrs, int n)
{
	int	i;
	int	j;
	int	swapped;

	i = -1;
	while (++i < n - 1)
	{
		swapped = 0;
		j = -1;
		while (++j < n - i - 1)
		{
			if (nbrs[j] > nbrs[j + 1])
			{
				swap(nbrs[j], nbrs[j + 1]);
				swapped = 1;
			}
		}
		if (!swapped)
			break ;
	}
	i = -1;
	while (++i < n - 1)
		if (nbrs[i] == nbrs[i + 1])
			return (0);
	return (1);
}

int	mes_pars(char *str, t_list *stack_a)
{
	int		wordcount;
	int		*nbrs;
	int		j;
	char	**split_str;
	int		*tmp;

	(void)stack_a;
	j = 0;
	if (!str)
		ft_putstr(2, "Error");
	wordcount = mes_len(str, ' ');
	nbrs = malloc(sizeof(int) * wordcount);
	if (!nbrs)
		return (free(str), 0);
	split_str = ft_split(str, ' ');
	if (!split_str)
		return (free(nbrs), free(str), 0);
	j = -1;
	while (++j < wordcount)
		nbrs[j] = ft_atoi(split_str[j]);
	tmp = nbrs;
	if (!check_dup(tmp, j))
		return (free_arr(split_str), free(nbrs), 0);
	fill_stack(stack_a, nbrs, j);
	return (free_arr(split_str), free(nbrs), 1);
}
