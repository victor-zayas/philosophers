/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:00:59 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/05/31 12:47:25 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_isdead(t_philo *philo)
{
	if (philo->info->died)
		return ;
	pthread_mutex_lock(&philo->info->dead);
	if ((ft_time() - philo->info->time) >= philo->info->ttd)
	{
		ft_status(philo, "died");
		philo->info->died = 1;
		pthread_mutex_unlock(&philo->info->dead);
		return ;
	}
	pthread_mutex_unlock(&philo->info->dead);
}

void	ft_sleep(t_philo *philo)
{
	ft_isdead(philo);
	if (philo->info->died)
		return ;
	ft_status(philo, "is sleeping");
	ft_usleep(philo->info->tts, philo);
	ft_isdead(philo);
	if (philo->info->died)
		return ;
}
