#include "philo.h"

long long	ft_get_time_diff_ms(t_timeval start, t_timeval end)
{
	// printf(MAG"Start time: %ld\n"RST, start.tv_sec * 1000 + start.tv_usec / 1000);
	// printf(CYN"End time: %ld\n"RST, end.tv_sec * 1000 + end.tv_usec / 1000);
	return ((end.tv_sec * 1000 + end.tv_usec / 1000)
			- (start.tv_sec * 1000 + start.tv_usec / 1000));
	/* return (((end.tv_sec - start.tv_sec) * 1000)
		+ ((end.tv_usec - start.tv_usec) / 1000)); */
}

void	ft_sleep(t_timeval start_time, int time_to_sleep_ms)
{
	while (ft_get_time_diff_ms(start_time, ft_get_timeval())
		<= time_to_sleep_ms)
		usleep(1000);
}

t_timeval	ft_get_timeval(void)
{
	t_timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		exit(EXIT_FAILURE);
	return (time);
}