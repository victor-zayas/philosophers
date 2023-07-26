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
    {
        pthread_mutex_lock(&philo->info->status);
        printf("SE ACABA DE COMER\n");
        pthread_mutex_unlock(&philo->info->status);
        return (1);
    }
    pthread_mutex_lock(&philo->info->status);
    printf("valor de running: %d\n", philo->info->running);
    pthread_mutex_unlock(&philo->info->status);
    if (philo->info->running == 0)
    {
        pthread_mutex_lock(&philo->info->status);
        printf("SE PARA EL PROGRAMA\n");
        pthread_mutex_unlock(&philo->info->status);
        return (1);
    }
	if (ft_sleep(philo))
        return (1);
	if (ft_thinking(philo))
		return (1);
	return (0);
}

static int check_running(t_philo	*philo)
{
    int b;
    pthread_mutex_lock(&philo->info->status);
    b = philo->info->running;
    pthread_mutex_unlock(&philo->info->status);
    return (b);

}

void	*ft_routine(void *args)
{
	t_philo	*philo;

	philo = args;
    philo->ate = 0;
    if (philo->nb % 2 == 0)
        ft_usleep(50);
	while (check_running(philo))
	{
        ft_dead(philo);
		if (ft_subroutine(philo))
            break ;
    }
    printf("Philo [%d] ha terminado su rutina\n", philo->nb); // Agregamos este mensaje de depuración
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
    printf("Todos los hilos han terminado\n"); // Agregamos este mensaje de depuración
	i = -1;
	while (++i < info.nb)
		pthread_mutex_destroy(&info.fork[i]);
    pthread_mutex_unlock(&info.status);
	pthread_mutex_destroy(&info.status);
	free(info.fork);
	//system("leaks philosophers");
	return (0);
}
