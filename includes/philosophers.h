/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:27:09 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/08/30 19:35:13 by vzayas-s         ###   ########.fr       */
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

/**
 * @brief struct with parameters info
 * 
 */
typedef struct info
{
	int				nb;
	long			ttd;
	long			tte;
	long			tts;
	long			time;
	int				must_eat;
	int				eaten;
	int				died;
	unsigned short	running;
	pthread_mutex_t	status;
	pthread_mutex_t	*fork;
}	t_info;

/**
 * @brief struct with philosophers data
 * 
 */
typedef struct philo
{
	pthread_t		th;
	int				nb;
	int				lf;
	int				ate;
	long			last_eat;
	t_info			*info;
	struct philo	*next;
}	t_philo;

// PROTOTYPE

	//UTILS
int		ft_isdigit(int c);
t_philo	*ft_lstlast(t_philo *lst);
void	free_mem(t_philo *head, t_info *info);

	//CREATE_LIST
int		ft_atoi(const char *str);
t_philo	*ft_lstnew(int id, t_info *info);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
void	ft_create_list(t_philo **philo, t_info *info);

	//INIT_ARGS
int		ft_check(int argc, char **argv, t_info *info);

	//PRINT
int		ft_print_status(t_philo *philo, char *s);
void	ft_print_philo(t_philo *philo);

	//TIME
long	ft_time(void);
void	ft_usleep(unsigned int ms);

	//ACTIONS
void	ft_dead(t_philo *philo);
void	ft_eating(t_philo *philo);
void	ft_must_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_thinking(t_philo *philo);

	//MAIN
void	ft_create_threads(t_info *info, t_philo **philo);
void	*ft_routine(void *args);

#endif
