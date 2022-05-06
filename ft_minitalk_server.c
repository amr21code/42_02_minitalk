/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_server.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 09:24:35 by amr21code         #+#    #+#             */
/*   Updated: 2022/05/06 13:14:40 by anruland         ###   ########.fr       */
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
	static int	bit;
	char		c;

	if (!bit)
		bit = 8;
	bit--;
	if (signum == SIGUSR1)
		binary[bit] = 0;
	else if (signum == SIGUSR2)
		binary[bit] = 1;
	if (bit == 0)
	{
		c = ft_btoi(binary);
		if (c == '\0')
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(c, 1);
	}
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
