/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_chaine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:01:46 by zmata             #+#    #+#             */
/*   Updated: 2025/12/01 13:13:05 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cub3d.h"

int	len_line_i(t_node **list_map, int which_line)
{
	t_node	*tmp;
	int		z;

	if (!list_map || !(*list_map))
		return (-1);
	tmp = *list_map;
	z = 0;
	while (tmp != NULL)
	{
		if (z == which_line)
			return (ft_strlen(tmp->line));
		tmp = tmp->next;
		z++;
	}
	return (-1);
}

void	new_value(char *new_line, t_node **list_map)
{
	t_node	*new;
	t_node	*tmp;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->line = ft_strdup(new_line);
	new->next = NULL;
	if (*list_map == NULL)
	{
		*list_map = new;
		return ;
	}
	tmp = *list_map;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void	printf_liste(t_node **list_map)
{
	t_node	*tmp;

	tmp = *list_map;
	while (tmp != NULL)
	{
		printf("liste chaine ligne = %s\n", tmp->line);
		tmp = tmp->next;
	}
}

char	*return_line_i_to_liste(t_node **list_map, int which_line)
{
	t_node	*tmp;
	int		z;

	if (!list_map || !(*list_map))
		return (NULL);
	tmp = *list_map;
	z = 0;
	while (z < which_line)
	{
		tmp = tmp->next;
		z++;
	}
	return (tmp->line);
}

void	free_list(t_node *lst)
{
	t_node	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst->line);
		free(lst);
		lst = tmp;
	}
}
