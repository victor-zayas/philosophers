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

void	ft_dead(t_philo *philo)
{
	if (((ft_time() - philo->info->time) - philo->last_eat) >= philo->info->ttd)
	{
		if (philo->info->running != 0)
		{
			philo->info->died = 1;
			philo->info->running = 0;
            pthread_mutex_lock(&philo->info->status);
            printf("Ms: %ld Philo [%d] died\n", ft_time() - philo->info->time, philo->nb);
            pthread_mutex_unlock(&philo->info->fork[philo->lf]);
            pthread_mutex_unlock(&philo->info->fork[philo->next->lf]);
            pthread_mutex_unlock(&philo->info->status);
		}
	}
}

void	ft_eating(t_philo *philo)
{
    pthread_mutex_lock(&philo->info->fork[philo->lf]);
    ft_print_status(philo, "has taken the left fork...\n");
    pthread_mutex_lock(&philo->info->fork[philo->next->lf]);
    ft_print_status(philo, "has taken the right fork...\n");
    ft_print_status(philo, "is eating...\n");
    philo->last_eat = ft_time() - philo->info->time;
    ft_usleep(philo->info->tte);
    pthread_mutex_unlock(&philo->info->fork[philo->lf]);
    ft_print_status(philo, "has left the left fork...\n");
    pthread_mutex_unlock(&philo->info->fork[philo->next->lf]);
    ft_print_status(philo, "has left the right fork...\n");
    ft_must_eat(philo);
}

void    ft_must_eat(t_philo *philo)
{
    if (philo->info->must_eat)
    {
        philo->ate++;
//        pthread_mutex_lock(&philo->info->status);
//        printf("PHILO %d ATE: %d TIMES\n", philo->nb, philo->ate);
//        pthread_mutex_unlock(&philo->info->status);
    }
    if (philo->ate == philo->info->must_eat && philo->info->must_eat)
    {
        philo->info->eaten++;
//        pthread_mutex_lock(&philo->info->status);
//        printf("PHILO finished: %d\n", philo->info->eaten);
//        pthread_mutex_unlock(&philo->info->status);
    }
    if (philo->info->eaten == philo->info->nb)
        philo->info->running = 0;
}

void	ft_sleep(t_philo *philo)
{
	ft_print_status(philo, "is sleeping...\n");
	ft_usleep(philo->info->tts);
}

void	ft_thinking(t_philo *philo)
{
	ft_print_status(philo, "is thinking...\n");
}
