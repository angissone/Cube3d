/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_mat4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:50:17 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/18 19:52:14 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// rx = (m00 * vx) + (m01 * vy) + (m02 * vz) + (m03 *vw)
t_vec3	mat4_mult_vec3(t_mat4 m, t_vec3 v)
{
	t_vec3	ret;
	int		l;
	int		c;

	l = 0;
	while (l < 3)
	{
		ret.v[l] = 0;
		c = 0;
		while (c < 3)
		{
				ret.v[l] += m.m[l][c] * v.v[c];
				c++;
		}
		l++;
	}
	return (ret);
}
