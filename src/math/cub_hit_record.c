/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hit_record.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:40:39 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/28 16:22:25 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_delta_dist(t_cub_hit_record *t, const t_ray *r)
{
	t->col = (int) r->origin.x;
	t->lig = (int) r->origin.y;
	if (r->dir.x)
		t->delta_dist.x = fabs(1.0 / r->dir.x);
	else
		t->delta_dist.x = MAX_DOUBLE;
	if (r->dir.y)
		t->delta_dist.y = fabs(1.0 / r->dir.y);
	else
		t->delta_dist.y = MAX_DOUBLE;
}

static void	set_step_side_dist(t_cub_hit_record *t, const t_ray *r)
{
	if (r->dir.x < 0)
	{
		t->step.x = -1;
		t->side_dist.x = (r->origin.x - t->col) * t->delta_dist.x;
	}
	else
	{
		t->step.x = 1;
		t->side_dist.x = (t->col + 1.0 - r->origin.x) * t->delta_dist.x;
	}
	if (r->dir.y < 0)
	{
		t->step.y = -1;
		t->side_dist.y = (r->origin.y - t->lig) * t->delta_dist.y;
	}
	else
	{
		t->step.y = 1;
		t->side_dist.y = (t->lig + 1.0 - r->origin.y) * t->delta_dist.y;
	}
}

static void	set_rec_face(t_cub_hit_record *t, t_hit_record *rec)
{
	if (t->side_dist.x < t->side_dist.y)
	{
		t->side_dist.x += t->delta_dist.x;
		t->col += t->step.x;
		t->side = SIDE_VERTICAL;
		if (t->step.x == 1)
			rec->face = FACE_EAST;
		else
			rec->face = FACE_WEST;
	}
	else
	{
		t->side_dist.y += t->delta_dist.y;
		t->lig += t->step.y;
		t->side = SIDE_HORIZONTAL;
		if (t->step.y == 1)
			rec->face = FACE_NORTH;
		else
			rec->face = FACE_SOUTH;
	}
}

char	get_map(const t_cub *m, int lig, int col)
{
	//return (m->map[m->map_height - 1 - lig][col]);
	int	row;
	int	len;

	row = m->map_height - 1 - lig;
	if (row < 0 || row >= m->map_height)
		return (CHAR_1);
	if (m->map[row] == NULL)
		return (CHAR_1);
	len = ft_strlen(m->map[row]);
	if (col < 0 || col >= len)
		return (CHAR_1);
	return (m->map[row][col]);
}

bool	cub_hit_grid(const t_cub *m, const t_ray r, t_hit_record *rec)
{
	t_cub_hit_record	t;

	set_delta_dist(&t, &r);
	set_step_side_dist(&t, &r);
	while (1)
	{
		set_rec_face(&t, rec);
		if (t.col < 0 || t.col >= m->map_width \
			|| t.lig < 0 || t.lig >= m->map_height)
			return (false);
		if (get_map(m, t.lig, t.col) == CHAR_1)
			break ;
	}
	if (t.side == SIDE_VERTICAL)
		rec->t = (t.side_dist.x - t.delta_dist.x);
	else
		rec->t = (t.side_dist.y - t.delta_dist.y);
	rec->p = ray_at(r, rec->t);
	if (t.side == SIDE_VERTICAL)
		rec->texture_x = m->texture->w * (rec->p.y - floor(rec->p.y));
	else
		rec->texture_x = m->texture->w * (rec->p.x - floor(rec->p.x));
	if (rec->t < EPSILON)
		rec->t = EPSILON;
	return (true);
}
