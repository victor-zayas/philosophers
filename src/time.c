/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:41:32 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/06/06 13:04:11 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

static int	ft_timediff(struct timeval time)
{
	struct timeval	diff;

	gettimeofday(&diff, NULL);
	return (((diff.tv_sec * 1000) + (diff.tv_usec / 1000))
		- ((time.tv_sec * 1000) + (time.tv_usec / 1000)));
}
