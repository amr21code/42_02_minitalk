/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_server.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 09:24:35 by amr21code         #+#    #+#             */
/*   Updated: 2022/04/26 23:24:24 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_minitalk.h"

int	ft_iterative_power(int nb, int power)
{
	int	pow;
	int	i;

	i = 0;
	pow = 1;
	if (power < 0)
		return (0);
	if (power == 0 && nb == 0)
		return (1);
	while (i < power)
	{
		pow *= nb;
		i++;
	}
	return (pow);
}

char	ft_btoi(int *binary)
{
	int	i;
	int	c;

	i = 7;
	c = 0;
	while (i > -1)
	{
		c += ft_iterative_power(2, i) * binary[i];
		i--;
	}
	return (c);
}

void	mt_print_msg(int signum)
{
	static int	binary[8];
	static int	reset;
	static int	bit;

	if (!reset)
		reset = 0;
	if (!bit)
		bit = 8;
	bit--;
	if (signum == SIGUSR1)
	{
		reset++;
		binary[bit] = 0;
	}
	else if (signum == SIGUSR2)
	{
		reset = 0;
		binary[bit] = 1;
	}
	if (bit == 0)
		ft_putchar_fd(ft_btoi(binary), 1);
	if (reset == 8)
		bit = 8;
}

int	main(void)
{
	sigset_t			signals;
	struct sigaction	s_action;

	sigemptyset(&signals);
	sigaddset(&signals, SIGUSR1);
	sigaddset(&signals, SIGUSR2);
	s_action.sa_mask = signals;
	s_action.sa_handler = mt_print_msg;
	sigaction(SIGUSR1, &s_action, NULL);
	sigaction(SIGUSR2, &s_action, NULL);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
