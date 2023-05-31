/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:27:09 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/05/31 12:51:23 by vzayas-s         ###   ########.fr       */
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
	int				died;
	int				must_eat;
	int				eaten;
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
	//ACTIONS
void	ft_isdead(t_philo *philo);
void	ft_sleep(t_philo *philo);

	// LIB
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

	// INIT
int		ft_check(int argc, char **argv, t_info *info);

	//UTILS
int		ft_time(void);
void	ft_usleep(int mls, t_philo *philo);
void	ft_status(t_philo *philo, char *str);
void	print_args(t_philo *philo);

#endif