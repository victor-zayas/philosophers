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
	pthread_mutex_lock(&philo->info->dead);
	if ((ft_time() - philo->info->start_eat) > philo->info->ttd || philo->info->nb == 1)
	{
		philo->info->died = 1;
		pthread_mutex_unlock(&philo->info->dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->dead);
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
	philo->info->start_eat = ft_time();
	ft_usleep(philo->info->tte);
    if (philo->info->must_eat)
    {
        philo->ate++;
        pthread_mutex_lock(&philo->info->status);
        printf("philo %d eaten %d\n", philo->nb, philo->ate);
        pthread_mutex_unlock(&philo->info->status);
    }
	if (philo->ate == philo->info->must_eat)
    {
        philo->info->eaten++;
        pthread_mutex_lock(&philo->info->status);
        printf("PHILO %d END EAT\n", philo->nb);
        pthread_mutex_unlock(&philo->info->status);
    }
	pthread_mutex_unlock(&philo->info->fork[philo->lf]);
	pthread_mutex_unlock(&philo->info->fork[philo->next->lf]);
    if (philo->info->eaten == philo->info->nb)
    {
        pthread_mutex_unlock(&philo->info->fork[philo->lf]);
        pthread_mutex_unlock(&philo->info->fork[philo->next->lf]);
        pthread_mutex_lock(&philo->info->status);
        printf("SALE\n");
        pthread_mutex_unlock(&philo->info->status);
        return (1);
    }
	ft_dead(philo);
	return (0);
}

int	ft_sleep(t_philo *philo)
{
	ft_print_status(philo, "is sleeping...\n");
	ft_usleep(philo->info->tts);
	ft_dead(philo);
	return (0);
}

int	ft_thinking(t_philo *philo)
{
	//ft_dead(philo);
	ft_print_status(philo, "is thinking...\n");
	ft_usleep(philo->info->ttd - (philo->info->tts + philo->info->tte));
	ft_dead(philo);
	return (0);
}
