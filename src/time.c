/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:41:32 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/06/20 16:25:34 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

static	unsigned int	get_time_diff(struct timeval __time)
{
    struct timeval  	diff;
    unsigned int		time;
    unsigned int		diff_time;

    gettimeofday(&diff, NULL);
    time = (__time.tv_sec * 1000 + __time.tv_usec / 1000);
    diff_time = (diff.tv_sec * 1000 + diff.tv_usec / 1000);
    return (diff_time - time);
}

void	ft_usleep(unsigned int ms)
{
    struct timeval	time;

    gettimeofday(&time, NULL);
    while (ms > get_time_diff(time))
        usleep(50);
}
