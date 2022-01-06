/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:17:58 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/12/28 19:19:15 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	putline_in_last_cells(t_data *img, int y, int x, t_map *map)
{
	t_cell	fst_proj;
	t_cell	sec_proj;

	if (x == map->x_len - 2)
	{
		ft_bzero(&fst_proj, sizeof(t_cell));
		ft_bzero(&sec_proj, sizeof(t_cell));
		ft_projection(&(map->cells[y][x + 1]), &fst_proj, map);
		ft_projection(&(map->cells[y + 1][x + 1]), &sec_proj, map);
		putline_bresenham(img, fst_proj, sec_proj);
	}
	if (y == map->y_len - 2)
	{
		ft_bzero(&fst_proj, sizeof(t_cell));
		ft_bzero(&sec_proj, sizeof(t_cell));
		ft_projection(&(map->cells[y + 1][x]), &fst_proj, map);
		ft_projection(&(map->cells[y + 1][x + 1]), &sec_proj, map);
		putline_bresenham(img, fst_proj, sec_proj);
	}
}
