/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:07:11 by nmascrie          #+#    #+#             */
/*   Updated: 2023/05/10 10:07:12 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	start(t_data *data, char **t)
{
	t_point	pos;
	t_point	pos2;

	data->mlx_ptr = mlx_init();
	data->map = t;
	data->score = 0;
	data->prog = 0;
	data->win = 0;
	data->exit = find_exit(data);
	data->dir = 2;
	data->frame = 10;
	data->chase = 0;
	load_images(data);
	pos = find_character(data);
	pos2 = find_exit(data);
	data->coins = find_coins(data->map);
	generate_coins_pos(data);
	calculate_window_size(data);
	data->pos = (struct s_point *) malloc(sizeof(t_point));
	data->pos->x = pos.x;
	data->pos->y = pos.y;
	data->mr_x = (struct s_point *) malloc(sizeof(t_point));
	data->mr_x->x = pos2.x;
	data->mr_x->y = pos2.y;
}

void	free_sprites(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->set.hero_up[0]);
	mlx_destroy_image(data->mlx_ptr, data->set.hero_down[0]);
	mlx_destroy_image(data->mlx_ptr, data->set.hero_left[0]);
	mlx_destroy_image(data->mlx_ptr, data->set.hero_right[0]);
	mlx_destroy_image(data->mlx_ptr, data->set.hero_up[1]);
	mlx_destroy_image(data->mlx_ptr, data->set.hero_down[1]);
	mlx_destroy_image(data->mlx_ptr, data->set.hero_left[1]);
	mlx_destroy_image(data->mlx_ptr, data->set.hero_right[1]);
	mlx_destroy_image(data->mlx_ptr, data->set.hero_up[2]);
	mlx_destroy_image(data->mlx_ptr, data->set.hero_down[2]);
	mlx_destroy_image(data->mlx_ptr, data->set.hero_left[2]);
	mlx_destroy_image(data->mlx_ptr, data->set.hero_right[2]);
	mlx_destroy_image(data->mlx_ptr, data->set.mr_x[0]);
	mlx_destroy_image(data->mlx_ptr, data->set.mr_x[1]);
	mlx_destroy_image(data->mlx_ptr, data->set.mr_x[2]);
	mlx_destroy_image(data->mlx_ptr, data->set.mr_x[3]);
}

void	free_all(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->set.wall);
	mlx_destroy_image(data->mlx_ptr, data->set.floor);
	mlx_destroy_image(data->mlx_ptr, data->set.door_locked);
	mlx_destroy_image(data->mlx_ptr, data->set.door_open);
	mlx_destroy_image(data->mlx_ptr, data->set.coin);
	mlx_destroy_image(data->mlx_ptr, data->set.coin_b);
	mlx_destroy_image(data->mlx_ptr, data->set.coin_c);
	mlx_destroy_image(data->mlx_ptr, data->set.coin_d);
	mlx_destroy_image(data->mlx_ptr, data->set.hero_happy);
	mlx_destroy_image(data->mlx_ptr, data->set.hero_dead);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	free_sprites(data);
	mlx_destroy_display(data->mlx_ptr);
	free(data->coin_pos);
	free(data->mr_x);
	free(data->pos);
	free(data->mlx_ptr);
	free_map(data);
}
