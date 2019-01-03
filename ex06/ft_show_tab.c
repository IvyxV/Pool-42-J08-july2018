/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viboujem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 17:25:20 by viboujem          #+#    #+#             */
/*   Updated: 2018/07/26 12:09:19 by viboujem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void					ft_putnbr(int nb)
{
	long nb2;

	nb2 = nb;
	if (nb2 < 0)
	{
		ft_putchar('-');
		nb2 = nb2 * -1;
	}
	if (nb2 < 10 && nb2 >= 0)
		ft_putchar(nb2 + '0');
	else if (nb2 >= 10)
	{
		ft_putnbr(nb2 / 10);
		ft_putchar(nb2 % 10 + '0');
	}
}

void					ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void					ft_print_words_tables(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i] != 0)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void					ft_show_tab(struct s_stock_par *par)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (par[j].str != 0)
		j++;
	while (i < j)
	{
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		ft_putnbr(par[i].size_param);
		ft_putchar('\n');
		ft_print_words_tables(par[i].tab);
		i++;
	}
}
