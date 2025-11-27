/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_collision_mur_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:04:58 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/27 17:07:56 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	test_collision_mur(t_cub *m, t_vec2 *q, t_vec2 dir)
{
	(void)dir;
    double r = EPSILON_MUR; // distance minimale aux murs
    int x0 = (int)(q->x - r);
    int x1 = (int)(q->x + r);
    int y0 = (int)(q->y - r);
    int y1 = (int)(q->y + r);

    for (int y = y0; y <= y1; y++)
    {
        for (int x = x0; x <= x1; x++)
        {
            if (m->map[y][x] == CHAR_1)
                return true;
        }
    }
   return false;
}