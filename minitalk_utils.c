/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:47:20 by ababa             #+#    #+#             */
/*   Updated: 2021/12/15 19:48:50 by ababa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	calculations(const char *str, int i, int sign)
{
	long	temp;
	long	result;

	temp = 0;
	result = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		if (temp != (result / 10))
		{
			if (sign == 1)
				return (-1);
			if (sign == -1)
				return (0);
		}
		temp = result;
		i++;
	}
	return (result * sign);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	return (calculations(str, i, sign));
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			ft_putchar(str[i]);
			i++;
		}
	}
}

void	ft_putnbr(int n)
{
	long	nb;

	nb = (long)n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
