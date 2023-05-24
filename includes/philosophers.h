/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:27:09 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/05/24 15:11:50 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// INCLUDES

# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>

// STRUCT

typedef struct s_info
{
	int	nb;
	int	ttd;
	int	tte;
	int	tts;
}	t_info;

// PROT

	// UTILS
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

	// INIT
void	ft_get_args(char **argv, t_info *info);

	// MAIN
void	ft_create_threat(t_info *data);

#endif