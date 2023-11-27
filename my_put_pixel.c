/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:31:54 by ynafiss           #+#    #+#             */
/*   Updated: 2023/07/30 18:03:04 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	put_one_pixel(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	if (x < 1200 && y < 1000)
	{
		dst = data->draw_image + (y * data->line_length \
		+ x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	put_all_pixel(t_mlx *var, int x, int color)
{
	if (x < 0 && x > W)
		return ;
	while (x < W * H)
	{
		var->draw_image[x] = color;
		x++;
	}
}

void	draw_sky_floor(t_mlx *p, double start, int i, double end)
{
	int	r;

	r = 0;
	while (r < start)
		put_one_pixel(p, i, r++, p->sky);
	while (end < H)
		put_one_pixel(p, i, end++, p->floor);
}
