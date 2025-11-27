/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_collision_mur.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:05:00 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/27 16:47:40 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	test_collision_mur(t_cub *m, t_vec2 *q, t_vec2 dir)
{
	(void)m;
	(void)q;
	(void)dir;

	int cx = (int)(q->x + (dir.x * EPSILON_MUR));
	int cy = (int)(q->y + (dir.y * EPSILON_MUR));

	if (m->map[(int)q->y][cx] == CHAR_1)
		q->x += (int)(q->x + (dir.x * EPSILON_MUR));

	if (m->map[cy][(int)q->x] == CHAR_1)
		q->y += (int)(q->x + (dir.x * EPSILON_MUR));

		return (false);
}
