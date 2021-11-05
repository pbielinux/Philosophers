#include "philo.h"

int	main(int argc, char **argv)
{
	t_env	env;
	size_t	i;

	if (argc < 5 || argc > 6)
		print_usage_and_exit();
	env = init_env_struct(argc, argv);
	get_philo_data(&env);
	init_threads(&env);
	i = 0;
	while (i < env.nb_of_philo)
	{
		if (pthread_join(env.philo_threads[i], NULL) != 0)
			exit (EXIT_FAILURE);
		i++;
	}
}