/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_collision_mur_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:04:58 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/27 16:32:17 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	test_collision_mur(t_cub *m, t_vec2 *q, t_vec2 dir)
{
	int cx = (int)(q->x + (dir.x * EPSILON_MUR));
	int cy = (int)(q->y + (dir.y * EPSILON_MUR));
	if (m->map[(int)q->y][cx] == CHAR_1)
		return (true);
	if (m->map[cy][(int)q->x] == CHAR_1)
		return (true);
	return (false);

	// if(m->map[(int)q->y][(int)q->x] == CHAR_1)
	// 	return (true);
	// return (false);


}