/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:09:51 by rchmouk           #+#    #+#             */
/*   Updated: 2023/07/30 18:02:08 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "header.h"

void	ft_error_exit(char *str)
{
	printf("%s", str);
	exit(1);
}

int	check_character(char c)
{
	static int	x;

	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (x == 1)
			ft_error_exit("\033[0;31mERROR :invalid map6.5!\n");
		else
		{
			x = 1;
			return (0);
		}
	}
	if (c == '1' || c == '0' || c == ' ' || c == '\t')
		return (0);
	return (1);
}

int	p(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (0);
	return (1);
}

void	valid_player(char **map, int i, int j)
{
	if (map[i - 1][j] != '1' && map[i - 1][j] != '0')
		ft_error_exit("\033[0;31mERROR :invalid map 144!\n");
	if (map[i + 1][j] != '1' && map[i + 1][j] != '0')
		ft_error_exit("\033[0;31mERROR :invalid map 144!\n");
	if (map[i][j - 1] != '1' && map[i][j - 1] != '0')
		ft_error_exit("\033[0;31mERROR :invalid map 144!\n");
	if (map[i][j + 1] != '1' && map[i][j + 1] != '0')
		ft_error_exit("\033[0;31mERROR :invalid map 144!\n");
}

void	check_all_sides(char **map, int len, int *tab)
{
	int	i;
	int	j;
	int	x;

	i = -1;
	x = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			check_all_nor2(&x, i, j, map);
			if (map[i][j] == ' ' || map[i][j] == '\t')
			{
				check_all_nor(i, j, map, tab);
				if (i < len - 1 && j < tab[i + 1] && map[i + 1][j] != '1'
					&& map[i + 1][j] != ' ')
					ft_error_exit("\033[0;31mERROR :invalid map10!\n");
			}
			if (p(map[i][j]) == 0)
				valid_player(map, i, j);
		}
	}
	if (x != 1)
		ft_error_exit("\033[0;31mERROR :invalid map!\n");
}
