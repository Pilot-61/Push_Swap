/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 02:38:26 by mes-salh          #+#    #+#             */
/*   Updated: 2024/07/17 03:55:38 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num(int c)
{
	return (c >= '0' && c <= '9');
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	is_valid_number(const char *str)
{
	char	**splited;
	int		i;
	int		j;

	splited = ft_split(str, ' ');
	if (!splited || !splited[0] || splited[0][0] == '\t')
		return (free_arr(splited), 0);
	j = -1;
	while (splited[++j])
	{
		i = 0;
		while (splited[j][i] == ' ')
			i++;
		if (splited[j][i++] == '-' || splited[j][i] == '+')
			if (!is_num(splited[j][i]))
				return (free_arr(splited), 0);
		while (splited[j][i])
		{
			if (!is_num(splited[j][i]))
				return (free_arr(splited), 0);
			i++;
		}
	}
	return (free_arr(splited), 1);
}

int	fill_stack(t_list **stack_a, char **av)
{
	int		i;
	int		j;
	char	**splited;

	i = 0;
	while (av[++i])
	{
		splited = ft_split(av[i], ' ');
		if (!splited)
			return (-1);
		j = -1;
		while (splited[++j])
		{
			if (!ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(splited[j]))))
			{
				free_stack(stack_a);
				free_arr(splited);
				ft_putstr(2, "Error");
				exit(EXIT_FAILURE);
			}
		}
		free_arr(splited);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;
	char	*str;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	i = 0;
	while (++i < ac)
		if (!is_valid_number(av[i]))
			return (ft_putstr(2, "Error"), EXIT_FAILURE);
	str = ft_strjoin(ac - 1, av + 1, " ");
	if (!str || !mes_pars(str) || fill_stack(&stack_a, av) == -1)
		return (ft_putstr(2, "Error"), 1);
	size = ft_lstsize(stack_a);
	index_smallest(&stack_a);
	if (!is_sorted(stack_a))
		sort_it(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	return (0);
}
