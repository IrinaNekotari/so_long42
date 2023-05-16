/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:12:06 by nmascrie          #+#    #+#             */
/*   Updated: 2023/05/10 09:12:08 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_point	find_exit(t_data *data)
{
	int		i;
	int		j;
	t_point	ret;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
			{
				ret.x = j;
				ret.y = i;
				break ;
			}
			j++;
		}
		i++;
	}
	return (ret);
}

t_point	find_character(t_data *data)
{
	int		i;
	int		j;
	t_point	ret;
	char	*parse;

	i = 0;
	while (data->map[i])
	{
		parse = ft_strdup(data->map[i]);
		j = 0;
		while (parse[j])
		{
			if (parse[j] == 'P')
			{
				ret.x = j;
				ret.y = i;
				break ;
			}
			j++;
		}
		i++;
		free(parse);
	}
	return (ret);
}
