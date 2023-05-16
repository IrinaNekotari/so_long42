/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:06:45 by nmascrie          #+#    #+#             */
/*   Updated: 2023/05/10 09:06:47 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	rect(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (y++ < 16)
	{
		x = 0;
		while (x < 64)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr,
				x++ + data->width - IMAGE_SIZE,
				y + data->height - 45, 0x000000);
	}
}
