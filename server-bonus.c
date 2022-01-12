/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server-bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:23:05 by souchen           #+#    #+#             */
/*   Updated: 2022/01/12 16:06:26 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Minitalk.h"
#include "libft/libft.h"

int	g_pid = 0;

int	display_binary_to_dec(int binary)
{
	int	decimal;
	int	weight;
	int	remainder;

	decimal = 0;
	weight = 1;
	remainder = 0;
	while (binary != 0)
	{
		remainder = binary % 10;
		decimal = decimal + remainder * weight;
		binary = binary / 10;
		weight = weight * 2;
	}
	return (decimal);
}

void	convert(int signal, siginfo_t *sig_info, void *context)
{
	static char	message[8];
	static int	i;

	(void) context;
	if (g_pid != sig_info->si_pid)
	{
		i = 0;
		ft_bzero(message, 8);
		g_pid = sig_info->si_pid;
	}
	if (signal == SIGUSR1)
		message[i] = '0';
	else
		message[i] = '1';
	i++;
	if (i == 8)
	{
		ft_putchar_fd(display_binary_to_dec(ft_atoi(message)), 1);
		if (display_binary_to_dec(ft_atoi(message)) == 0)
			kill(sig_info->si_pid, SIGUSR1);
		i = 0;
		ft_bzero(message, 8);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	sa.sa_sigaction = &convert;
	sa.sa_flags = SA_SIGINFO;
	if (pid < 0)
		return (-1);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
