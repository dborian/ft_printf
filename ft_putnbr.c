/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedme <dedme@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:23:32 by dedme             #+#    #+#             */
/*   Updated: 2024/12/15 13:49:48 by dedme            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int				tab[10];
	unsigned int	nbr;
	int				v;

	v = 0;
	nbr = nb;
	if (nb < 0)
	{
		ft_putchar(45);
		nbr = nb * -1 + (v++) * 0;
	}
	else if (nb == 0)
		return (ft_putchar(48));
	nb = -1;
	while (nbr != 0)
	{
		tab[++nb] = nbr % 10;
		nbr = nbr / 10;
	}
	while (nb >= 0)
		ft_putchar(tab[nb-- + (nbr++ *0)] + 48);
	return (nbr + v);
}

int	ft_putnbr2(int nb)
{
	int				tab[10];
	unsigned int	nbr;

	nbr = nb;
	if (nb == 0)
		return (ft_putchar(48));
	nb = -1;
	while (nbr != 0)
	{
		tab[++nb] = nbr % 10;
		nbr = nbr / 10;
	}
	while (nb >= 0)
		ft_putchar(tab[nb-- + (nbr++ *0)] + 48);
	return (nbr);
}

int	ft_putnbr_base(int nbr, char *base)
{
	int				tab[25];
	unsigned int	nb;
	int				i;

	i = 0;
	nb = nbr;
	if (nbr == 0)
		return (ft_putchar(base[nbr % 16]));
	nbr = -1;
	if (nb != 0)
	{
		while (nb != 0)
		{
			tab[++nbr] = nb % 16;
			nb = nb / 16;
			while (nbr >= 0 && nb <= 0)
				ft_putchar(base[tab[nbr-- + (i++ *0)]]);
		}
	}
	return (i);
}

int	ft_putnbr_base2(unsigned long nbr, char *base)
{
	int				tab[100];
	unsigned long	nb;
	int				i;
	int				j;

	j = 0;
	i = 0;
	nb = nbr;
	if (nbr == 0)
		return (ft_putchar(base[nbr % 16]));
	while (nb != 0)
	{
		tab[j] = nb % 16;
		j++;
		nb = nb / 16;
		while (j > 0 && nb == 0)
			ft_putchar(base[tab[--j + (i++) * 0]]);
	}
	return (i);
}

int	ft_puthex(void *str)
{
	unsigned long	nb;
	int				len;

	if (!str)
		return (ft_putstr("(nil)"));
	len = 0;
	nb = (unsigned long)str;
	len = ft_putstr("0x");
	len += ft_putnbr_base2(nb, "0123456789abcdef");
	return (len);
}
