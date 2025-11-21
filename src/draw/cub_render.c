/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:53:25 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/21 16:27:29 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned int get_texture_pixel(t_img *t, int x, int y)
{
	char	*pixel;

	if (x < 0)
		x = 0;
	else if (x >= t->w)
		x = t->w - 1;
	if (y < 0)
		y = 0;
	else if (y >= t->h)
		y = t->h - 1;
	pixel = t->addr + (y * t->size_line + (x * (t->bpp / 8)));
	return (*(unsigned int *) pixel);
}
// static int	get_texture_color(t_cub *m)
// {
// 	int color =  0xff00ff;
// 	if (m->rec.face == FACE_NORTH)
// 		color = 0xff0000;
// 	if (m->rec.face == FACE_EAST)
// 		color = 0x008000;
// 	if (m->rec.face == FACE_WEST)
// 		color = 0x000080;
// 	return (color);
// }
static int	cub_draw_v_wall(t_cub *m, int x)
{
	int 	color;
	double	step;
	t_img	*texture;
	double	texture_position;
	int		y;

	texture = &m->texture[m->rec.face];
	step = cub_div((double)texture->h, m->rec.line_height);
	// cub_print_var_d("t", (double)texture->h);
	// cub_print_var_d("u", m->rec.line_height);
	// cub_print_var_d("s", step);
	texture_position = (m->rec.draw_begin - m->height / 2 + m->rec.line_height / 2) * step;
	y = m->rec.draw_begin;
	while (y <= m->rec.draw_end)
	{
		texture_position += step;
		color = get_texture_pixel(texture, m->rec.p.x, texture_position);
		//cub_putpixel(m, m->rec.texture_x, y, color);
		cub_putpixel(m, x, y, color);
		y++;
	}
	cub_print_var_d("x", x);
	return (y);
}

static	void	cub_draw_vertical_line(t_cub *m, int x)
{
	int	y;

	//m->rec.line_height = /*(int)*/(m->height / m->rec.t); // peut etre a 0 a proteger
	m->rec.line_height = cub_div(m->height, m->rec.t);
	// cub_print_var_d("t", m->height);
	// cub_print_var_d("u", m->rec.t);
	// cub_print_var_d("s", m->rec.line_height);
	m->rec.draw_begin = (m->height - m->rec.line_height) / 2;
	m->rec.draw_end = (m->height + m->rec.line_height) / 2;

	y = 0;
	while (y < m->rec.draw_begin)
		cub_putpixel(m, x, y++, m->color_ceiling);
	y = cub_draw_v_wall(m, x);
	while (y < m->height)
		cub_putpixel(m, x, y++, m->color_floor);
}

void	cub_render(t_cub *m)
{
	int		x;

	x = 0;
	while (x < m->width)
	{
		cub_init_camera(m, x);
		if (cub_hit_grid(m, m->ray, &m->rec))
			cub_draw_vertical_line(m, x);
		x++;
		cub_putpixel(m, x, x, 0xff00ff);
	}
}
