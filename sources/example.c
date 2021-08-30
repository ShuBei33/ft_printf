/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 19:05:04 by estoffel          #+#    #+#             */
/*   Updated: 2021/08/30 22:34:57 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int	fct(char *format, ...)
{
	va_list	args;
	char	*str;
	char	*str2;

	va_start(args, format);
	str = va_arg(args, char *);
	str2 = va_arg(args, char *);
	ft_putstr(str);
	ft_putstr(str2);
	va_end(args);
	return (0);
}

static void	ft_putc_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n >= 0 && n <= 9)
		ft_putc_fd('0' + n, fd);
	else if (n < 0)
	{
		ft_putc_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

int	nbr_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr == -2147483648)
		return (11);
	if (nbr < 0)
	{
		len++;
		nbr = (-1) * nbr;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

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

char	*flag_x(int n, char *base)
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

int	handle_int(va_list *args)
{
	int	i;

	i = va_arg(*args, int);
	ft_putnbr_fd(i, 1);
	return (nbr_len(i));
}

int	check_conv(char c, va_list *args)
{
	char	c1;
	char	*str;
	int		i;

	if (c == 's')
	{
		str = va_arg(*args, char *);
		return (write(1, str, ft_strlen(str)));
	}
	else if (c == 'i' || c == 'd')
		return (handle_int(args));
	else if (c == 'c')
	{
		c1 = va_arg(*args, int);
		ft_putc_fd(c1, 1);
		return (1);
	}
	else if (c == 'x')
	{
		i = va_arg(*args, int);
		str = flag_x(i, "0123456789abcdef");
		ft_putstr(str);
		return (ft_strlen(str));
	}
	else if (c == 'X')
	{
		i = va_arg(*args, int);
		str = flag_x(i, "0123456789ABCDEF");
		ft_putstr(str);
		return (ft_strlen(str));
	}
	return (0);
}

int	ft_pf(char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i])
				len = len + check_conv(format[i], &args);
		}
		else
			len = len + write(1, &format[i], 1);
		i++;
	}	
	va_end(args);
	return (len);
}

int	main(void)
{
	int	ch;

	ch = 75;
	printf("ASCII value = %d, Character = %c\n", ch, ch);
	ft_pf("ASCII value = %d, Character = %c\n", ch, ch);
	//if (ac == 3)
	//	fct("coucou %c oucou", av[1], av[2]);
	ft_pf("%i\n", ft_pf("coucou [%s], comment tu vas ? J'ai %i an%c\n%X\n%x\n", "enora", 28, 's', 16, 42));
	printf("%i\n", printf("coucou [%s], comment tu vas ? J'ai %i an%c\n%X\n%x\n", "enora", 28, 's', 16, 42));
	//printf("coucou [%-10.3s], comment tu vas ?\n", "Enora");
}
