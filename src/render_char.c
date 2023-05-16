/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:24:32 by nmascrie          #+#    #+#             */
/*   Updated: 2023/05/10 11:24:33 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	render_mainchar_frame1(t_data *data, int j, int i)
{
	if (data->dir == 2)
		print_image(data, data->set.hero_up[1], j, i);
	else if (data->dir == 3)
		print_image(data, data->set.hero_left[1], j, i);
	else if (data->dir == 4)
		print_image(data, data->set.hero_right[1], j, i);
	else
		print_image(data, data->set.hero_down[1], j, i);
}

static void	render_mainchar_frame2(t_data *data, int j, int i)
{
	if (data->dir == 2)
		print_image(data, data->set.hero_up[2], j, i);
	else if (data->dir == 3)
		print_image(data, data->set.hero_left[2], j, i);
	else if (data->dir == 4)
		print_image(data, data->set.hero_right[2], j, i);
	else
		print_image(data, data->set.hero_down[2], j, i);
}

static void	render_mainchar_frame3(t_data *data, int j, int i)
{
	if (data->dir == 2)
		print_image(data, data->set.hero_up[0], j, i);
	else if (data->dir == 3)
		print_image(data, data->set.hero_left[0], j, i);
	else if (data->dir == 4)
		print_image(data, data->set.hero_right[0], j, i);
	else
		print_image(data, data->set.hero_down[0], j, i);
}

void	render_mainchar(t_data *data, int j, int i)
{
	if (data->win == 1)
		print_image(data, data->set.hero_happy, j, i);
	else if (data->win == -1)
		print_image(data, data->set.hero_dead, j, i);
	else if (data->frame == 1)
		render_mainchar_frame1(data, j, i);
	else if (data->frame == 3)
		render_mainchar_frame2(data, j, i);
	else
		render_mainchar_frame3(data, j, i);
}
