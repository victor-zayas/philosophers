/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:39:36 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/08/16 12:43:57 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

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
}
