/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_client.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:32:27 by amr21code         #+#    #+#             */
/*   Updated: 2022/04/26 23:21:33 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_minitalk.h"

void	ft_itob(int c, int *binary)
{
	int	i;

	i = 7;
	while (i)
	{
		binary[i] = c % 2;
		c /= 2;
		i--;
	}
}

void	mt_send_str(char *str, int srv_pid)
{
	int	binary[8];
	int	i;
	int	j;

	i = 0;
	ft_bzero(binary, 8);
	while (str[i])
	{
		ft_itob(str[i], binary);
		j = 0;
		while (j < 8)
		{
			if (binary[j])
				kill(srv_pid, SIGUSR2);
			else
				kill(srv_pid, SIGUSR1);
			j++;
			usleep(100);
		}
		i++;
	}
}

void	mt_reset_srv(int srv_pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(srv_pid, SIGUSR1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int					srv_pid;

	if (ac != 3)
		return (1);
	srv_pid = ft_atoi(av[1]);
	if (srv_pid == -1)
		return (1);
	if (!ft_strncmp(av[2], "@reset@", 7))
	{
		mt_reset_srv(srv_pid);
		return (0);
	}
	mt_send_str(av[2], srv_pid);
}
