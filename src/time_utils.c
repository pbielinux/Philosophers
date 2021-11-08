/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:04:31 by pbielik           #+#    #+#             */
/*   Updated: 2021/11/08 19:05:00 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_get_time_diff_ms(t_timeval start, t_timeval end)
{
	return ((end.tv_sec * 1000 + end.tv_usec / 1000)
		- (start.tv_sec * 1000 + start.tv_usec / 1000));
}

void	ft_sleep(t_timeval start_time, int time_to_sleep_ms)
{
	while (ft_get_time_diff_ms(start_time, ft_get_timeval())
		<= time_to_sleep_ms)
		usleep(10);
}

t_timeval	ft_get_timeval(void)
{
	t_timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		exit(EXIT_FAILURE);
	return (time);
}
