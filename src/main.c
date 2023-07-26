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

static int	ft_subroutine(t_philo *philo)
{
	if (ft_eating(philo))
        return (1);
    if (philo->info->eaten == philo->info->nb)
        return (1);
	if (ft_sleep(philo))
        return (1);
	if (ft_thinking(philo))
		return (1);
	return (0);
}

void	*ft_routine(void *args)
{
	t_philo	*philo;

	philo = args;
    philo->ate = 0;
    if (philo->nb % 2 == 0)
        ft_usleep(50);
	while (!philo->info->died)
	{
        ft_dead(philo);
		if (ft_subroutine(philo))
            break ;
    }
	return (0);
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
	//system("leaks philosophers");
	return (0);
}
