/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:41:32 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/08/30 19:14:19 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * @brief get the actual time (now) in miliseconds
 * 
 * @return long actual time in miliseconds
 */
long	ft_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

/**
 * @brief make usleeps until the time given in miliseconds
 * 
 * @param ms time given in miliseconds
 */
void	ft_usleep(unsigned int ms)
{
	long	start_time;

	start_time = ft_time();
	while (ft_time() - start_time < ms)
		usleep(100);
}
