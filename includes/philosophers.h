/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:27:09 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/06/06 13:04:04 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// INCLUDES

# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

// STRUCT

typedef struct s_info
{
	int				nb;
	int				ttd;
	int				tte;
	int				tts;
	int				time;
	int				must_eat;
	int				eaten;
	int				died;
	pthread_t		*th;
	pthread_mutex_t	status;
	pthread_mutex_t	*fork;
	pthread_mutex_t	dead;

}	t_info;

typedef struct philo
{
	int		nb;
	int		lf;
	int		rf;
	t_info	*info;
}	t_philo;


// PROT
	//INIT_ARGS
int	ft_check(int argc, char **argv, t_info *info);

	//PRINT
int	ft_print_status(t_philo *philo, char *s);

	//TIME
int	ft_time(void);

#endif