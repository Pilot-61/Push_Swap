/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 02:38:26 by mes-salh          #+#    #+#             */
/*   Updated: 2024/07/12 18:06:24 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_valid_number(const char *str)
{
	char	**splited;
	int		i;
	int		j;

	splited = ft_split(str, ' ');
	j = 0;
	while (splited[j])
	{
		i = 0;
		while (splited[j][i] == ' ')
			i++;
		if (splited[j][i] == '-' || splited[j][i] == '+')
		{
			i++;
			if (!is_num(splited[j][i]))
				return (0);
		}
		while (splited[j][i])
		{
			if (!is_num(splited[j][i]))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	*str;
	int		i;

	if (ac < 2)
	{
		ft_putstr("usage : ./push_swap [nbr1] [nbr2] ...\n");
		return (EXIT_FAILURE);
	}
	i = 1;
	while (i < ac)
	{
		if (!is_valid_number(av[i]))
		{
			ft_putstr("The Arguments must be numbers with only one sign\n");
			return (EXIT_FAILURE);
		}
		i++;
	}
	str = ft_strjoin(ac - 1, av + 1, " ");
	mes_pars(str);
	return (0);
}
