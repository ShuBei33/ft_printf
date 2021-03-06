/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 22:07:04 by estoffel          #+#    #+#             */
/*   Updated: 2021/09/08 14:12:48 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

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

static char	*ft_uitoa(unsigned int n)
{
	char			*output;
	int				len;
	unsigned int	nb;

	nb = n;
	if (n < 0)
		nb = -n;
	len = intlen(n);
	output = malloc(sizeof(char) * (len + 1));
	if (!output)
		return (NULL);
	output[len] = '\0';
	while (nb >= 0 && len > 0)
	{
		--len;
		output[len] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (n < 0)
		output[0] = '-';
	return (output);
}

int	conv_u(va_list *args)
{
	unsigned int		i;
	char				*str;
	int					len;

	i = va_arg(*args, unsigned int);
	str = ft_uitoa(i);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}
