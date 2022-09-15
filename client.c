/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:22:45 by hkahsay           #+#    #+#             */
/*   Updated: 2022/09/15 13:06:39 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_msg(int pid, char	*str)
{
	int	i;
	int	bits;

	i = -1;
	while (str[++i])
	{
		bits = 8;
		while (--bits >= 0)
		{
			if ((str[i] >> bits & 1) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
		}
	}
	bits = 8;
	while (--bits >= 0)
	{
		kill(pid, SIGUSR2);
		usleep(10);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;
	int		i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("please write proper text");
		exit(1);
	}
	else if (!ft_isdigit(argv[1][i]))
	{
		ft_printf("the Pid must be a number");
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	str = ft_strdup(argv[2]);
	send_msg(pid, str);
	free(str);
	return (0);
}
