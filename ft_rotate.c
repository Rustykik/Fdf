/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 19:06:14 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/12/24 19:15:49 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_cell	*cell, float alpha)
{
	float	matrot[4][4];
	t_cell	cur;

	cur = *cell;
	ft_bzero(matrot, sizeof(matrot));
	matrot[0][0] = 1;
	matrot[1][1] = cosf(alpha);
	matrot[1][2] = sinf(alpha);
	matrot[2][1] = -sinf(alpha);
	matrot[2][2] = cosf(alpha);
	matrot[3][3] = 1;
	multiply_matrix(matrot, &cur, cell);
}

void	rotate_y(t_cell	*cell, float alpha)
{
	float	matrot[4][4];
	t_cell	cur;

	cur = *cell;
	ft_bzero(matrot, sizeof(matrot));
	matrot[0][0] = cosf(alpha);
	matrot[1][1] = 1;
	matrot[2][0] = sinf(alpha);
	matrot[0][2] = -sinf(alpha);
	matrot[2][2] = cosf(alpha);
	matrot[3][3] = 1;
	multiply_matrix(matrot, &cur, cell);
}

void	rotate_z(t_cell	*cell, float alpha)
{
	float	matrot[4][4];
	t_cell	cur;

	cur = *cell;
	ft_bzero(matrot, sizeof(matrot));
	matrot[0][0] = cosf(alpha);
	matrot[1][1] = cosf(alpha);
	matrot[1][0] = -sinf(alpha);
	matrot[0][1] = sinf(alpha);
	matrot[2][2] = 1;
	matrot[3][3] = 1;
	multiply_matrix(matrot, &cur, cell);
}

void	ft_rotate(t_cell	*cell, t_map *map)
{
	rotate_x(cell, map->angle_x);
	rotate_y(cell, map->angle_y);
	rotate_z(cell, map->angle_z);
}
