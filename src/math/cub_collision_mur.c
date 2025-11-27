/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_collision_mur.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:05:00 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/27 18:31:01 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	test_collision_mur_(t_cub *m, t_vec2 *q, t_vec2 dir)
{
	t_dim2	_x;
	t_dim2	_y;
	int		x;
	int		y;

	(void)dir;
	_x.v0 = (int)(q->x - EPSILON_MUR);
	_x.v1 = (int)(q->x + EPSILON_MUR);
	_y.v0 = (int)(q->y - EPSILON_MUR);
	_y.v1 = (int)(q->y + EPSILON_MUR);
	y = _y.v0;
	while (y <= _y.v1)
	{
		x = _x.v0;
		while (x <= _x.v1)
		{
			if (m->map[y][x] == CHAR_1)
				return (true);
			x++;
		}
		y++;
	}
	return (false);
}

int	test_collision_mur(t_cub *m, t_vec2 *q, t_vec2 dir)
{
	int		hit;

	hit = test_collision_mur_(m, q, dir);
	if (hit)
	{
		// if (dir.x > 0)      q->x = floor(q->x) + (1.0 - EPSILON_MUR);
		// else if (dir.x < 0) q->x = ceil(q->x)  + (EPSILON_MUR);

		// if (dir.y > 0)      q->y = floor(q->y) + (1.0 - EPSILON_MUR);
		// else if (dir.y < 0) q->y = ceil(q->y)  + (EPSILON_MUR);
	}

	return (false);
}
