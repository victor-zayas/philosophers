/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:56:54 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/06/22 11:12:53 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// Nb_of_philo - Time_to_die - Time_to_eat - Time_to_sleep - times_eaten(opt)

static int	ft_subroutine(t_philo *philo)
{
	if (philo->nb % 2 == 0)
	{
		if (ft_sleep(philo))
			return (1);
	}
	if (ft_eating(philo))
		return (1);
	if (ft_sleep(philo))
		return (1);
	if (ft_thinking(philo))
		return (1);
	return (0);
}

void	*ft_routine(void *args)
{
	t_philo	*philo;

	philo = args;
	while (!philo->info->died)
	{
		ft_subroutine(philo);
	}
	return (0);
}

int	ft_create_threads(t_info *info, t_philo **philo)
{
	t_philo	*tmp;
	int		i;

	tmp = *(philo);
	info->time = ft_time();
	while (tmp->next)
	{
		if (pthread_create(&tmp->th, NULL, ft_routine, tmp) != 0)
		{
			perror("pthread_create error");
			return (1);
		}
		tmp = tmp->next;
		if (tmp == *philo)
			break ;
	}
	i = -1;
	while (++i < info->nb)
	{
		if (pthread_join((*philo)->th, NULL) != 0)
		{
			perror("pthread_join error");
			return (1);
		}
		*philo = (*philo)->next;
	}
	free (tmp);
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philo;
	int		i;

	philo = NULL;
	if (ft_check(argc, argv, &info))
		return (1);
	ft_create_list(&philo, &info);
	if (ft_create_threads(&info, &philo))
		return (1);
	i = -1;
	while (++i < info.nb)
		pthread_mutex_destroy(&info.fork[i]);
	pthread_mutex_destroy(&info.dead);
	pthread_mutex_destroy(&info.status);
	free(info.fork);
	//system("leaks philosophers");
	return (0);
}
