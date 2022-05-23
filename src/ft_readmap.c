/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:35:27 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/12/28 20:07:13 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	count_lines_of_map(char *path, t_map *map)
{
	int		fd;
	char	*string;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: %s", strerror(errno));
		free(map);
		exit(-1);
	}
	map->y_len = 0;
	while (1)
	{
		string = ft_get_next_line(fd);
		if (string == NULL)
			break ;
		free(string);
		string = 0;
		++map->y_len;
	}
	close(fd);
}

int	parse_x_len(char **raw_cells, t_map *map)
{
	int	len;

	len = 0;
	while (raw_cells[len] != NULL)
		++len;
	if (map->x_len == 0)
	{
		map->x_len = len;
		return (1);
	}
	else if (map->x_len != len)
	{
		free_split(raw_cells);
		return (0);
	}
	return (1);
}

static t_cell	*parse_string_into_cells(char *string, t_map *map, int lines)
{
	char	**raw_cells;
	char	**data;
	t_cell	*cells;
	int		len;

	len = 0;
	raw_cells = ft_split(string, ' ');
	if (raw_cells == NULL)
		return (split_error(raw_cells));
	if (!parse_x_len(raw_cells, map))
		parse_error(string, map);
	cells = (t_cell *)ft_calloc(sizeof(t_cell), (map->x_len));
	if (cells == NULL)
		return (split_error(raw_cells));
	while (raw_cells[len] != NULL)
	{
		data = ft_split(raw_cells[len], ',');
		if (data == NULL)
			return (split_error(raw_cells));
		init_cell(&cells[len], len, lines, data);
		++len;
	}
	free_split(raw_cells);
	return (cells);
}

static void	fill_cells_of_map(char *path, t_map *map)
{
	int		lines;
	int		fd;
	char	*string;

	lines = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: %s", strerror(errno));
		free_map(map);
		exit(-1);
	}
	while (lines < map->y_len)
	{
		string = ft_get_next_line(fd);
		if (!string)
			return ;
		map->cells[lines] = parse_string_into_cells(string, map, lines);
		if (map->cells[lines] == NULL)
			filling_cells_error(string, map);
		free(string);
		++lines;
	}
	close(fd);
}

void	ft_readmap(char *path, t_map *map)
{
	int	fd_check;

	fd_check = open(path, O_RDONLY);
	if (fd_check == -1)
	{
		ft_printf("Error: %s", strerror(errno));
		free(map);
		exit(-1);
	}
	map->x_len = 0;
	count_lines_of_map(path, map);
	map->cells = (t_cell **)ft_calloc(sizeof(t_cell *), (map->y_len));
	if (map->cells == NULL)
	{
		ft_printf("Error: %s", strerror(errno));
		free(map);
		exit(-1);
	}
	fill_cells_of_map(path, map);
}
