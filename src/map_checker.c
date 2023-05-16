/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:38:50 by nmascrie          #+#    #+#             */
/*   Updated: 2023/05/10 13:38:51 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_format(char **map)
{
	int	y;
	int	x;
	int	count_x;

	x = 0;
	y = 0;
	count_x = 0;
	while (map[0][count_x])
		count_x++;
	while (map[y] != NULL)
	{
		while (map[y][x])
			x++;
		if (x != count_x)
		{
			ft_printf("Error !\n");
			ft_printf("La carte doit etre un rectangle.\n");
			return (0);
		}
		x = 0;
		y++;
	}
	return (1);
}

int	check_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (NULL != map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] != 'E' && map[i][j] != 'P'
				&& map[i][j] != 'C' && map[i][j] != '0'
				&& map[i][j] != '1' && map[i][j] != '\n')
			{
				ft_printf("Error !\n");
				ft_printf("La carte contient des chars invalides.\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	count_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		i++;
	}
	return (i);
}

int	check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			if (i == 0 && map[i][j] != '1')
				return (0);
			if (j == 0 && map[i][j] != '1')
				return (0);
			if (j == ((int)ft_strlen(map[i]) - 1) && map[i][j] != '1')
				return (0);
			if (i == (count_lines(map) - 1) && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_io(char **map)
{
	int	i;
	int	j;
	int	comptes[2];

	i = 0;
	comptes[0] = 0;
	comptes[1] = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			if (map[i][j] == 'E')
				comptes[0]++;
			else if (map[i][j] == 'P')
				comptes[1]++;
			j++;
		}
		i++;
	}
	if (comptes[0] != 1 || comptes[1] != 1)
	{
		return (0);
	}
	return (1);
}
