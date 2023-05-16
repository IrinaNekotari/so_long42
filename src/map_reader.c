/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:38:42 by nmascrie          #+#    #+#             */
/*   Updated: 2023/05/10 13:38:43 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	map_size(char *path)
{
	int		i;
	int		fd;
	char	*tmp;

	fd = open(path, O_RDONLY);
	tmp = get_next_line(fd);
	i = 0;
	if (!tmp)
		return (-1);
	while (tmp)
	{
		i += (int)ft_strlen(tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void	free_map_no_launch(char **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		free(data[i]);
		i++;
	}
	data = NULL;
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	data->map = NULL;
}

int	is_ber(char *str)
{
	int	i;

	i = (int) ft_strlen(str);
	if (str[i - 1] != 'r')
		return (0);
	if (str[i - 2] != 'e')
		return (0);
	if (str[i - 3] != 'b')
		return (0);
	if (str[i - 4] != '.')
		return (0);
	return (1);
}

char	**read_map(char *path)
{
	char	**ret;
	char	*tmp;
	int		fd;
	int		i;

	i = 0;
	if (!is_ber(path))
		return (NULL);
	if (map_size(path) <= 0)
		return (NULL);
	fd = open(path, O_RDONLY);
	ret = malloc((map_size(path)) * sizeof(char));
	tmp = get_next_line(fd);
	while (tmp)
	{
		ret[i] = tmp;
		i++;
		tmp = get_next_line(fd);
	}
	ret[i] = NULL;
	close(fd);
	return (ret);
}
