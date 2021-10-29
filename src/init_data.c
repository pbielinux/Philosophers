#include "philo.h"

static t_philo		*init_philo(t_env *env);
static t_timings	init_timings(int argc, char **argv);
static t_fork		*init_forks(uint8_t nb_forks);

t_env	init_env_struct(int argc, char **argv)
{
	t_env	env;

	env.nb_of_philo = ft_atoi(argv[1]);
	env.forks = init_forks(env.nb_of_philo);
	env.printer_mutex = init_printer_mutex();
	env.timings = init_timings(argc, argv);
	env.philo_tab = init_philo(&env);
	return (env);
}

static t_fork	*init_forks(uint8_t nb_forks)
{
	size_t	i;
	t_fork	*forks;

	forks = malloc(sizeof(t_fork) * nb_forks);
	omm_guard(forks, __FILE__, __LINE__);
	i = -1;
	while (++i < nb_forks)
	{
		forks[i].mutex = malloc(sizeof(pthread_mutex_t));
		omm_guard(forks[i].mutex, __FILE__, __LINE__);
		if (pthread_mutex_init(forks[i].mutex, NULL) != 0)
			exit(EXIT_FAILURE);
		forks[i].is_busy = false;
	}
	return (forks);
}

static t_timings	init_timings(int argc, char **argv)
{
	t_timings	timing;

	timing.time_to_die = ft_atoi(argv[2]);
	timing.time_to_eat = ft_atoi(argv[3]);
	timing.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		timing.meals_to_take = ft_atoi(argv[5]);
	else
		timing.meals_to_take = UNSET;
	if (gettimeofday(&timing.start_time, NULL) < 0)
		exit(EXIT_FAILURE);
	return (timing);
}

static t_philo	*init_philo(t_env *env)
{
	t_philo	*philo_tab;
	uint8_t	i;

	philo_tab = malloc(sizeof(t_philo) * env->nb_of_philo);
	omm_guard(philo_tab, __FILE__, __LINE__);
	i = -1;
	while (++i < env->nb_of_philo)
	{
		philo_tab[i].id = i + 1;
		philo_tab[i].state = thinking;
		philo_tab[i].meals_taken = 0;
		philo_tab[i].last_meal = env->timings.start_time;
		philo_tab[i].fork_left = &env->forks[previous(i, env->nb_of_philo)];
		philo_tab[i].fork_right = &env->forks[i];
	}
	return (philo_tab);
}