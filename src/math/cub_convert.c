/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:06:38 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/28 16:19:20 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	cub_degrees_to_radians(double degrees)
{
	return (degrees * PI / 180);
}

t_vec2	cub_rotate_xy(t_cub *m, t_vec2 p, double angle)
{
	float	cosa;
	float	sina;
	t_vec2	q;

	(void)m;
	cosa = cos(angle);
	sina = sin(angle);
	q.x = (p.x * cosa - p.y * sina);
	q.y = (p.y * cosa + p.x * sina);
	return (q);
}

void	cub_move_forward(t_cub *m, t_vec2 *p, t_vec2 dir, double step)
{
	t_vec2	q;

	q.x = p->x + dir.x * step;
	q.y = p->y + dir.y * step;
	(void)m;
	/*if (q.x < 1 + EPSILON_MUR || \
		q.y < 1 + EPSILON_MUR || \
		q.x >= m->map_width - 1 - EPSILON_MUR || \
		q.y >= m->map_height - 1 - EPSILON_MUR)
		return ;
	if (test_collision_mur(m, &q, dir))
		return ;*/
	*p = q;
}

void	cub_move_side(t_cub *m, t_vec2 *p, t_vec2 dir, double step)
{
	t_vec2	side;

	side.x = -dir.y;
	side.y = dir.x;
	return (cub_move_forward(m, p, side, step));
}

double	cub_div(double x, double y)
{
	if (y < EPSILON)
		y = EPSILON;
	return (x / y);
}
