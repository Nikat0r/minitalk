/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:21:56 by ababa             #+#    #+#             */
/*   Updated: 2021/12/17 20:13:30 by ababa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	character_division(char c, int pid)
{
	int	current_bit;

	current_bit = 7;
	while (current_bit != -1)
	{
		if (c & (1 << current_bit))
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		current_bit--;
		usleep(100);
	}
}

static void	string_division(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		character_division(str[i], pid);
		i++;
	}
	character_division('\0', pid);
}

static int	pid_check(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 0 && str[i] > 9)
			return (-1);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		if (ft_atoi(argv[1]) <= 0 || argv[1] == NULL
			|| pid_check(argv[1]) == -1)
		{
			exit(1);
		}
		string_division(argv[2], ft_atoi(argv[1]));
		ft_putstr("The message was sent!\n");
	}
	else
		ft_putstr("Incorrect arguments, correct format -> [PID] [string]\n");
}
