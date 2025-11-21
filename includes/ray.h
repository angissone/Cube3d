/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:57:47 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/21 15:59:56 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vec3.h"

typedef struct s_cub	t_cub;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	dir;
}	t_ray;

typedef enum e_face
{
	FACE_NORTH = 0,
	FACE_WEST,
	FACE_SOUTH,
	FACE_EAST
}	t_face;

// p : the contact point between ray and the object
typedef struct s_hit_record
{
	t_vec3	p;
	t_vec3	normal;
	double	t;
	t_face		face;
	int		line_height;
	int		draw_begin;
	int		draw_end;
	int 	texture_x;
}	t_hit_record;

t_vec3	ray_at(t_ray ray, double t);

#endif
