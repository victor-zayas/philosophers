/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:22:09 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/05/30 13:44:04 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_timediff(struct timeval time)
{
	struct timeval	diff;

	gettimeofday(&diff, NULL);
	return (((diff.tv_sec * 1000) + (diff.tv_usec / 1000))
		- ((time.tv_sec * 1000) + (time.tv_usec / 1000)));
}

void	ft_status(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->info->status);
	printf("%d Philo %d %s\n", ft_time() - philo->info->time, philo->nb, str);
	pthread_mutex_unlock(&philo->info->status);
}
