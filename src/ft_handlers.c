/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:31:11 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/12/27 20:14:55 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	escape_handler(t_fdf *fdf)
{
	free_map(fdf->map);
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit(0);
}
