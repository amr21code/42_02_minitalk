/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_server.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amr21code <a@n.de>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 09:24:35 by amr21code         #+#    #+#             */
/*   Updated: 2022/03/10 20:02:46 by amr21code        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_server.h"

void	func(int signum)
{
	ft_printf("signal %d caught\n", signum);
}

int	main(void)
{
	int	pid;

	signal(30, func);
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	while (1)
		pause();

	return (0);
}
