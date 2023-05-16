/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 08:48:37 by nmascrie          #+#    #+#             */
/*   Updated: 2023/05/10 08:48:38 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_sprites(t_data *data)
{
	data->set.hero_up[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/PD1.xpm", &(data->set.w), &(data->set.h));
	data->set.hero_down[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/PU1.xpm", &(data->set.w), &(data->set.h));
	data->set.hero_left[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/PL1.xpm", &(data->set.w), &(data->set.h));
	data->set.hero_right[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/PR1.xpm", &(data->set.w), &(data->set.h));
	data->set.hero_up[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/PD2.xpm", &(data->set.w), &(data->set.h));
	data->set.hero_down[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/PU2.xpm", &(data->set.w), &(data->set.h));
	data->set.hero_left[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/PL2.xpm", &(data->set.w), &(data->set.h));
	data->set.hero_right[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/PR2.xpm", &(data->set.w), &(data->set.h));
	data->set.hero_up[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/PD4.xpm", &(data->set.w), &(data->set.h));
	data->set.hero_down[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/PU4.xpm", &(data->set.w), &(data->set.h));
	data->set.hero_left[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/PL4.xpm", &(data->set.w), &(data->set.h));
	data->set.hero_right[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/PR4.xpm", &(data->set.w), &(data->set.h));
}

void	load_mr_x(t_data *data)
{
	data->set.mr_x[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/XD.xpm", &(data->set.w), &(data->set.h));
	data->set.mr_x[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/XU.xpm", &(data->set.w), &(data->set.h));
	data->set.mr_x[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/XL.xpm", &(data->set.w), &(data->set.h));
	data->set.mr_x[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/XR.xpm", &(data->set.w), &(data->set.h));
}

void	load_images(t_data *data)
{
	data->set.w = IMAGE_SIZE;
	data->set.h = IMAGE_SIZE;
	data->set.wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/1.xpm", &(data->set.w), &(data->set.h));
	data->set.floor = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/0.xpm", &(data->set.w), &(data->set.h));
	data->set.door_locked = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/L.xpm", &(data->set.w), &(data->set.h));
	data->set.door_open = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/E.xpm", &(data->set.w), &(data->set.h));
	data->set.coin = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/C1.xpm", &(data->set.w), &(data->set.h));
	data->set.coin_b = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/C2.xpm", &(data->set.w), &(data->set.h));
	data->set.coin_c = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/C3.xpm", &(data->set.w), &(data->set.h));
	data->set.coin_d = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/C4.xpm", &(data->set.w), &(data->set.h));
	data->set.hero_happy = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/Happy.xpm", &(data->set.w), &(data->set.h));
	data->set.hero_dead = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/Ded.xpm", &(data->set.w), &(data->set.h));
	load_sprites(data);
	load_mr_x(data);
}
