/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:42:32 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/06/06 11:54:00 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_print_status(t_philo *philo, char *s)
{
	pthread_mutex_lock(&philo->info->status);
	if (philo->info->died == 1)
	{
		printf("c murio\n");
		exit (1);
	}
	else
	{
		printf("%d Philo %d %s\n", ft_time() - philo->info->time, philo->nb, s);
	}
	pthread_mutex_unlock(&philo->info->status);
}
