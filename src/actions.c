/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:28:24 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/06/29 12:08:43 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_dead(t_philo *philo)
{
	if ((ft_time() - philo->info->start_eat) >= philo->info->ttd)
	{
        pthread_mutex_lock(&philo->info->status);
        philo->info->died = 1;
        philo->info->running = 0;
        printf("Ms: %d Philo [%d] died\n", ft_time() - philo->info->time, philo->nb);
        pthread_mutex_unlock(&philo->info->status);
        return (1);
	}
	return (0);
}

int	ft_eating(t_philo *philo)
{
	if (philo->info->nb == 1)
	{
		pthread_mutex_lock(&philo->info->fork[philo->lf]);
		if (ft_print_status(philo, "has taken the left fork...\n"))
		{
			pthread_mutex_unlock(&philo->info->fork[philo->lf]);
			return (1);
		}
	}
	else
	{
		pthread_mutex_lock(&philo->info->fork[philo->lf]);
		if (ft_print_status(philo, "has taken the left fork...\n"))
		{
			pthread_mutex_unlock(&philo->info->fork[philo->lf]);
			return (1);
		}
		pthread_mutex_lock(&philo->info->fork[philo->next->lf]);
		if (ft_print_status(philo, "has taken the right fork...\n"))
		{
			pthread_mutex_unlock(&philo->info->fork[philo->next->lf]);
			return (1);
		}
		if (ft_print_status(philo, "is eating...\n"))
			return (1);
	}
    pthread_mutex_unlock(&philo->info->fork[philo->lf]);
    pthread_mutex_unlock(&philo->info->fork[philo->next->lf]);
	philo->info->start_eat = ft_time();
	ft_usleep(philo->info->tte);
    ft_dead(philo);
    if (philo->info->must_eat)
    {
        pthread_mutex_lock(&philo->info->status);
        philo->ate++;
        pthread_mutex_unlock(&philo->info->status);
    }
    if (philo->ate == philo->info->must_eat && philo->info->must_eat)
    {
        pthread_mutex_lock(&philo->info->status);
        philo->info->eaten++;
        pthread_mutex_unlock(&philo->info->status);
    }
    if (philo->info->eaten == philo->info->nb)
        return (1);
	return (0);
}

int	ft_sleep(t_philo *philo)
{
	ft_print_status(philo, "is sleeping...\n");
	ft_usleep(philo->info->tts);
	return (0);
}

int	ft_thinking(t_philo *philo)
{
	ft_print_status(philo, "is thinking...\n");
	ft_usleep(philo->info->ttd - (philo->info->tts + philo->info->tte));
	return (0);
}
