/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:28:24 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/06/22 16:07:27 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->dead);
	if ((ft_time() - philo->info->start_eat) > philo->info->ttd
		|| philo->info->nb == 1)
	{
		philo->info->died = 1;
		return (1);
	}
	pthread_mutex_unlock(&philo->info->dead);
	return (0);
}

int	ft_eating(t_philo *philo)
{
	ft_dead(philo);
	if (philo->info->nb == 1)
	{
		pthread_mutex_lock(&philo->info->fork[philo->lf]);
		if (ft_print_status(philo, "has taken the left fork...\n"))
			return (1);
	}
	else
	{
		pthread_mutex_lock(&philo->info->fork[philo->lf]);
		if (ft_print_status(philo, "has taken the left fork...\n"))
			return (1);
		pthread_mutex_lock(&philo->info->fork[philo->next->lf]);
		if (ft_print_status(philo, "has taken the right fork...\n"))
			return (1);
		if (ft_print_status(philo, "is eating...\n"))
			return (1);
	}
	philo->info->start_eat = ft_time();
	ft_usleep(philo->info->tte);
    philo->info->eaten += 1;
    printf("COMIDO REALIZADO %d\n", philo->info->eaten);
    printf("COMIDO TOTAL %d\n", philo->info->must_eat);
    if (philo->info->eaten == philo->info->must_eat)
        return (1);
    pthread_mutex_unlock(&philo->info->fork[philo->lf]);
    pthread_mutex_unlock(&philo->info->fork[philo->next->lf]);
	ft_dead(philo);
	return (0);
}

int	ft_sleep(t_philo *philo)
{
	ft_dead(philo);
	ft_print_status(philo, "is sleeping...\n");
	ft_usleep(philo->info->tts);
	ft_dead(philo);
	return (0);
}

int	ft_thinking(t_philo *philo)
{
	ft_dead(philo);
	ft_print_status(philo, "is thinking...\n");
	ft_usleep(philo->info->ttd - (philo->info->tts + philo->info->tte));
	ft_dead(philo);
	return (0);
}
