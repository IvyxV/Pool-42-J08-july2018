/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viboujem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 13:11:27 by viboujem          #+#    #+#             */
/*   Updated: 2018/07/26 11:53:39 by viboujem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

int						ft_strlen(char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char					*ft_strdup(char *src)
{
	int				i;
	int				j;
	char			*str;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	str = (char*)malloc(sizeof(*str) * (i + 1));
	while (src[j])
	{
		str[j] = src[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

struct s_stock_par		*ft_param_to_tab(int ac, char **av)
{
	int				i;
	t_stock_par		*tab_param;

	i = 0;
	tab_param = (t_stock_par*)malloc(sizeof(t_stock_par) * (ac + 1));
	while (i < ac)
	{
		tab_param[i].size_param = ft_strlen(av[i]);
		tab_param[i].str = av[i];
		tab_param[i].copy = ft_strdup(av[i]);
		tab_param[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	tab_param[i].str = 0;
	return (tab_param);
}
