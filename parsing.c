/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 23:38:41 by mes-salh          #+#    #+#             */
/*   Updated: 2024/07/11 23:53:07 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mes_pars(char *str)
{
	int	i;

	i = 0;
	if (!str)
		ft_putstr("invalid argument\n");
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ' '))
			ft_putstr("arguments must be only numbers");
		i++;
	}
}
