/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:17:29 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/08/30 19:26:24 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * @brief recreate atoi function in C
 * 
 * @param str string received
 * @return int number received
 */
int	ft_atoi(const char *str)
{
	int	result;
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			break ;
		result = result * 10 + (str[i++] - 48);
	}
	return (result * sign);
}

/**
 * @brief create a new node
 * 
 * @param id number of node
 * @param info struct wit basic info
 * @return t_philo* philosophers node
 */
t_philo	*ft_lstnew(int id, t_info *info)
{
	t_philo	*node;

	node = malloc(sizeof(t_philo));
	if (!node)
		return (NULL);
	node->info = info;
	node->nb = id;
	node->lf = id - 1;
	node->next = NULL;
	return (node);
}

/**
 * @brief add node to last element of list
 * 
 * @param lst head of list
 * @param new node to add
 */
void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*final;

	if (!(*lst))
		*lst = new;
	else
	{
		final = ft_lstlast(*lst);
		final->next = new;
	}
}

/**
 * @brief create a new list
 * 
 * @param philo struct with philosophers info
 * @param info struct with basic info
 */
void	ft_create_list(t_philo **philo, t_info *info)
{
	int		i;

	i = 0;
	while (++i <= info->nb)
	{
		ft_lstadd_back(philo, ft_lstnew(i, info));
	}
	ft_lstlast(*philo)->next = *philo;
}
