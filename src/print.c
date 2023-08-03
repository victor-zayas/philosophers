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
