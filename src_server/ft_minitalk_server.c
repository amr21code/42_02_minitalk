/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_server.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amr21code <a@n.de>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 09:24:35 by amr21code         #+#    #+#             */
/*   Updated: 2022/03/14 12:24:24 by amr21code        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/pi/42_02_minitalk/ft_minitalk.h"

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
		// ft_printf("\nTest:");
		// for (int j = 0; j < 8; j++)
		// 	ft_printf("%d", binary[j]);
		// ft_printf("\n");
		// ft_printf("2^%d = %d * %d + rest = %d\n", i, ft_iterative_power(2, i), binary[i],  c);
		i--;
	}
	return (c);
}

void	mt_print_msg(int signum)
{
	static int	binary[8];
	static int	i;

	if (!i)
		i = 8;
	i--;
	if (signum == SIGUSR1)
		binary[i] = 0;
	else if (signum == SIGUSR2)
		binary[i] = 1;
	if (i == 0)
	{
		ft_putchar_fd(ft_btoi(binary), 1);
		// ft_printf("%c", ft_btoi(binary));
		// ft_printf("\nTest:");
		// for (int j = 0; j < 8; j++)
		// 	ft_printf("%d", binary[j]);
		// ft_printf("\n");
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
