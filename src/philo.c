/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:15:44 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/05/23 11:59:22 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*create_philo(int __unused nb_ph)
{
	int	i = 0;

	while (++i <= 100)
		//printf("Philosopher [%d]\n", i);
		write(1, "hola\n", 5);
	return (0);
}

void	*create_fork(int __unused nb_fk)
{
	int	i = 0;
	
	//printf("%d", nb_fk);
	while (++i <= 100)
		write(1, "hola2\n", 6);
		//printf("Tenedor [%d]\n", i);
	return (0);
}

int	main(int argc, char **argv)
{
	pthread_t	p1;
	//pthread_t	p2;
	int			i;
	int			nb_ph;
	int			nb_fk;

	(void)argv;
	i = 0;
	nb_ph = ft_atoi(argv[1]);
	nb_fk = ft_atoi(argv[1]);
	if (argc == 4)
	{	
		pthread_create(&p1, NULL, create_philo(nb_ph), NULL);
		//pthread_join(p1, NULL);
		printf("acaba el hilo\n");
		//pthread_create(&p2, NULL, create_fork(nb_fk), NULL);
		//pthread_join(p2, NULL);
	}
	else if (argc == 5)
	{
		printf("No esta hecho, te esperas crack <( •̀ᴖ•́)>\n");
	}
	else
		printf("Unexpected error in your brain (; ￢＿￢)\n");
	//exit(0);
}

// number_of_philosophers | time_to_die | time_to_eat time_to_sleep