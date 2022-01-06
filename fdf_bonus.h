/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:22:05 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/12/28 20:20:22 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H
# include "math.h"
# include "minilibx/mlx.h"
# include <fcntl.h>
# include "libft/libft.h"
# include <sys/errno.h>

# include <stdio.h>

# define WIDTH 1920.0f
# define HIGHT 1080.0f

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vec;

typedef struct s_point
{
	int	x;
	int	y;
	int	color;
}	t_point;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pix;
	int		line_len;
	int		endian;
}	t_data;

typedef struct s_cell
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_cell;

typedef struct s_map
{
	float	angle_x;
	float	angle_y;
	float	angle_z;

	int		zoom;

	int		x_pos;
	int		y_pos;

	int		perspective_flag;
	int		ceveler_flag;

	int		x_len;
	int		y_len;
	t_cell	**cells;

}	t_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_data	*img;
}	t_fdf;

void	putline_bresenham(t_data *img, t_cell start, t_cell end);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	ft_readmap(char *path, t_map *map);

void	ft_draw_matrix(t_data *img, t_map *map);

int		ft_key_hooker(int key, t_fdf *fdf);

void	render_next_frame(t_fdf *fdf);

void	free_map(t_map *map);

void	free_split(char **splitted);

void	rotate_x(t_cell	*cell, float alpha);

void	rotate_y(t_cell	*cell, float alpha);

void	rotate_z(t_cell	*cell, float alpha);

void	ft_rotate(t_cell	*cell, t_map *map);

void	multiply_matrix(float mat[4][4], t_cell *cell, t_cell *ret);

void	ft_scale(t_cell	*cell, t_map *map);

void	filling_cells_error(char *string, t_map *map);

void	*split_error(char **split);

void	parse_error(char *string, t_map *map);

void	free_map(t_map *map);

void	free_split(char **splitted);

void	init_cell(t_cell *cell, int x, int y, char **data);

void	init_map(t_map *map);

void	init_point(t_point *point, int x, int y);

int		convert_data_to_int(char *color);

void	escape_handler(t_fdf *fdf);

void	ft_angle_handle(int key, t_fdf *fdf);

void	ft_translate_handle(int key, t_fdf *fdf);

void	ft_zoom_handle(int key, t_fdf *fdf);

void	init_utils_points(t_point *dpoint, t_point *incs, t_cell start, \
t_cell end);

double	percent(int start, int end, int current);

int		get_light(int start, int end, double percentage);

int		get_color(t_point current, t_cell start, t_cell end, t_point delta);

void	init_point_bresenham(t_point *point, t_cell cell);

void	putline_in_last_cells(t_data *img, int y, int x, t_map *map);

void	ft_draw_matrix(t_data *img, t_map *map);

void	ft_projection(t_cell *cell, t_cell *ret, t_map *map);

void	ft_ceveler(t_cell	*cell);

/* mattrix approach 

t_vec	vec_add_num(t_vec *v, float n);
t_vec	vec_mul_num(t_vec *v, float n);
t_vec	vec_div_num(t_vec *v, float n);
float	vec_dot_prod(t_vec *v1, t_vec *v2);
float	vec_len(t_vec *v);
t_vec	vec_normalize(t_vec *v);
t_vec	vec_cross_prod(t_vec *v1, t_vec *v2);
t_vec	vec_sub_num(t_vec *v, float n);
t_vec	vec_add_vec(t_vec *v1, t_vec *v2);
t_vec	vec_substruct_vec(t_vec *v1, t_vec *v2);
void	multiply_matrix_vec(float mat[4][4], t_vec *cell, t_vec *ret);
float	**identity_matrix(void);
float	**matrix_rotation_x(float fAngleRad);
float	**matrix_rotation_y(float fAngleRad);
float	**matrix_rotation_z(float fAngleRad);
float	**matrix_translation(float x, float y, float z);
float	**matrix_projection(float fAngleRad);
float	**multiply_matrix_mat(float mat1[4][4], float mat2[4][4], float mat[4][4]);
*/

#endif