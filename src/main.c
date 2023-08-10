/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:56:54 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/06/29 12:08:29 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void *ft_check_dead(void *args)
{
    t_philo *philo = args;

    while (philo->info->running != 0)
    {
        ft_dead(philo);
        usleep(100);
    }
    return (NULL);
}

void *ft_routine(void *args)
{
    t_philo *philo = args;
    pthread_t check_thread;

    philo->ate = 0;
    philo->last_eat = 0;
    if (philo->nb % 2 == 0)
        ft_usleep(philo->info->tte - 20);
    pthread_create(&check_thread, NULL, ft_check_dead, philo);
    while (philo->info->running != 0)
    {
        if (philo->info->eaten < philo->info->nb)
            ft_eating(philo);
        ft_sleep(philo);
        ft_thinking(philo);
    }
    pthread_detach(check_thread);
    return (NULL);
}

void	ft_create_threads(t_info *info, t_philo **philo)
{
	t_philo	*tmp;
	int		i;

	tmp = *(philo);
	info->time = ft_time();
	while (tmp->next)
	{
		if (pthread_create(&tmp->th, NULL, ft_routine, tmp))
			return ;
		tmp = tmp->next;
		if (tmp == *philo)
			break ;
	}
	i = -1;
	while (++i < info->nb)
	{
		if (pthread_join((*philo)->th, NULL) != 0)
			return ;
		*philo = (*philo)->next;
	}
	free (tmp);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philo;
	int		i;

	philo = NULL;
	if (ft_check(argc, argv, &info))
		return (1);
	ft_create_list(&philo, &info);
	ft_create_threads(&info, &philo);
	i = -1;
	while (++i < info.nb)
		pthread_mutex_destroy(&info.fork[i]);
	pthread_mutex_destroy(&info.status);
	free(info.fork);
    free_mem(&*philo, &info);
	return (0);
}
