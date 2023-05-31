/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:22:09 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/05/31 12:44:23 by vzayas-s         ###   ########.fr       */
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

void	ft_usleep(int mls, t_philo *philo)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	while (mls > ft_timediff(t))
	{
		ft_isdead(philo);
		if (philo->info->died)
			return ;
		usleep(100);
	}
}

void	ft_status(t_philo *philo, char *s)
{
	pthread_mutex_lock(&philo->info->status);
	if (!philo->info->died)
		printf("%d Philo %d %s\n", ft_time() - philo->info->time, philo->nb, s);
	pthread_mutex_unlock(&philo->info->status);
}

void	print_args(t_philo *philo)
{
	printf("nb of Philos [%d]\n", philo->info->nb);
	printf("time to eat [%d]\n", philo->info->ttd);
	printf("time to sleep [%d]\n", philo->info->tte);
	printf("time to dead [%d]\n", philo->info->tts);
	printf("ID philo [%d]\n\n", philo->nb);
}
