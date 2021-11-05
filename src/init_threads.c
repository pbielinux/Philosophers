#include "philo.h"

bool	ft_is_dead(t_philo *philo)
{
	if (ft_get_time_diff_ms(philo->last_meal, ft_get_timeval())
		>= philo->timings->time_to_die)
		return (true);
	return (false);
}

void	ft_try_eat(t_philo *philo)
{
	if (get_forks(philo))
	{
		philo->state = eating;
		ft_print_state(philo);
		philo->last_meal = ft_get_timeval();
		ft_sleep(philo->last_meal, philo->timings->time_to_eat);
		philo->meals_taken++;
	}
}

void	ft_do_sleep(t_philo *philo)
{
	philo->state = sleeping;
	ft_print_state(philo);
	drop_forks(philo);
	ft_sleep(ft_get_timeval(), philo->timings->time_to_sleep);
}

void	ft_do_think(t_philo *philo)
{
	philo->state = thinking;
	ft_print_state(philo);
	usleep(1);
}

void	ft_do_dead(t_philo *philo)
{
	philo->state = dead;
	ft_print_state(philo);
}

void	*philo_routine(void *philo_void)
{
	t_philo *philo;
	
	philo = philo_void;
	while (philo->state != dead)
	{
		if (ft_is_dead(philo))
			ft_do_dead(philo);
		else if (philo->state == thinking)
			ft_try_eat(philo);
		else if (philo->state == eating)
			ft_do_sleep(philo);
		else if (philo->state == sleeping)
			ft_do_think(philo);
	}
	return (philo_void);
}

void	init_threads(t_env *env)
{
	size_t i;

	i = -1;
	while (++i < env->nb_of_philo)
	{
		if (pthread_create(&env->philo_threads[i], NULL,
			philo_routine, (void *)&env->philo_tab[i]) != 0)
			exit(EXIT_FAILURE);
	}
}