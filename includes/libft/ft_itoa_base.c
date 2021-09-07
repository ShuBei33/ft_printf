/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 18:03:31 by estoffel          #+#    #+#             */
/*   Updated: 2021/09/07 19:16:52 by estoffel         ###   ########.fr       */
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
	if (n == 0)
		len = 1;
	return (len);
}

char	*ft_itoa_base(unsigned int n, char *base)
{
	char			*output;
	int				len;
	int				base_size;
	unsigned long	nb;

	nb = n;
	if (n < 0)
		nb = -n;
	len = intlen(n);
	base_size = ft_strlen(base);
	output = malloc(sizeof(char) * (len + 1));
	if (!output)
		return (NULL);
	output[len] = '\0';
	if (nb == 0)
		output[0] = '0';
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
