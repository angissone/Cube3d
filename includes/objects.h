/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:41:56 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/28 16:31:38 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "vec4.h"
# include "color.h"
# include <stdbool.h>

bool	cub_hit_grid(const t_cub *m, const t_ray r, t_hit_record *rec);
char	get_map(const t_cub *m, int lig, int col);

#endif
