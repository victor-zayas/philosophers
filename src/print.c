/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:42:32 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/08/30 19:15:58 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * @brief print messages with actual time, ID of philosopher and custom message
 * 
 * @param philo struct point with philosopher info
 * @param s custom message
 * @return int
 */
int	ft_print_status(t_philo *philo, char *s)
{
	if (philo->info->running != 0)
	{
		pthread_mutex_lock(&philo->info->status);
		if (philo->info->running != 0)
			printf("Ms: %ld Philo [%d] %s\n", ft_time() - philo->info->time,
				philo->nb, s);
		pthread_mutex_unlock(&philo->info->status);
	}
	return (0);
}
