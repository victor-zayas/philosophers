/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:02:40 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/06/21 16:55:30 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static	int	ft_init(t_info *info)
{
	int	i;

	if (!info->nb)
		return (1);
	info->fork = malloc(sizeof(pthread_mutex_t) * info->nb);
	if (!info->fork)
		return (1);
	i = -1;
	while (++i < info->nb)
		pthread_mutex_init(&info->fork[i], NULL);
	pthread_mutex_init(&info->status, NULL);
	info->died = 0;
	info->eaten = 0;
	info->time = 0;
	info->start_eat = 0;
	return (0);
}

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
	if (!argv[5])
		info->must_eat = 0;
	else
	{
		info->must_eat = ft_atoi(argv[5]);
		if (info->must_eat <= 0)
			return (1);
	}
	if (ft_init(info))
		return (1);
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
