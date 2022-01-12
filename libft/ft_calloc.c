/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:46:29 by souchen           #+#    #+#             */
/*   Updated: 2021/11/19 13:45:47 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*chain;

	chain = (void *) malloc (count * size);
	if (chain == NULL)
		return (NULL);
	ft_bzero(chain, size * count);
	return (chain);
}
