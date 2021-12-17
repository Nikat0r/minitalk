/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:52:34 by ababa             #+#    #+#             */
/*   Updated: 2021/12/15 20:56:45 by ababa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	handler(int signum)
{
	static char	storage[10000000];
	static int	counter = 0;
	static int	bit = 7;

	if (signum == SIGUSR1)
		storage[counter] |= (1 << bit);
	if (signum == SIGUSR2)
		storage[counter] &= ~(1 << bit);
	bit--;
	if (bit == -1)
	{
		bit = 7;
		if (storage[counter] == '\0')
		{
			write(1, storage, counter);
			write(1, "\n", 1);
			counter = 0;
		}
		else
			counter++;
	}
}

int	main(void)
{
	ft_putstr("The server's PID : ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
	{
		pause();
	}
}
