/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metrics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:19:14 by nmascrie          #+#    #+#             */
/*   Updated: 2023/05/09 13:19:15 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	transition(t_data *data, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{	
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
			x++;
		}
		y++;
		usleep(2500);
	}
}

void	progress_error(t_data *data, int show)
{
	int	x;
	int	y;

	if (show)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, data->width / 2 - 64,
			data->height - 44, 0xFF0000, "La porte est fermee !");
		mlx_string_put(data->mlx_ptr, data->win_ptr, data->width / 2 - 64,
			data->height - 32, 0xFF0000, "Collecte toutes les clefs !");
	}
	else
	{
		y = 0;
		while (y < 40)
		{
			x = 0;
			while (x < 250)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr,
					x++ + data->width / 2 - IMAGE_SIZE - 32,
					y + data->height - 64, 0x000000);
			y++;
		}
	}
}

void	progress_bar(t_data *data)
{
	int		i;
	int		j;
	float	test;
	float	t2;

	i = 0;
	while (i < 16)
	{
		j = 32;
		while (j < data->width - 32)
		{
			test = ((float)data->prog / (float)data->coins) * 100;
			t2 = (((float)j / ((float)data->width - 32)) * 100);
			if (t2 <= test)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, j,
					data->height - 8 - i, 0x00FF00);
			else
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, j,
					data->height - 8 - i, 0xFF0000);
			j++;
		}
		i++;
	}
}

void	progress_percent(t_data *data)
{
	float	perc;
	char	*dur;

	rect(data);
	perc = ((float)data->prog / (float)data->coins) * 100;
	if (perc >= 100)
		mlx_string_put(data->mlx_ptr, data->win_ptr,
			data->width - 180, data->height - 32,
			0x00FF00, "100% ! Foncez vers la sortie !");
	else
	{
		dur = ft_itoa((int) perc);
		mlx_string_put(data->mlx_ptr, data->win_ptr, data->width - 40,
			data->height - 32, 0xfc8c03, dur);
		mlx_string_put(data->mlx_ptr, data->win_ptr, data->width - 26,
			data->height - 32, 0xfc8c03, "%");
		free(dur);
	}
}

void	progress_steps(t_data *data)
{
	int		x;
	int		y;
	char	*dur;

	dur = ft_itoa(data->score);
	y = 0;
	while (y < 16)
	{
		x = 0;
		while (x < 50)
		{	
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + 70,
				y + data->height - 45, 0x000000);
			x++;
		}
		y++;
	}
	mlx_string_put(data->mlx_ptr, data->win_ptr, 32, data->height - 32,
		0xFF0000, "Pas :");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 75, data->height - 32,
		0x00FF00, dur);
	free(dur);
}
