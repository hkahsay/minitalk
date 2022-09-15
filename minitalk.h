/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:22:27 by hkahsay           #+#    #+#             */
/*   Updated: 2022/09/15 12:39:55 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include	<unistd.h>
# include	<stdio.h>
# include	<string.h>
# include	<stdlib.h>
# include	<fcntl.h>
# include	<sys/stat.h>
# include	<signal.h>
# include	"ft_print/include/ft_printf.h"
# include	"ft_print/include/libft.h"

static void		send_msg(int pid, char	*str);
void			print_msg(int signum);
#endif
