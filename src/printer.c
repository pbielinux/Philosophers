/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:04:23 by pbielik           #+#    #+#             */
/*   Updated: 2021/11/08 19:29:41 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*get_state_str(e_philo_state state)
{
	if (state == forks_taken)
		return (BLU"has taken forks");
	else if (state == eating)
		return (MAG"is eating");
	else if (state == sleeping)
		return (CYN"is sleeping");
	else if (state == thinking)
		return (YEL"is thinking");
	else
		return (RED"died");
}

void	ft_print_state(t_philo *philo)
{
	t_timeval	time;
	static bool	a_philo_died = false;

	time = ft_get_timeval();
	pthread_mutex_lock(philo->printer_mutex);
	if (a_philo_died == false)
		printf("%lld %d %s\n"RST,
			ft_get_time_diff_ms(philo->timings->start_time, time),
			philo->id,
			get_state_str(philo->state));
	if (philo->state == dead)
		a_philo_died = true;
	if (a_philo_died)
		philo->state = dead;
	pthread_mutex_unlock(philo->printer_mutex);
}

pthread_mutex_t	*init_printer_mutex(void)
{
	pthread_mutex_t	*printer_mutex;

	printer_mutex = malloc(sizeof(pthread_mutex_t));
	omm_guard(printer_mutex, __FILE__, __LINE__);
	if (pthread_mutex_init(printer_mutex, NULL) != 0)
		ft_exit_error(MUTEX_CREATION);
	return (printer_mutex);
}
