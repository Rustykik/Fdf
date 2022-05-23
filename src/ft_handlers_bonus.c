/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:31:11 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/12/27 21:13:03 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	escape_handler(t_fdf *fdf)
{
	free_map(fdf->map);
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit(0);
}

void	ft_angle_handle(int key, t_fdf *fdf)
{
	if (key == 38)
		fdf->map->angle_x -= 0.05f;
	if (key == 40)
		fdf->map->angle_y -= 0.05f;
	if (key == 37)
		fdf->map->angle_z -= 0.05f;
	if (key == 32)
		fdf->map->angle_x += 0.05f;
	if (key == 34)
		fdf->map->angle_y += 0.05f;
	if (key == 31)
		fdf->map->angle_z += 0.05f;
}

void	ft_translate_handle(int key, t_fdf *fdf)
{
	if (key == 13)
		fdf->map->y_pos -= 3;
	if (key == 1)
		fdf->map->y_pos += 3;
	if (key == 0)
		fdf->map->x_pos -= 3;
	if (key == 2)
		fdf->map->x_pos += 3;
}

void	ft_zoom_handle(int key, t_fdf *fdf)
{
	if (key == 12)
		fdf->map->zoom += 10;
	if (key == 14)
		fdf->map->zoom -= 10;
}
