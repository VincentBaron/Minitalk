/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:32:29 by vincentbaro       #+#    #+#             */
/*   Updated: 2021/08/19 10:49:50 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	bit_shift_handler(int pid, char *str)
{
	int	i;
	int	bit_shift;

	i = 0;
	while (str[i])
	{
		bit_shift = 0;
		while (bit_shift < 8)
		{
			if ((str[i] >> bit_shift) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			bit_shift++;
			usleep(200);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*string;

	if (ac != 3)
	{
		ft_putstr_fd("Wrong number of arguments, program quitting...", 1);
		return (0);
	}
	pid = ft_atoi(av[1]);
	string = av[2];
	bit_shift_handler(pid, string);
}
