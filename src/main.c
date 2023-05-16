/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:46:44 by nmascrie          #+#    #+#             */
/*   Updated: 2023/05/03 11:46:45 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	g_anim_frame = 1;
int	g_x_dir = 1;

void	calculate_window_size(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
			j++;
		i++;
	}
	data->width = j * IMAGE_SIZE;
	data->height = (i + 1) * IMAGE_SIZE;
}

int	render(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (data->win_ptr == NULL)
		return (1);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			render_loop(data, i, j);
			j++;
		}
		i++;
	}
	victory_checker(data);
	usleep(125000);
	return (0);
}

static int	launch(char **map, char *title)
{
	t_data	data;

	start(&data, map);
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr,
			data.width, data.height, title);
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr,
			data.width, data.height);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, 17, 0, &dest_win, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	free_all(&data);
	return (1);
}

static int	checklist(char **t)
{
	if (!check_format(t) || !check_chars(t))
		return (0);
	if (!check_io(t))
		return (print_error("La carte contient un nombre invalide et P ou E."));
	if (!check_walls(t))
		return (print_error("La carte n'est pas fermee."));
	if (find_coins(t) < 1)
		return (print_error("La carte ne contient aucune clef (C)."));
	if (!check_paths(t))
		return (print_error("La carte n'a aucun chemin valide."));
	return (1);
}

int	main(int args, char *argsv[])
{
	char	**t;

	if (args != 2)
	{
		ft_printf("Error !\n");
		ft_printf("Le programme necessite un");
		ft_printf(" unique argument pour etre lance.\n");
	}
	else
	{
		t = read_map(argsv[1]);
		if (!t)
			ft_printf("Error !\nLa carte .ber specifie n'existe pas.\n");
		else if (checklist(t))
		{		
			launch(t, argsv[1]);
		}
		else
			free_map_no_launch(t);
		free(t);
	}
}
