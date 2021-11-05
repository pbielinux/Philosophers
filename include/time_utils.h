#ifndef TIME_UTILS_H
# define TIME_UTILS_H

# include "types.h"

long long	ft_get_time_diff_ms(t_timeval start, t_timeval end);

t_timeval	ft_get_timeval(void);

void	ft_sleep(t_timeval start_time, int time_to_sleep_ms);

#endif // !TIME_UTILS_H
