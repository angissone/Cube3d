/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 20:06:43 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/25 19:41:45 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

typedef struct s_cub	t_cub;

typedef union s_vec2
{
	struct {
		double	x;
		double	y;
	};
}	t_vec2;

typedef struct s_dim2
{
	int	col;
	int	lig;
}	t_dim2;

typedef union s_vec3
{
	struct {
		double	x;
		double	y;
		double	z;
	};
	double	v[3];
}	t_vec3;

t_vec3	vec3_scale(t_vec3 v, double t);
t_vec3	vec3_add(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_sub(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_init(double x, double y, double z);
double	vec3_sqr_length(t_vec3 v);
t_vec3	vec3_normalize(t_vec3 v);
double	vec3_dot(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_rnd_dbl(t_cub *m);
t_vec3	vec3_rnd_dbl_rng(t_cub *m, double min, double max);
t_vec3	vec3_rnd_unit(t_cub *m);
t_vec3	random_on_hemisphere(t_cub *m, const t_vec3 normal);
t_vec3	vec3_hadamard_product(t_vec3 u, t_vec3 v);
t_vec3	vec3_cross(t_vec3 u, t_vec3 v);

#endif
