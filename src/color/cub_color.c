/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:30:50 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/18 19:42:59 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_vec3	learp(float x, t_vec3 v0, t_vec3 v1) // WHY learp AND NOT lerp ?
{		// IS IT FOR “linear extrapolation” — I.E., USING X OUTSIDE [0, 1] RANGE?
	return (
		vec3_add(
			vec3_scale(v0, 1 - x),
			vec3_scale(v1, x)
		)
	);
}

static	t_vec3	get_bckgnd_color(t_ray ray) // BACKROUND COLOR GRADIANT WITH Y AXIS
{
	t_vec3	vect_unit;
	double	a;
	t_vec3	color_start;
	t_vec3	color_end;

	color_start = int_to_color(COLOR_BCKGND_BOTTOM);
	//cub_print_vec("v0", color_start);
	color_end = int_to_color(COLOR_BCKGND_TOP);
	//cub_print_vec("v1", color_end);
	vect_unit = vec3_normalize(ray.dir);
	//cub_print_vec("vect_unit", vect_unit);
	a = 0.5 * (vect_unit.v[1] + 1.0); // NORMALIZED VALUE BETWEEN [0.0,1.0]
	//cub_print_var_d("a", a);
	return (learp(a, color_start, color_end));
}

// TODO si ray non modifie supprimer le parametre t_ray ray
t_vec3		ray_color(t_cub *m, const t_ray ray)
{
	t_vec3	color;
	t_hit_record	rec;
	double shade;


	if (cub_hit_grid(m, ray, &rec))
	{
		shade = 1.0 / (1 + rec.t * SHADE_RATIO);
		color = vec3_init(shade, shade, shade);
		return (color);
	}
	else
	{
		color = get_bckgnd_color(m->ray);
		// cub_print_vec("color", color);
		// cub_print_color("color=", color);
	}
	return (color);
}

