/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:15:44 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/05/25 12:55:56 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *arg)
{
	(void)arg;
	printf("a\n");
	return (0);
}

void	*ft_routine2(void *arg)
{
	(void)arg;
	printf("b\n");
	return (0);
}

void	ft_create_threat(t_info *data)
{
	pthread_t	p1;
	//pthread_t	p2;
	int			i = 0;

	(void)data;
	while (++i <= data->nb)
	{
		pthread_create(&p1, NULL, &ft_routine, (void *)&data->nb);
		pthread_join(p1, NULL);
		//printf("\nFin philosophers\n\n");
		//pthread_create(&p2, NULL, &ft_routine2, (void *)&data->nb);
		//pthread_join(p2, NULL);
		//printf("\nFin Tresnedores\n\n");
	}
}

// number_of_philosophers | time_to_die | time_to_eat | time_to_sleep
int	main(int argc, char **argv)
{
	t_info	info;
	int		i;

	i = 0;
	if (argc == 5)
	{
		ft_get_args(argv, &info);
		ft_create_threat(&info);
	}
	else if (argc == 6)
	{
		//en caso de que haya el parametro opcional de veces comidas;
		printf("No esta hecho, te esperas crack <( •̀ᴖ•́)>\n");
	}
	else
	{
		//caso de error argumentos invalidos;
		printf("Unexpected error (; ￢＿￢)\n");
	}
	exit(0);
}
