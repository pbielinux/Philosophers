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