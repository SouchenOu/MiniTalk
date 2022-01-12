/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client-bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:21:16 by souchen           #+#    #+#             */
/*   Updated: 2022/01/12 16:05:58 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Minitalk.h"
#include "libft/libft.h"

void	send_bits(int pid, char *string, size_t len)
{
	int		shift;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		shift = 0;
		while (shift <= 7)
		{
			if ((string[i] << shift) & 128)
			{
				kill (pid, SIGUSR2);
			}
			else
			{
				kill(pid, SIGUSR1);
			}
			shift++;
			usleep(800);
		}
		i++;
	}
}

void	handler(int i)
{
	ft_putstr_fd ("message received:", 1);
	ft_putnbr_fd (i, 1);
	write (1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	pid;

	signal (SIGUSR1, handler);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		send_bits(pid, argv[2], ft_strlen(argv[2]));
	}
	else
		ft_putstr_fd("problem!", 1);
	return (0);
}
