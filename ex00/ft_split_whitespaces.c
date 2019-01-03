/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viboujem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 23:07:44 by viboujem          #+#    #+#             */
/*   Updated: 2018/07/23 23:38:08 by viboujem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int		ft_nb_words(char *str)
{
	int		i;
	int		nb_words;

	i = 0;
	nb_words = 0;
	while (str[i] != '\0')
	{
		while (is_space(str[i]) && str[i] != '\0')
			i++;
		if ((!is_space(str[i])) && (str[i] != '\0'))
			nb_words++;
		while ((!is_space(str[i])) && (str[i] != '\0'))
			i++;
	}
	return (nb_words);
}

int		ft_nb_letters(char *str, int n)
{
	int		i;
	int		size;

	i = n;
	size = 0;
	while (str[i] != '\0' && !is_space(str[i]))
		i++;
	return (i - n);
}

void	ft_tabs(int n, int i, char **dest, char *str)
{
	int		j;

	j = 0;
	dest[i] = (char*)malloc(sizeof(char) * (ft_nb_letters(str, n) + 1));
	while (!(is_space(str[n])) && (str[n] != '\0'))
	{
		dest[i][j] = str[n];
		j++;
		n++;
	}
	dest[i][j] = '\0';
}

char	**ft_split_whitespaces(char *str)
{
	int		i;
	int		n;
	char	**dest;

	i = 0;
	n = 0;
	dest = (char**)malloc(sizeof(char*) * (ft_nb_words(str) + 1));
	while (str[n] != '\0')
	{
		while (is_space(str[n]))
			n++;
		if (str[n] != '\0' && (!is_space(str[n])))
		{
			ft_tabs(n, i, dest, str);
			i++;
			while ((!is_space(str[n])) && (str[n] != '\0'))
				n++;
		}
	}
	dest[i] = NULL;
	return (dest);
}
