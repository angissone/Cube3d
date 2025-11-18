/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:05:37 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/18 19:29:58 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// (C-P(t) . C-P(t) = r^2) with P(t)=Q+t*d
// t^2*d⋅d −2td⋅(C−Q) + (C−Q)⋅(C−Q)−r^2=0
bool	cub_sphere_hit(const t_cub *m, t_param_sphere_hit *_)
{
	double	a;
	double	b;
	double	c;
	t_vec3	oc;
	double	delta;
	double	t;
	t_vec3	center;
	double radius;

	center = m->sphere[_->i].center;
	radius = m->sphere[_->i].radius;
	oc = vec3_sub (center, _->ray.origin);
	a = vec3_dot(_->ray.dir, _->ray.dir);
	b = -2 * vec3_dot(_->ray.dir, oc);
	c = vec3_dot(oc, oc) - radius * radius;
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (false);
	t = ((-b - sqrt(delta)) / (2 * a));
	if (t <= _->inter.min || t >= _->inter.max)
	{
		t = ((-b + sqrt(delta)) / (2 * a));
		if (t <= _->inter.min || t >= _->inter.max)
			return (false);
	}
	_->rec->t = t;
	_->rec->p = ray_at(_->ray, _->rec->t);
	// cub_print_vec("p     ", _->rec->p);
	// cub_print_vec("center", center);
	set_face_normal(_->ray, vec3_scale(vec3_sub(_->rec->p, center), 1. / radius), _->rec);
	// cub_print_vec("NORMAL", _->rec->normal);
	// cub_print_var_d("LENGTH", vec3_sqr_length(_->rec->normal));
	vec3_normalise_color(m->sphere[_->i].color, &_->rec->colorN);
	return (true);
}
