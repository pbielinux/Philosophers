#include "philo.h"

t_philo_data	init_data_struct(int argc, char **argv)
{
	t_philo_data	data;
	t_timings		timings;

	data.nb_of_philo = ft_atoi(argv[1]);
	data.forks = init_forks(data.nb_of_philo);
	data.printer_mutex = init_printer_mutex();
	timings = init_timings(argc, argv);
	return (data);
}

t_fork	*init_forks(uint8_t nb_forks)
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

t_timings	init_timings(int argc, char **argv)
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