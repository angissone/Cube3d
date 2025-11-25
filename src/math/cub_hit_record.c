/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hit_record.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:40:39 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/25 19:39:38 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	set_step_side_dist \
// 	(const t_ray r, t_vec2 delta_dist, t_vec2	step, t_vec2 side_dist)
// {

// 	if(r.dir.x < 0)
// 	{
// 		step.x = -1;
// 		side_dist.x = (r.origin.x - _.col) * delta_dist.x;
// 	}
// 	else
// 	{
// 		step.x = 1;
// 		side_dist.x = (_.col + 1.0 - r.origin.x) * delta_dist.x;
// 	}
// 	if (r.dir.y < 0)
// 	{
// 		step.y = -1;
// 		side_dist.y = (r.origin.y - _.lig) * delta_dist.y;
// 	}
// 	else
// 	{
// 		step.y = 1;
// 		side_dist.y = (_.lig + 1.0 - r.origin.y) * delta_dist.y;
// 	}
// }

bool	cub_hit_grid(const t_cub *m, const t_ray r, t_hit_record *rec)
{
	t_dim2	_;
	t_vec2	delta_dist;
	t_vec2	step;
	t_vec2	side_dist;
	int		side;

	_.col = (int) r.origin.x;
	_.lig = (int) r.origin.y;
	if (r.dir.x)
		delta_dist.x = fabs(1.0 / r.dir.x);
	else
		delta_dist.x = MAX_DOUBLE;
	if (r.dir.y)
		delta_dist.y = fabs(1.0 / r.dir.y);
	else
		delta_dist.y = MAX_DOUBLE;
	if(r.dir.x < 0)
	{
		step.x = -1;
		side_dist.x = (r.origin.x - _.col) * delta_dist.x;
	}
	else
	{
		step.x = 1;
		side_dist.x = (_.col + 1.0 - r.origin.x) * delta_dist.x;
	}
	if (r.dir.y < 0)
	{
		step.y = -1;
		side_dist.y = (r.origin.y - _.lig) * delta_dist.y;
	}
	else
	{
		step.y = 1;
		side_dist.y = (_.lig + 1.0 - r.origin.y) * delta_dist.y;
	}
	while (1)
	{
		if (side_dist.x < side_dist.y)
		{
			side_dist.x += delta_dist.x;
			_.col += step.x;
			side = SIDE_VERTICAL;
			if (step.x == 1)
				rec->face = FACE_EAST;
			else
				rec->face = FACE_WEST;
		}
		else
		{
			side_dist.y += delta_dist.y;
			_.lig += step.y;
			side = SIDE_HORIZONTAL;
			if (step.y == 1)
				rec->face = FACE_NORTH;
			else
				rec->face = FACE_SOUTH;
		}
		if (_.col < 0 || _.col >= m->map_width || _.lig < 0 || _.lig >= m->map_height)
			return false;
		if (m->map[_.lig][_.col] == CHAR_1)
			break;
	}
	if (side == SIDE_VERTICAL)
		rec->t = (side_dist.x - delta_dist.x);
	else
		rec->t = (side_dist.y - delta_dist.y);
	rec->p = vec3_add(r.origin, vec3_scale(r.dir, rec->t));

	if (side == SIDE_VERTICAL)
		rec->texture_x = m->texture->w * (rec->p.y - floor(rec->p.y));
	else
		rec->texture_x = m->texture->w * (rec->p.x - floor(rec->p.x));
	// if ( (side==0 && r.dir.x>0) || (side==1 && r.dir.y<0) )
	// 	rec->texture_x  = m->texture->w - rec->texture_x - 1;

	// //cub_print_var_d("x", 1);
	return true;
}
