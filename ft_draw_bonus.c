/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 22:34:38 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/12/28 19:19:41 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
first - second
|
third

*-*
|    ==>> iterate threw hole map connecting with lines three points 
*
*/

#include "fdf_bonus.h"

void	multiply_matrix(float mat[4][4], t_cell *cell, t_cell *ret)
{
	float	w;

	ret->x = cell->x * mat[0][0] + cell->y * mat[1][0] \
	+ cell->z * mat[2][0] + mat[3][0];
	ret->y = cell->x * mat[0][1] + cell->y * mat[1][1] \
	+ cell->z * mat[2][1] + mat[3][1];
	ret->z = cell->x * mat[0][2] + cell->y * mat[1][2] \
	+ cell->z * mat[2][2] + mat[3][2];
	w = cell->x * mat[0][3] + cell->y * mat[1][3] + \
	cell->z * mat[2][3] + mat[3][3];
	if (w != 0.0f)
	{
		ret->x /= w;
		ret->y /= w;
		ret->z /= w;
	}
	ret->color = cell->color;
}

void	ft_scale(t_cell	*cell, t_map *map)
{
	float	x;
	float	y;

	x = cell->x;
	y = cell->y;
	cell->x = 100 * (x / map->x_len);
	cell->x *= (WIDTH / map->zoom);
	cell->x += map->x_pos;
	cell->y = 100 * (y / map->y_len);
	cell->y *= (HIGHT / map->zoom);
	cell->y += map->y_pos;
}

/*
void	ft_perspective(t_cell *cell)
{
	t_cell	cur;
	float	aspect_ratio;
	float	fov_rad;
	float	mat[4][4];

	ft_bzero(mat, sizeof(mat));
	cur = *cell;
	aspect_ratio = HIGHT / WIDTH;
	fov_rad = 1.0f / tanf(FOV * 0.5f / 180.0f * 3.14159f);
	mat[0][0] = aspect_ratio * fov_rad;
	mat[1][1] = fov_rad;
	mat[2][2] = 10.0f / (10.0f - 0.001f);
	// mat[3][2] = -1; // ?
	mat[3][2] =  (-10.0f * 0.001f) / (10.0f - 0.001f); // 2 * ?
	mat[2][3] = 1.0f;
	mat[3][3] = 0.0f;
	multiply_matrix(mat, &cur, cell);
}
*/

void	ft_ceveler(t_cell	*cell)
{
	t_cell	cur;

	cur = *cell;
	if (sqrtf(cell->x * cell->x + cell->y * \
	cell ->y + cell->z * cell->z) != 0.0f )
	{
		cur.x = cell->x * 1000 / sqrtf(cell->x * cell->x + \
		cell->y * cell ->y + cell->z * cell->z);
		cur.y = cell->y * 1000 / sqrtf(cell->x * cell->x + \
		cell->y * cell ->y + cell->z * cell->z);
	}
	cell->x = cur.x + WIDTH / 2;
	cell->y = cur.y + HIGHT / 2;
}

void	ft_projection(t_cell *cell, t_cell *ret, t_map *map)
{
	*ret = *cell;
	if (map->ceveler_flag == 1)
	{
		ft_rotate(ret, map);
		ft_ceveler(ret);
	}
	else
	{
		ft_rotate(ret, map);
		ft_scale(ret, map);
	}
}

void	ft_draw_matrix(t_data *img, t_map *map)
{
	int		x;
	int		y;
	t_cell	fst_proj;
	t_cell	sec_proj;
	t_cell	trd_proj;

	y = 0;
	while (y < map->y_len - 1)
	{
		x = 0;
		while (x < map->x_len - 1)
		{
			ft_bzero(&fst_proj, sizeof(t_cell));
			ft_bzero(&sec_proj, sizeof(t_cell));
			ft_bzero(&trd_proj, sizeof(t_cell));
			ft_projection(&(map->cells[y][x]), &fst_proj, map);
			ft_projection(&(map->cells[y][x + 1]), &sec_proj, map);
			ft_projection(&(map->cells[y + 1][x]), &trd_proj, map);
			putline_bresenham(img, fst_proj, sec_proj);
			putline_bresenham(img, fst_proj, trd_proj);
			putline_in_last_cells(img, y, x, map);
			++x;
		}
		++y;
	}
}
