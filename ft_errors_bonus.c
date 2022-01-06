/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 19:21:13 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/12/28 20:08:38 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	free_split(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		++i;
	}
	free(splitted);
}

void	free_map(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->y_len && map->cells[y])
	{
		free(map->cells[y]);
		++y;
	}
	free(map->cells);
	free(map);
}

void	*split_error(char **split)
{
	ft_printf("Error: %s", strerror(errno));
	if (split)
		free_split(split);
	return (NULL);
}

void	filling_cells_error(char *string, t_map *map)
{
	ft_printf("Error: %s", strerror(errno));
	free(string);
	free_map(map);
	exit(-1);
}

void	parse_error(char *string, t_map *map)
{
	ft_printf("Error: wrong map");
	free(string);
	free_map(map);
	exit(-1);
}
