/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:15:44 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/05/31 12:22:04 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *args)
{
	t_philo	*philo;

	philo = args;
	philo->info->eaten = 0;
	philo->info->time = ft_time();
	print_args(philo);
	return (0);
}

int	ft_create_thread(t_info *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->nb);
	if (!philo)
		return (1);
	data->time = ft_time();
	while (++i <= data->nb)
	{
		philo[i].nb = i;
		philo[i].lf = i;
		philo[i].rf = (i + 1) % data->nb;
		philo[i].info = data;
		pthread_create(&data->th[i], NULL, &ft_routine, &philo[i]);
	}
	while (++i <= data->nb)
		pthread_join(data->th[i], NULL);
	free(philo);
	return (0);
}

// number_of_philosophers | time_to_die | time_to_eat | time_to_sleep || must eat
int	main(int argc, char **argv)
{
	t_info	info;

	if (ft_check(argc, argv, &info))
		return (1);
	if (ft_create_thread(&info))
		return (1);
	//system("leaks philosophers");
	return (0);
}
