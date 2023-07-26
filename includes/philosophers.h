/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:27:09 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/06/21 12:51:15 by vzayas-s         ###   ########.fr       */
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

typedef struct info
{
	int				nb;
	int				ttd;
	int				tte;
	int				tts;
	int 			time;
	int 			start_eat;
	int				must_eat;
	int				eaten;
	int				died;
    unsigned short  running;
	pthread_mutex_t	status;
	pthread_mutex_t	*fork;
}	t_info;

typedef struct philo
{
	pthread_t		th;
	int				nb;
	int				lf;
    int             ate;
	t_info			*info;
	struct philo	*next;
}	t_philo;


// PROTOTIPE
	//LIB
int		ft_atoi(const char *str);
t_philo *ft_lstnew(int id, t_info *info);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
void	ft_create_list(t_philo **philo, t_info *info);

	//LIB_UTILS
int		ft_isdigit(int c);
t_philo	*ft_lstlast(t_philo *lst);

	//INIT_ARGS
int		ft_check(int argc, char **argv, t_info *info);

	//PRINT
int		ft_print_status(t_philo *philo, char *s);

	//TIME
int		ft_time(void);
void	ft_usleep(unsigned int ms);

	//ACTIONS
int		ft_dead(t_philo *philo);
int		ft_eating(t_philo *philo);
int		ft_sleep(t_philo *philo);
int		ft_thinking(t_philo *philo);

	//MAIN
void	ft_create_threads(t_info *info, t_philo **philo);
void	*ft_routine(void *args);

#endif
