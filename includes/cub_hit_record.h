/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hit_record.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:08:42 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/25 20:49:10 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_HIT_RECORD
# define CUB_HIT_RECORD

# include "vec3.h"

typedef struct s_cub_hit_record
{
	int	col;
	int	lig;
	t_vec2	delta_dist;
	t_vec2	step;
	t_vec2	side_dist;
	int		side;
} t_cub_hit_record;

#endif
