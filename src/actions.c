/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:28:24 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/06/20 18:04:59 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdead(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->dead);
	//printf("TIME DIFF {%ld}\n", (philo->info->start_eat - ft_time()));
	if ((philo->info->start_eat - ft_time()) > philo->info->ttd)
		philo->info->died = 1;
	if (philo->info->died)
		ft_print_status(philo, "c muere ...\n");
	pthread_mutex_unlock(&philo->info->dead);
	return (0);
}

int	ft_iseating(t_philo *philo)
{
	if (ft_isdead(philo))
		return (1);
	if (philo->nb % 2 == 0)
	{
		pthread_mutex_lock(&philo->info->fork[philo->lf]);
		ft_print_status(philo, "has taken the left fork...\n");
		pthread_mutex_lock(&philo->info->fork[philo->next->lf]);
		ft_print_status(philo, "has taken the rigth fork...\n");
	}
	else
	{
		pthread_mutex_lock(&philo->info->fork[philo->lf]);
		ft_print_status(philo, "has taken the left fork...\n");
		pthread_mutex_lock(&philo->info->fork[philo->next->lf]);
		ft_print_status(philo, "has taken the rigth fork...\n");
	}
	ft_print_status(philo, "is eating...\n");
	philo->info->start_eat = ft_time();
	ft_usleep(philo->info->tte);
	pthread_mutex_unlock(&philo->info->fork[philo->lf]);
	pthread_mutex_unlock(&philo->info->fork[philo->next->lf]);
	if (ft_isdead(philo))
		return (1);
	return (0);
}

int	ft_sleep(t_philo *philo)
{
	if (ft_isdead(philo))
		return (1);
	ft_print_status(philo, "is sleeping...\n");
	ft_usleep(philo->info->tts);
	if (ft_isdead(philo))
		return (1);
	return (0);
}

int	ft_isthinking(t_philo *philo)
{
	if (ft_isdead(philo))
		return (1);
	ft_print_status(philo, "is thinking...\n");
	ft_usleep(philo->info->ttd - (philo->info->tts + philo->info->tte));
	if (ft_isdead(philo))
		return (1);
	return (0);
}
