/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:22:34 by nmascrie          #+#    #+#             */
/*   Updated: 2023/05/09 11:22:35 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	generate_coins_pos(t_data *data)
{
	int		i;
	int		j;
	int		c;
	char	*parse;

	data->coin_pos = malloc(data->coins * 2 * sizeof(int));
	i = 0;
	c = 0;
	while (data->map[i])
	{
		parse = ft_strdup(data->map[i]);
		j = 0;
		while (parse[j])
		{
			if (parse[j] == 'C')
			{
				data->coin_pos[c] = j;
				data->coin_pos[c + 1] = i;
				c += 2;
			}
			j++;
		}
		i++;
		free(parse);
	}
}

int	find_coins(char **data)
{
	int		i;
	int		j;
	int		ret;

	i = 0;
	ret = 0;
	while (data[i])
	{
		j = 0;
		while (data[i][j])
		{
			if (data[i][j] == 'C')
				ret++;
			j++;
		}
		i++;
	}
	return (ret);
}

int	is_coin(int x, int y, t_data *data)
{
	int	i;

	i = 0;
	if (x < 0 || y < 0)
		return (0);
	while (i < data->coins * 2 - 1)
	{
		if (y == data->coin_pos[i] && x == data->coin_pos[i + 1])
			return (1);
		i += 2;
	}
	return (0);
}
