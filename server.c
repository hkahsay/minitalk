/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:38:30 by hkahsay           #+#    #+#             */
/*   Updated: 2022/09/15 14:42:41 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_msg(int signum)
{
	static int	bit;
	static int	count;

	if (bit <= 7)
	{
		count <<= 1;
		if (signum == SIGUSR1)
			count ^= 1;
		++bit;
	}
	if (bit == 8)
	{
		write(1, &count, 1);
		if (!count)
			write(1, "\n", 1);
		count = 0;
		bit = 0;
	}
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, print_msg);
	signal(SIGUSR2, print_msg);
	while (1)
		pause();
	return (0);
}
