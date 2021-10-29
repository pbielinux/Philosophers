#include "philo.h"

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc < 5 || argc > 6)
		print_usage_and_exit();
	env = init_env_struct(argc, argv);
	get_philo_data(&env);

	db_print_data();
}