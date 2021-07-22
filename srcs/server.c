/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:52:43 by vincentbaro       #+#    #+#             */
/*   Updated: 2021/07/22 11:14:19 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minitalk.h"

static char mssg;
static int bit_shift;


void add_char(int bit)
{
    // ft_putchar_fd('1', 1);
    (void)bit;
    mssg += 1 << bit_shift;
    bit_shift++;
}

void nothing(int bit)
{
    // // ft_putchar_fd('0', 1);
    (void)bit;
    bit_shift++;
}

int main()
{
    int pid;

    mssg = 0;
    bit_shift = 0;
    pid = getpid();
    ft_putnbr_fd(pid, 1);
    ft_putstr_fd("\nWaiting for connection...\n", 1);

    while(1)
    {
        signal(SIGUSR1, nothing);
        signal(SIGUSR2, add_char);
        pause();
        if (bit_shift >= 7)
        {
            ft_putchar_fd(mssg, 1);
            mssg = 0;
            bit_shift = 0;
        }
    }
}