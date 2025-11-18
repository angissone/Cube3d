/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_vec4_rnd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:25:15 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/18 19:41:01 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vec3	vec3_rnd_dbl(t_cub *m)
{
	return (vec3_init(random_double(m), random_double(m), random_double(m)));
}

t_vec3	vec3_rnd_dbl_rng(t_cub *m, double min, double max)
{
	return ( vec3_init( \
		random_double_range(m, min, max), \
		random_double_range(m, min, max), \
		random_double_range(m, min, max)));
}

t_vec3	vec3_rnd_unit(t_cub *m)
{
	t_vec3	v;
	double	lensq;

	while (true)
	{
		v = vec3_rnd_dbl_rng(m, -1, 1);
		lensq = vec3_sqr_length(v);
		if (lensq >= C_1_160 && lensq <= 1)
			return (vec3_scale(v, 1 / sqrt(lensq)));
	}
}


// t_vec3	vec3_rnd_unit(t_cub *m)
// {
// 	double z = random_double_range(m, -1.0, 1.0);
// 	double a = random_double_range(m, 0.0, 2.0 * PI);
// 	double r = sqrt(1.0 - z * z);
// 	double x = r * cos(a);
// 	double y = r * sin(a);
// 	return vec3_init(x, y, z, 0.0);
// }


t_vec3 random_on_hemisphere(t_cub *m, const t_vec3 normal)
{
	t_vec3	ret;

	ret = vec3_rnd_unit(m);
	if (vec3_dot(ret, normal) > 0)
		return (ret);
	else
		return (vec3_scale(ret, -1));
}
