/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_info_color_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:10:00 by ybouroga          #+#    #+#             */
/*   Updated: 2025/12/01 13:10:29 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_valid(char *str, int *i)
{
	int	z;

	z = *i;
	while ((str[z] >= '0' && str[z] <= '9')
		|| str[z] == ' ' || str[z] == '\t'
		|| str[z] == '\n' || str[z] == ',')
		z++;
	if (str[z] == '\0')
		return (1);
	return (0);
}

int	has_only_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	return (str[i] == '\0');
}

void	color_error(char *line, char *tmp, t_info_cub *info)
{
	free(tmp);
	free(line);
	exit_prog("Un doublon de couleur ou valeur incorrecte", info);
}
