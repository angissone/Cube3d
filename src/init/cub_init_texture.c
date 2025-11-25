/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:36:37 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/25 17:19:58 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cub_init_xpm(t_cub *m, int index)
{
	t_img	*im;
	char	*file;

	im = &m->texture[index];
	file = m->file_texture[index];
	im->img = mlx_xpm_file_to_image(m->mlx, file, &im->w, &im->h);
	if (im->img == NULL)
		cub_pexit(file, m);
	im->addr = \
		mlx_get_data_addr(im->img, &im->bpp, &im->size_line, &im->endian);
}

void	cub_init_texture(t_cub *m)
{
	cub_init_xpm(m, FACE_NORTH);
	cub_init_xpm(m, FACE_WEST);
	cub_init_xpm(m, FACE_SOUTH);
	cub_init_xpm(m, FACE_EAST);
}
