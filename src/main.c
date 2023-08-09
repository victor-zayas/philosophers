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

// Nb_of_philo - Time_to_die - Time_to_eat - Time_to_sleep - times_eaten(opt)

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
        ft_usleep(philo->info->tte - 20, philo);
    pthread_create(&check_thread, NULL, ft_check_dead, philo);
    while (philo->info->running != 0)
    {
        ft_eating(philo);
        ft_sleep(philo);
        ft_thinking(philo);
    }
    pthread_join(check_thread, NULL);
    return (NULL);
}

//void	*ft_routine(void *args)
//{
//	t_philo	*philo;
//
//	philo = args;
//	philo->ate = 0;
//	philo->last_eat = 0;
//	if (philo->nb % 2 == 0)
//		ft_usleep(philo->info->tte - 20, philo);
//	while (philo->info->running != 0)
//	{
//		ft_eating(philo);
//        ft_sleep(philo);
//        ft_thinking(philo);
//    }
//    return (0);
//}

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
//        pthread_detach((*philo)->th);
//        *philo = (*philo)->next;
	}
	free (tmp);
}

void ft_print_philos(t_philo *philo)
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

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philo;
	int		i;

	philo = NULL;
	if (ft_check(argc, argv, &info))
		return (1);
	ft_create_list(&philo, &info);
//	ft_print_philos(philo);
	ft_create_threads(&info, &philo);
	i = -1;
	while (++i < info.nb)
		pthread_mutex_destroy(&info.fork[i]);
    pthread_mutex_unlock(&info.status);
	pthread_mutex_destroy(&info.status);
	free(info.fork);
	//system("leaks philosophers");
	return (0);
}
