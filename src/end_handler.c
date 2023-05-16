/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:35:33 by nmascrie          #+#    #+#             */
/*   Updated: 2023/05/10 11:35:34 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	victory_checker(t_data *data)
{
	g_anim_frame++;
	data->frame++;
	if (g_anim_frame >= 6)
		g_anim_frame = 0;
	progress_steps(data);
	progress_bar(data);
	progress_percent(data);
	if (data->win == -1)
	{
		ft_printf("Monsieur X vous a eu (Skill issue)");
		transition(data, 0xFF0000);
		usleep(1200000);
		dest_win(data);
	}
	if (data->win == 1)
	{
		ft_printf("Victoire ! Vous avez gagne en %d pas.\n", data->score);
		transition(data, 0x000000);
		usleep(1200000);
		dest_win(data);
	}
}
