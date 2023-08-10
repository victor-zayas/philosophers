/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:42:32 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/06/29 12:04:15 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_print_status(t_philo *philo, char *s)
{
    ft_dead(philo);
    if (philo->info->running != 0)
    {
        pthread_mutex_lock(&philo->info->status);
        printf("Ms: %ld Philo [%d] %s\n", ft_time() - philo->info->time, philo->nb, s);
        pthread_mutex_unlock(&philo->info->status);
    }
    return (0);
}

void ft_print_philo(t_philo *philo)
{
	while (philo)
	{
        printf("STRUCT\n");
        printf("NB of philos: %d\n", philo->info->nb);
        printf("Time to DIE: %ld\n", philo->info->ttd);
        printf("Time to EAT: %ld\n", philo->info->tte);
        printf("Time to SLEEP: %ld\n", philo->info->tts);
        printf("TIME: %ld\n", philo->info->time);
        printf("PHILO\n");
		printf("PHILO NB = %d\n", philo->nb);
		printf("lf = %d\n", philo->lf);
        printf("PHILO NB = %ld\n", philo->last_eat);
		philo = philo->next;
	}
}