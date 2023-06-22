/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:42:32 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/06/21 17:02:58 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_print_status(t_philo *philo, char *s)
{
	pthread_mutex_lock(&philo->info->status);
	printf("Ms: %ld Philo [%d] %s\n",
		ft_time() - philo->info->time, philo->nb, s);
	pthread_mutex_unlock(&philo->info->status);
	return (0);
}

int	ft_print_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->status);
	printf("PHILO [%d] nb: [%d]\n", philo->nb, philo->nb);
	printf("PHILO [%d] lf: [%d]\n",philo->nb, philo->lf);
	pthread_mutex_unlock(&philo->info->status);
	return (0);
}

int	ft_print_info(t_info *info)
{
	pthread_mutex_lock(&info->status);
	printf("INFO nb: [%d]\n", info->nb);
	printf("INFO ttd: [%d]\n", info->ttd);
	printf("INFO tte: [%d]\n", info->tte);
	printf("INFO tts: [%d]\n", info->tts);
	pthread_mutex_unlock(&info->status);
	return (0);
}
