/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 19:26:13 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/12/27 21:12:48 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	convert_data_to_int(char *color)
{
	int	len_of_num;
	int	pow;
	int	ret;
	int	num;

	ret = 0;
	pow = 0;
	len_of_num = ft_strlen(color);
	if (!color)
		return (0);
	while (color[len_of_num - 1] != 'x')
	{
		if (color[len_of_num - 1] >= '0' && color[len_of_num - 1] <= '9')
			num = color[len_of_num - 1] - 48;
		else
			num = color[len_of_num - 1] - 55;
		ret += num * ft_pow(16, pow);
		--len_of_num;
		++pow;
	}
	return (ret);
}

void	init_cell(t_cell *cell, int x, int y, char **data)
{
	cell->x = x;
	cell->y = y;
	cell->z = -(ft_atoi(data[0]));
	if (data[1])
		cell->color = convert_data_to_int(data[1]);
	else
		cell->color = 0xffffff;
	free_split(data);
}

void	init_map(t_map *map)
{
	map->angle_x = -0.3f;
	map->angle_y = -0.25f;
	map->angle_z = -0.75f;
	map->zoom = 350;
	map->x_pos = (WIDTH / 3);
	map->y_pos = (HIGHT / 2);
	map->perspective_flag = -1;
	map->ceveler_flag = -1;
}

void	init_point(t_point *point, int x, int y)
{
	point->x = x;
	point->y = y;
}
