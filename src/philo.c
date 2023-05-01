/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:15:44 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/05/01 20:49:50 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine()
{
	int	i = 0;

	while (i++ <= 100)
		printf("Philosopher [%d]\n", i);
	return (0);
}

void	*no_rutine()
{
	int	i = 0;

	while (i++ <= 100)
		printf("NO RUTINE\n");
	return (0);
}

int	main(int argc, char **argv)
{
	pthread_t	p1;
	pthread_t	p2;
	int			i;

	i = 0;
	if (argc == 4)
	{	
		(void)argv;
		//if (ft_isdigit(argv[i]) == 1)
		pthread_create(&p1, NULL, &routine, NULL);
		pthread_join(p1, NULL);
		pthread_create(&p2, NULL, &no_rutine, NULL);
		pthread_join(p2, NULL);
	}
	else if (argc == 5)
	{
		printf("No esta hecho, te esperas crack <( •̀ᴖ•́)>\n");
	}
	else
		printf("Unexpected error in your brain (; ￢＿￢)\n");
}

// number_of_philosophers | time_to_die | time_to_eat time_to_sleep