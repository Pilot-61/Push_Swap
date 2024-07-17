/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 23:38:41 by mes-salh          #+#    #+#             */
/*   Updated: 2024/07/17 00:25:19 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
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
				swap(&nbrs[j], &nbrs[j + 1]);
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

int	mes_pars(char *str)
{
	int		wordcount;
	int		*nbrs;
	int		j;
	char	**split_str;

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
	if (!check_dup(nbrs, j))
		return (free_arr(split_str), free(nbrs), free(str), 0);
	return (free_arr(split_str), free(nbrs), free(str), 1);
}
