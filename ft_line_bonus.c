/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:38:59 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/12/27 21:12:41 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	bresenham_1(t_data *img, t_cell start, t_cell end)
{
	t_point	point;
	t_point	dpoint;
	t_point	incs;
	int		balance;
	int		color;

	init_utils_points(&dpoint, &incs, start, end);
	init_point_bresenham(&point, start);
	dpoint.y <<= 1;
	balance = dpoint.y - dpoint.x;
	dpoint.x <<= 1;
	while (point.x != (int)end.x)
	{
		color = get_color(point, start, end, dpoint);
		my_mlx_pixel_put(img, point.x, point.y, color);
		if (balance >= 0)
		{
			point.y += incs.y;
			balance -= dpoint.x;
		}
		balance += dpoint.y;
		point.x += incs.x;
	}
	color = get_color(point, start, end, dpoint);
	my_mlx_pixel_put(img, point.x, point.y, color);
}

void	bresenham_2(t_data *img, t_cell start, t_cell end)
{
	t_point	point;
	t_point	dpoint;
	t_point	incs;
	int		balance;
	int		color;

	init_utils_points(&dpoint, &incs, start, end);
	init_point_bresenham(&point, start);
	dpoint.x <<= 1;
	balance = dpoint.x - dpoint.y;
	dpoint.y <<= 1;
	while (point.y != (int)end.y)
	{
		color = get_color(point, start, end, dpoint);
		my_mlx_pixel_put(img, point.x, point.y, color);
		if (balance >= 0)
		{
			point.x += incs.x;
			balance -= dpoint.y;
		}
		balance += dpoint.x;
		point.y += incs.y;
	}
	color = get_color(point, start, end, dpoint);
	my_mlx_pixel_put(img, point.x, point.y, color);
}

void	putline_bresenham(t_data *img, t_cell start, t_cell end)
{
	t_point	dpoint;
	t_point	incs;

	init_utils_points(&dpoint, &incs, start, end);
	if (dpoint.x >= dpoint.y)
	{
		bresenham_1(img, start, end);
	}
	else
	{
		bresenham_2(img, start, end);
	}
}
