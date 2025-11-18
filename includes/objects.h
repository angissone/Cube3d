/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:41:56 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/18 19:25:54 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "vec4.h"
# include "color.h"
# include "interval.h"
# include <stdbool.h>

typedef struct s_param_sphere_hit	t_param_sphere_hit; // CHANGE TO t_param_hit ?

typedef struct s_sphere
{
	t_vec3	center;
	double	radius;
	t_color	color;
}	t_sphere;

typedef struct s_plane
{
	t_vec3	point;
	t_vec3	normal;
	t_color	color;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	center;
	t_vec3	axis;
	double	diameter;
	double	height;
	t_color	color;
}	t_cylinder;

bool	cub_hit_grid(const t_cub *m, const t_ray r, t_hit_record *rec);
bool	cub_sphere_hit(const t_cub *m, t_param_sphere_hit *_);
bool	cub_plane_hit(const t_cub *m, t_param_sphere_hit *_);

#endif
