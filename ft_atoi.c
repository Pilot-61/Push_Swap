/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:06:50 by mes-salh          #+#    #+#             */
/*   Updated: 2024/07/12 00:25:03 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	mes_pnbr(int i, long nb, int sign, const char *str)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - 48);
		if (nb < 0 && sign == -1)
			return (0);
		else if (nb < 0 && sign == 1)
			return (-1);
		i++;
	}
	if (str[i] == '\0')
		return ((int)(nb * sign));
	ft_putstr("invalid number /numbers should have only one sign");
	exit(1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while(str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		ft_putstr("invalid number /numbers should have only one sign");
		exit(1);
	}
	return (mes_pnbr(i, nb, sign, str));
}
