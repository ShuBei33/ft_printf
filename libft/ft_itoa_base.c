/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 18:03:31 by estoffel          #+#    #+#             */
/*   Updated: 2021/08/30 21:40:59 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(long int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n = -n;
		++len;
	}
	while (n > 9)
	{
		n = n / 10;
		++len;
	}
	return (len);
}

char	*ft_itoa_base(int n, char *base)
{
	char			*output;
	int				len;
	int				base_size;
	unsigned int	nb;

	nb = n;
	if (n < 0)
		nb = -n;
	len = intlen(n);
	base_size = ft_strlen(base);
	output = malloc(sizeof(char) * (base_size + 1));
	if (!output)
		return (NULL);
	output[len] = '\0';
	while (nb != 0 && len > 0)
	{
		--len;
		output[len] = base[nb % base_size];
		nb = nb / base_size;
	}
	if (n < 0)
		output[0] = '-';
	return (output);
}
