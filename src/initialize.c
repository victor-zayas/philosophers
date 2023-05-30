/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:23:04 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/05/30 16:26:23 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_args(t_info *info)
{
	printf("[%d]\n", info->nb);
	printf("[%d]\n", info->ttd);
	printf("[%d]\n", info->tte);
	printf("[%d]\n", info->tts);
}

/* static int	ft_init(t_info *info)
{
	//reservar memoria para hilo
	//reservar memoria para fork
} */

static int	ft_get_args(char **argv, t_info *info)
{
	info->nb = ft_atoi(argv[1]);
	if (info->nb <= 0)
		return (1);
	info->ttd = ft_atoi(argv[2]);
	if (info->ttd <= 0)
		return (1);
	info->tte = ft_atoi(argv[3]);
	if (info->tte <= 0)
		return (1);
	info->tts = ft_atoi(argv[4]);
	if (info->tts <= 0)
		return (1);
	//if (ft_init(info))
	//	return (1);
	print_args(info);
	return (0);
}

int	ft_check(int argc, char **argv, t_info *info)
{
	if (argc < 5)
	{
		return (1);
		printf("there are not enough arguments\n");
	}
	if (argc > 6)
	{
		return (1);
		printf("there are too many arguments\n");
	}
	if (ft_get_args(argv, info))
		return (1);
	return (0);
}
