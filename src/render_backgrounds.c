/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_backgrounds.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:31:28 by nmascrie          #+#    #+#             */
/*   Updated: 2023/05/10 11:31:29 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

extern int	g_anim_frame;
extern int	g_x_dir;

void	render_coin(t_data *data, int j, int i)
{
	if (g_anim_frame == 0)
		print_image(data, data->set.coin, j, i);
	else if (g_anim_frame == 1 || g_anim_frame == 5)
		print_image(data, data->set.coin_b, j, i);
	else if (g_anim_frame == 2 || g_anim_frame == 4)
		print_image(data, data->set.coin_c, j, i);
	else if (g_anim_frame == 3)
		print_image(data, data->set.coin_d, j, i);
}

void	render_background(t_data *data, int j, int i, char c)
{
	if (c == 'P')
		print_image(data, data->set.floor, j, i);
	else if (c == '0')
		print_image(data, data->set.floor, j, i);
	else if (c == '1')
		print_image(data, data->set.wall, j, i);
	else if (c == 'C')
		print_image(data, data->set.floor, j, i);
	else if (c == 'E' && data->prog >= data->coins)
		print_image(data, data->set.door_open, j, i);
	else if (c == 'E' && data->prog < data->coins)
		print_image(data, data->set.door_locked, j, i);
}

void	render_loop(t_data *data, int i, int j)
{
	if (i == data->mr_x->y && j == data->mr_x->x
		&& data->win != -1 && data->chase == 1)
		print_image(data, data->set.mr_x[g_x_dir], j, i);
	else if (i == data->pos->y && j == data->pos->x)
		render_mainchar(data, j, i);
	else if (is_coin(i, j, data))
		render_coin(data, j, i);
	else
		render_background(data, j, i, data->map[i][j]);
}

void	print_image(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img,
		IMAGE_SIZE * x, IMAGE_SIZE * y);
}
