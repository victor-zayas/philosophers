/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:39:36 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/08/30 19:11:11 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * @brief checks if the parameter received is a number
 * 
 * @param c the number received
 * @return int return 1 if a number, return 0 if not
 */
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * @brief get the last element in linked list
 * 
 * @param lst list received
 * @return t_philo* the las element of list
 */
t_philo	*ft_lstlast(t_philo *lst)
{
	while (lst->next)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

/**
 * @brief free struct pointer
 * 
 * @param philo struct pointer received
 * @param info struct pointer received
 */
void	free_mem(t_philo *philo, t_info *info)
{
	t_philo	*aux;

	while (info->nb)
	{
		aux = philo;
		philo = philo->next;
		free(aux);
		info->nb--;
	}
	free(info->fork);
}
