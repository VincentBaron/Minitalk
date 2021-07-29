/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:52:43 by vincentbaro       #+#    #+#             */
/*   Updated: 2021/07/29 11:41:46 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static char	g_mssg;
static int	g_bit_shift;

void	add_char(int bit)
{
	(void)bit;
	g_mssg += 1 << g_bit_shift;
	g_bit_shift++;
}

void	nothing(int bit)
{
	(void)bit;
	g_bit_shift++;
}

int	main(void)
{
	int	pid;

	g_mssg = 0;
	g_bit_shift = 0;
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	while (1)
	{
		signal(SIGUSR1, nothing);
		signal(SIGUSR2, add_char);
		pause();
		if (g_bit_shift >= 7)
		{
			ft_putchar_fd(g_mssg, 1);
			g_mssg = 0;
			g_bit_shift = 0;
		}
	}
	system("leaks server");
}
