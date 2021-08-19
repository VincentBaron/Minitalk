/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:52:43 by vincentbaro       #+#    #+#             */
/*   Updated: 2021/08/19 10:46:42 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static t_signal	g_sig;

void	add_char(int bit)
{
	(void)bit;
	g_sig.g_mssg += 1 << g_sig.g_bit_shift;
	g_sig.g_bit_shift++;
}

void	nothing(int bit)
{
	(void)bit;
	g_sig.g_bit_shift++;
}

int	main(void)
{
	int	pid;

	g_sig.g_mssg = 0;
	g_sig.g_bit_shift = 0;
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	while (1)
	{
		signal(SIGUSR1, nothing);
		signal(SIGUSR2, add_char);
		pause();
		if (g_sig.g_bit_shift == 8)
		{
			ft_putchar_fd(g_sig.g_mssg, 1);
			g_sig.g_mssg = 0;
			g_sig.g_bit_shift = 0;
		}
	}
}
