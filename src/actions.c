/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:28:24 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/06/07 22:29:43 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdead(t_philo *philo)
{
	if (philo->info->tte > philo->info->ttd && philo->info->tts > philo->info->ttd)
		philo->info->died = 1;
	return (0);
}

int	ft_iseating(t_philo *philo)
{
	int i = -1;

	if (ft_isdead(philo))
		return (1);
	while (++i < philo->nb)
	{
		if (philo->lf && philo->rf)
			ft_print_status(philo, "is eating...");
		ft_sleep(philo->info->tte);
	}
	return (0);
}
