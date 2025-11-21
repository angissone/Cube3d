/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hit_record.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:40:39 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/21 16:21:12 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	cub_hit_grid(const t_cub *m, const t_ray r, t_hit_record *rec)
{
	int 	col;
	int 	lig;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	int		side;

	//cub_print_var_d("mw", m->map_width);
	col = (int) r.origin.x;
	lig = (int) r.origin.y;
	if (r.dir.x)
		delta_dist_x = fabs(1.0 / r.dir.x);
	else
		delta_dist_x = MAX_DOUBLE;
	if (r.dir.y)
		delta_dist_y = fabs(1.0 / r.dir.y);
	else
		delta_dist_y = MAX_DOUBLE;
	if(r.dir.x < 0)
	{
		step_x = -1;
		side_dist_x = (r.origin.x - col) * delta_dist_x;
	}
	else
	{
		step_x = 1;
		side_dist_x = (col + 1.0 - r.origin.x) * delta_dist_x;
	}
	if (r.dir.y < 0)
	{
		step_y = -1;
		side_dist_y = (r.origin.y - lig) * delta_dist_y;
	}
	else
	{
		step_y = 1;
		side_dist_y = (lig + 1.0 - r.origin.y) * delta_dist_y;
	}
	while (1)
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_dist_x;
			col += step_x;
			side = SIDE_VERTICAL;
			if (step_x == 1)
				rec->face = FACE_EAST;
			else
				rec->face = FACE_WEST;
		}
		else
		{
			side_dist_y += delta_dist_y;
			lig += step_y;
			side = SIDE_HORIZONTAL;
			if (step_y == 1)
				rec->face = FACE_NORTH;
			else
				rec->face = FACE_SOUTH;
		}
		if (col < 0 || col >= m->map_width || lig < 0 || lig >= m->map_height)
			return false;
		if (m->map[lig][col] == CHAR_1)
			break;
	}
	//(void)perp_wall_dist;
	if (side == SIDE_VERTICAL)
		rec->t = (side_dist_x - delta_dist_x);
	else
		rec->t = (side_dist_y - delta_dist_y);
	rec->p = vec3_add(r.origin, vec3_scale(r.dir, rec->t));

	// if (side == SIDE_VERTICAL)
	// 	rec->texture_x = m->texture->w * (rec->p.y - (int)(rec->p.y));
	// else
	// 	rec->texture_x = m->texture->w * (rec->p.x - (int)(rec->p.x));
	double wall_x;
	if (side == SIDE_VERTICAL)
		wall_x = rec->p.y - floor(rec->p.y);
	else
		wall_x = rec->p.x - floor(rec->p.x);

	// inversion si nécessaire
	if ((side == SIDE_VERTICAL && r.dir.x > 0) || (side == SIDE_HORIZONTAL && r.dir.y < 0))
		wall_x = 1.0 - wall_x;

	rec->texture_x = (int)(wall_x * m->texture->w);

	//cub_print_var_d("x", 1);
	return true;
}
