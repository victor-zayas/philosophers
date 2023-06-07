/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:56:54 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/06/07 22:39:34 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// Nb_of_philo - Time_to_die - Time_to_eat - Time_to_sleep - times_eaten(opt)

void	*ft_routine(void *args)
{
	t_philo	*philo;

	philo = args;
	if (philo->nb % 2 == 1)
		ft_sleep(philo->info->tte);
	ft_isdead(philo);
	if (philo->info->died)
		return (NULL);
	ft_print_status(philo, "is thinking...\n");
	ft_isdead(philo);
	return (0);
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
	while (++i < info->nb)
	{
		philo[i].info = info;
		philo[i].nb = i + 1;
		philo[i].lf = i + 1;
		philo[i].rf = info->nb - 1;
		pthread_create(&info->th[i], NULL, ft_routine, &philo[i]);
	}
	i = -1;
	while (++i < info->nb)
		pthread_join(info->th[i], NULL);
	free(info->th);
	free(philo);
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	info;
	int		i;

	i = 0;
	if (ft_check(argc, argv, &info))
		return (1);
	if (ft_create_threads(&info))
		return (1);
	while (i < info.nb)
	{
		pthread_mutex_destroy(&info.fork[i]);
		i++;
	}
	pthread_mutex_destroy(&info.dead);
	pthread_mutex_destroy(&info.status);
	free(info.fork);
	free(info.th);
	//system("leaks philosophers");
	return (0);
}
