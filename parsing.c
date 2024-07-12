/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 23:38:41 by mes-salh          #+#    #+#             */
/*   Updated: 2024/07/12 19:43:53 by mes-salh         ###   ########.fr       */
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
		{
			existe = 0;
		}
		s++;
	}
	return (counter);
}

// int	checker(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == ' ')
// 			i++;
// 		if (str[i] == '+' || str[i] == '-')
// 			i++;
// 		while (str[i] >= '0' && str[i] <= '9')
// 			i++;
// 		if (str[i] == '+' || str[i] == '-')
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

void	mes_pars(char *str)
{
	int		i;
	int		wordcount;
	int		*nbrs;
	int		j;
	char	**split_str;

	i = 0;
	j = 0;
	if (!str)
		ft_putstr("Error\n");
	// while (str[i])
	// {
	// 	if (!((str[i] >= '0' && str[i] <= '9')
	// 			|| str[i] == ' ' || str[i] == '+' || str[i] == '-'))
	// 	{
	// 		ft_putstr("arguments must be only numbers");
	// 		free(str);
	// 		exit(1);
	// 	}
	// 	i++;
	// }
	// if (!checker(str))
	// {
	// 	ft_putstr("arguments must be only numbers with sign at the begin only");
	// 	exit(1);
	// }
	wordcount = mes_len(str, ' ');
	nbrs = malloc(sizeof(int) * wordcount);
	if (!nbrs)
	{
		ft_putstr("Memory allocation failed\n");
		return ;
	}
	split_str = ft_split(str, ' ');
	if (!split_str)
	{
		ft_putstr("Splitting string failed\n");
		free(nbrs);
		return ;
	}
	j = 0;
	while (j < wordcount)
	{
		nbrs[j] = ft_atoi(split_str[j]);
		printf("Number %d: %d\n", j, nbrs[j]);
		j++;
	}
	j = 0;
	while (split_str[j])
	{
		free(split_str[j]);
		j++;
	}
	free(split_str);
	free(nbrs);
}
