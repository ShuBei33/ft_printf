/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:52:31 by estoffel          #+#    #+#             */
/*   Updated: 2021/08/31 20:35:59 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

static char	*itoa_base(int n, char *base)
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

int	conv_id(va_list *args)
{
	int		i;
	char	*str;

	i = va_arg(*args, int);
	str = ft_itoa_base(i, "0123456789");
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}