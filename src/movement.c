/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:26:02 by nmascrie          #+#    #+#             */
/*   Updated: 2023/05/09 11:26:04 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

extern int	g_x_dir;

void	x_moves(t_data *data)
{
	g_x_dir = rand() % 4;
	if (g_x_dir == 1
		&& data->map[data->mr_x->y - 1][data->mr_x->x] != '1')
		data->mr_x->y--;
	else if (g_x_dir == 0
		&& data->map[data->mr_x->y + 1][data->mr_x->x] != '1')
		data->mr_x->y++;
	else if (g_x_dir == 2
		&& data->map[data->mr_x->y][data->mr_x->x - 1] != '1')
		data->mr_x->x--;
	else if (g_x_dir == 3
		&& data->map[data->mr_x->y][data->mr_x->x + 1] != '1')
		data->mr_x->x++;
	else
		g_x_dir = rand() % 4;
}

void	x_gonna_give(t_data *data)
{
	if (X_SPAWN != 0 && data->score > 5)
	{
		data->chase = 1;
		x_moves(data);
	}
}

void	update_score(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->coins * 2 - 1)
	{
		if (data->pos->x == data->coin_pos[i]
			&& data->pos->y == data->coin_pos[i + 1])
		{
			data->coin_pos[i] = -1;
			data->coin_pos[i + 1] = -1;
			data->prog++;
		}	
		i += 2;
	}
}

void	victory(t_data *data)
{
	if (data->pos->x == data->mr_x->x
		&& data->pos->y == data->mr_x->y && data->chase == 1)
		data->win = -1;
	if (data->pos->x == data->exit.x && data->pos->y == data->exit.y)
	{
		if (data->prog < data->coins)
			progress_error(data, 1);
		else
			data->win = 1;
	}
	else
		progress_error(data, 0);
	x_gonna_give(data);
	if (data->pos->x == data->mr_x->x
		&& data->pos->y == data->mr_x->y && data->chase == 1)
		data->win = -1;
}

int	move(int dir, t_data *data)
{
	if (dir == UP && data->map[data->pos->y - 1][data->pos->x] != '1')
	{
		data->pos->y--;
		data->score++;
	}
	if (dir == DOWN && data->map[data->pos->y + 1][data->pos->x] != '1')
	{
		data->pos->y++;
		data->score++;
	}
	if (dir == LEFT && data->map[data->pos->y][data->pos->x - 1] != '1')
	{
		data->pos->x--;
		data->score++;
	}
	if (dir == RIGHT && data->map[data->pos->y][data->pos->x + 1] != '1')
	{
		data->pos->x++;
		data->score++;
	}
	data->dir = dir;
	data->frame = 0;
	victory(data);
	update_score(data);
	return (0);
}
