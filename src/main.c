/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:56:54 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/06/06 12:57:43 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// Nb_of_philo - Time_to_die - Time_to_eat - Time_to_sleep - times_eaten(opt)

void	*ft_routine(void *args)
{
	
}

int	ft_create_threads(t_info *info)
{
	t_philo	*philo;
	int		i;

	philo = malloc(sizeof(t_philo) * (info->nb));
	if (!philo)
		return (1);
	info->time = ft_time();
	i = -1;
	while (++i <= info->nb)
	{
		philo[i].info = info;
		philo[i].nb = i + 1;
		philo[i].lf = i + 1;
		philo[i].rf = philo->nb - 1;
		pthread_create(&info->th[i], NULL, ft_routine, &philo[i]);
	}
	while (++i <= info->nb)
		pthread_join(&info->th, NULL);
	free(philo);
	return (0);
}

int	main(int argc, char **argv, t_info *info)
{
	if (ft_check(argc, argv, info))
		return (1);
}
