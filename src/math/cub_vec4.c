/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_vec4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:50:17 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/18 19:37:09 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vec3	vec3_scale(t_vec3 v, double t)
{
	t_vec3	ret;
	int		i;

	i = 0;
	while (i < 3)
	{
		ret.v[i] = v.v[i] * t;
			i++;
	}
	return (ret);
}

t_vec3	vec3_add(t_vec3 v1, t_vec3 v2)
{
	t_vec3	ret;
	int		i;

	i = 0;
	while (i < 3)
	{
		ret.v[i] = v1.v[i] + v2.v[i];
		i++;
	}
	return (ret);
}


t_vec3	vec3_sub(t_vec3 v1, t_vec3 v2)
{
	t_vec3	ret;
	int		i;

	i = 0;
	while (i < 3)
	{
		ret.v[i] = v1.v[i] - v2.v[i];
		i++;
	}
	return (ret);
}


t_vec3	vec3_init(double x, double y, double z)
{
	t_vec3	ret;
	ret.v[0] = x;
	ret.v[1] = y;
	ret.v[2] = z;
	return (ret);
}

double	vec3_sqr_length(t_vec3 v)
{
	return (v.v[0] * v.v[0] + v.v[1] * v.v[1] + v.v[2] * v.v[2]);
}

t_vec3	vec3_normalize(t_vec3 v)
{
	t_vec3	ret;
	int		i;
	double	inv_len;

	inv_len = 1 / sqrt(vec3_sqr_length(v));
	i = 0;
	while (i < 3)
	{
		ret.v[i] = v.v[i] * inv_len;
		i++;
	}
	return (ret);
}

double	vec3_dot(t_vec3 v1, t_vec3 v2)
{
	double	ret;
	int	i;

	ret = 0;
	i = 0;
	while (i < 3)
	{
		ret += v1.v[i] * v2.v[i];
		i++;
	}
	return (ret);
}

t_vec3 vec3_hadamard_product(t_vec3 u, t_vec3 v)
{
	t_vec3	ret;
	int	i;

	i = 0;
	while (i < 3)
	{
		ret.v[i] = u.v[i] * v.v[i];
		i++;
	}
	return (ret);
}

t_vec3 vec3_cross(t_vec3 u, t_vec3 v)
{
	t_vec3 r;
	r.v[0] = u.v[1] * v.v[2] - u.v[2] * v.v[1];
	r.v[1] = u.v[2] * v.v[0] - u.v[0] * v.v[2];
	r.v[2] = u.v[0] * v.v[1] - u.v[1] * v.v[0];
	return (r);
}
