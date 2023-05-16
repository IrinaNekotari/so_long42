/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:34:43 by nmascrie          #+#    #+#             */
/*   Updated: 2023/05/10 11:34:44 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	dest_win(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		dest_win(data);
	}
	if (keysym == XK_w)
		move(UP, data);
	if (keysym == XK_s)
		move(DOWN, data);
	if (keysym == XK_a)
		move(LEFT, data);
	if (keysym == XK_d)
		move(RIGHT, data);
	return (0);
}
