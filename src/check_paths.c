/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:55:19 by nmascrie          #+#    #+#             */
/*   Updated: 2023/05/12 13:55:20 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**ft_clone(char **t)
{
	int		i;
	char	**ret;

	i = 0;
	ret = malloc((count_lines(t) + 1) * (int)ft_strlen(t[0]) * sizeof(char));
	while (t[i])
	{
		ret[i] = ft_strdup(t[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

int	path_to_exit(char **map, int x, int y)
{
	int	sol[4];

	sol[0] = 0;
	sol[1] = 0;
	sol[2] = 0;
	sol[3] = 0;
	if (map[y][x] == 'E')
		return (1);
	map[y][x] = 'x';
	if (y > 0 && map[y][x - 1] != 'x' && map[y][x - 1] != '1')
		sol[0] = path_to_exit(map, x - 1, y);
	if (y < count_lines(map) - 1 && map[y][x + 1] != 'x'
		&& map[y][x + 1] != '1')
		sol[1] = path_to_exit(map, x + 1, y);
	if (x > 0 && map[y - 1][x] != 'x' && map[y - 1][x] != '1')
		sol[2] = path_to_exit(map, x, y - 1);
	if (x < (int)ft_strlen(map[y]) - 2 && map[y + 1][x] != 'x'
		&& map[y + 1][x] != '1')
		sol[3] = path_to_exit(map, x, y + 1);
	if (sol[0] || sol[1] || sol[2] || sol[3])
		return (1);
	else
		return (0);
}

static void	reset_map(char **a, char **b)
{
	int	i;

	i = 0;
	while (a[i])
	{
		free(a[i]);
		a[i] = ft_strdup(b[i]);
		i++;
	}
	a[i] = NULL;
}

static int	sortie(char **back)
{
	free_map_no_launch(back);
	free(back);
	return (0);
}

int	check_paths(char **map)
{
	char	**back;
	int		i;
	int		j;

	i = 1;
	back = ft_clone(map);
	while (back[i])
	{
		j = 1;
		while (back[i][j])
		{
			if (back[i][j++] == 'P' || back[i][j] == 'C')
			{	
				if (!path_to_exit(back, j, i))
					return (sortie(back));
				else
					reset_map(back, map);
			}
			j++;
		}
		i++;
	}
	free_map_no_launch(back);
	free(back);
	return (1);
}
