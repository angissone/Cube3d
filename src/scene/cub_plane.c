/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:05:37 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/18 19:29:58 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	cub_plane_hit(const t_cub *m, t_param_sphere_hit *_) // change to t_param_hit if applicable
{
	t_vec3	p0;
	t_vec3	n;
	t_vec3	oc;
	double	denom;
	double	t;

	p0 = m->plane[_->i].point;
	n = m->plane[_->i].normal;
	oc = vec3_sub(p0, _->ray.origin); // oc = origin to center
	denom = vec3_dot(n, _->ray.dir); // if denom = 0, oc and ray.dir are parallels (vec3_dot = produit scalaire, composante cle de la projection orthogonale)
	if (fabs(denom) < EPSILON)
		return (false);
	t = vec3_dot(n, oc) / denom;
	if (t <= _->inter.min || t >= _->inter.max)
		return (false);
	_->rec->t = t;
	_->rec->p = ray_at(_->ray, t);
	_->rec->normal = n; // not affected. We take directly the n from the plane
	vec3_normalise_color(m->plane[_->i].color, &_->rec->colorN);
	return (true);
}
