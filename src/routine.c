/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:04:25 by pbielik           #+#    #+#             */
/*   Updated: 2021/11/08 19:11:14 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_try_eat(t_philo *philo);
static void	ft_do_sleep(t_philo *philo);
static void	ft_do_think(t_philo *philo);
static bool	ft_is_dead(t_philo *philo);

void	*philo_routine(void *philo_void)
{
	t_philo	*philo;

	philo = philo_void;
	while (philo->state != dead
		&& !(philo->state == sleeping && (philo->timings->meals_to_take != UNSET
				&& philo->meals_taken >= philo->timings->meals_to_take)))
	{
		if (ft_is_dead(philo))
			;
		else if (philo->state == thinking)
			ft_try_eat(philo);
		else if (philo->state == eating)
			ft_do_sleep(philo);
		else if (philo->state == sleeping)
			ft_do_think(philo);
	}
	return (philo_void);
}

static bool	ft_is_dead(t_philo *philo)
{
	if (ft_get_time_diff_ms(philo->last_meal, ft_get_timeval())
		>= philo->timings->time_to_die)
	{
		philo->state = dead;
		ft_print_state(philo);
		return (true);
	}
	return (false);
}

static void	ft_try_eat(t_philo *philo)
{
	if (get_forks(philo))
	{
		philo->state = eating;
		philo->meals_taken++;
		ft_print_state(philo);
		philo->last_meal = ft_get_timeval();
		ft_sleep(philo->last_meal, philo->timings->time_to_eat);
	}
}

static void	ft_do_sleep(t_philo *philo)
{
	const long	time_before_starving = philo->timings->time_to_die
		- ft_get_time_diff_ms(philo->last_meal, ft_get_timeval());

	philo->state = sleeping;
	ft_print_state(philo);
	drop_forks(philo);
	if (time_before_starving < philo->timings->time_to_sleep)
		ft_sleep(ft_get_timeval(), time_before_starving);
	else
		ft_sleep(ft_get_timeval(), philo->timings->time_to_sleep);
}

static void	ft_do_think(t_philo *philo)
{
	philo->state = thinking;
	ft_print_state(philo);
	usleep(100);
}
