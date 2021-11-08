/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:04:12 by pbielik           #+#    #+#             */
/*   Updated: 2021/11/08 19:04:13 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	drop_forks(t_philo *philo)
{
	t_fork	*left;
	t_fork	*right;

	left = philo->fork_left;
	right = philo->fork_right;
	pthread_mutex_unlock(left->mutex);
	left->is_busy = false;
	pthread_mutex_unlock(right->mutex);
	right->is_busy = false;
}

bool	get_forks(t_philo *philo)
{
	t_fork	*left;
	t_fork	*right;

	left = philo->fork_left;
	right = philo->fork_right;
	if (left->is_busy == false)
	{
		pthread_mutex_lock(left->mutex);
		left->is_busy = true;
		if (right->is_busy == false)
		{
			pthread_mutex_lock(right->mutex);
			right->is_busy = true;
			philo->state = forks_taken;
			ft_print_state(philo);
			ft_print_state(philo);
			return (true);
		}
		else
		{
			pthread_mutex_unlock(left->mutex);
			left->is_busy = false;
		}
	}
	return (false);
}

t_fork	*init_forks(int nb_forks)
{
	size_t	i;
	t_fork	*forks;

	forks = malloc(sizeof(t_fork) * nb_forks);
	omm_guard(forks, __FILE__, __LINE__);
	i = -1;
	while (++i < (size_t)nb_forks)
	{
		forks[i].mutex = malloc(sizeof(pthread_mutex_t));
		omm_guard(forks[i].mutex, __FILE__, __LINE__);
		if (pthread_mutex_init(forks[i].mutex, NULL) != 0)
			exit(EXIT_FAILURE);
		forks[i].is_busy = false;
	}
	return (forks);
}
