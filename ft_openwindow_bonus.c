/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_openwindow_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:01:42 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/12/27 21:32:03 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= WIDTH || y >= HIGHT || x <= 0 || y <= 0)
		return ;
	dst = data->addr + (y * data->line_len + x * (data->bits_per_pix / 8));
	*(unsigned int *) dst = color;
}

/* 
*
*
*
*100000  change to zoom add hooks and transform
*
*
*
*/

int	main(int argc, char **argv)
{
	t_data	img;
	t_map	*map;
	t_fdf	fdf;

	if (argc == 2)
	{	
		map = (t_map *)malloc(sizeof(t_map));
		init_map(map);
		fdf.mlx = mlx_init();
		fdf.win = mlx_new_window(fdf.mlx, 1920, 1080, "FDF");
		img.img = mlx_new_image(fdf.mlx, 1920, 1080);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pix, \
		&img.line_len, &img.endian);
		ft_readmap(argv[1], map);
		ft_draw_matrix(&img, map);
		fdf.map = map;
		fdf.img = &img;
		mlx_put_image_to_window(fdf.mlx, fdf.win, img.img, 0, 0);
		mlx_hook(fdf.win, 2, 1L << 0, ft_key_hooker, &fdf);
		mlx_loop(fdf.mlx);
	}
	return (0);
}
