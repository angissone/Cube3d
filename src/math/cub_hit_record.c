/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hit_record.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:40:39 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/18 19:45:14 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_face_normal(t_ray ray, t_vec3 outward_normal, t_hit_record *rec)
{
	rec->front_face = vec3_dot(ray.dir, outward_normal) < 0;
	if (rec->front_face)
		rec->normal = outward_normal;
		//rec->normal = vec3_scale(outward_normal, -1);
	else
		rec->normal = vec3_scale(outward_normal, -1);
}

bool	cub_hit_grid(const t_cub *m, const t_ray r, t_hit_record *rec)
{
	int 	map_x;
	int 	map_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	int		hit;
	int		side;
	double	perp_wall_dist;

	map_x = (int) r.origin.v[0];
	map_y = (int) r.origin.v[1];
	ray_dir_x = r.dir.v[0];
	ray_dir_y = r.dir.v[1];
	delta_dist_x = (ray_dir_x != 0) ? fabs(1.0 / ray_dir_x) : MAX_DOUBLE;
	delta_dist_y = (ray_dir_y != 0) ? fabs(1.0 / ray_dir_y) : MAX_DOUBLE;

	if(ray_dir_x < 0)
	{
		step_x = -1;
		side_dist_x = (r.origin.v[0] - map_x) * delta_dist_x;
	}
	else
	{
		step_x = 1;
		side_dist_x = (map_x + 1.0 - r.origin.v[0]) * delta_dist_x;
	}
	if (ray_dir_y < 0)
	{
		step_y = -1;
		side_dist_y = (r.origin.v[1] - map_y) * delta_dist_y;
	}
		else
	{
		step_y = 1;
		side_dist_y = (map_y + 1.0 - r.origin.v[1]) * delta_dist_y;
	}
	hit = HIT_0;
	while (hit == HIT_0)
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_dist_x;
			map_x += step_x;
			side = SIDE_0;
		}
		else
		{
			side_dist_y += delta_dist_y;
			map_y += step_y;
			side = SIDE_1;
		}
		if (map_x < 0 || map_x >= m->map_width || map_y < 0 || map_y >= m->map_height)
			return false;
		if (m->map[map_y][map_x] == CHAR_1)
			hit = HIT_1;
	}
	if (side == SIDE_0)
		perp_wall_dist = (side_dist_x - delta_dist_x);
	else
		perp_wall_dist = (side_dist_y - delta_dist_y);
	rec->t = perp_wall_dist;
	rec->p = vec3_add(r.origin, vec3_scale(r.dir, rec->t));

	if (side == SIDE_0)
		rec->normal = (t_vec3){ .v = { (r.dir.v[0] > 0) ? -1 : 1, 0, 0 } };
	else
		rec->normal = (t_vec3){ .v = { 0, (r.dir.v[1] > 0) ? -1 : 1, 0 } };

	rec->front_face = true;
	rec->colorN = int_to_color(COLOR_BCKGND);
	return true;

}
