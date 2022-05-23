/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 09:21:46 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/12/27 21:12:58 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	clear_image(t_data *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(img, x, y, 0);
			++x;
		}
		++y;
	}
}

void	render_next_frame(t_fdf *fdf)
{
	t_data	img;

	img = *(fdf->img);
	clear_image(&img);
	ft_draw_matrix(fdf->img, fdf->map);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
}

int	ft_key_hooker(int key, t_fdf *fdf)
{
	if (key == 38 || key == 40 || key == 37 || \
	key == 32 || key == 34 || key == 31)
		ft_angle_handle(key, fdf);
	if (key == 12 || key == 14)
		ft_zoom_handle(key, fdf);
	if (key == 13 || key == 0 || key == 1 || key == 2)
		ft_translate_handle(key, fdf);
	if (key == 8)
		fdf->map->ceveler_flag *= -1;
	if (key == 53)
		escape_handler(fdf);
	ft_printf("%d \n", key);
	render_next_frame(fdf);
	return (0);
}
