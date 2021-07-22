/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:32:29 by vincentbaro       #+#    #+#             */
/*   Updated: 2021/07/22 11:02:24 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minitalk.h"

void bit_shift_handler(int pid, char *str)
{
    int i;
    int bit_shift;

    i = 0;
    while(str[i])
    {
        bit_shift = 0;
        while(bit_shift < 7)
        {
            if ((str[i] >> bit_shift) & 1)
                kill(pid, SIGUSR2);
            else
                kill(pid, SIGUSR1);
            bit_shift++;
            usleep(100);
        }
        i++;
    }
}

int main(int ac, char **av)
{
    int pid;
    char *string;

    if (ac != 3)
    {
        ft_putstr_fd("Wrong number of arguments, program quitting...", 1);
        return 0;
    }
    pid = ft_atoi(av[1]);
    string = av[2];
    // ft_putstr_fd(string, 1);
    bit_shift_handler(pid, string);
}