#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo_data	philo_data;

	if (argc < 5 || argc > 6)
		print_usage_and_exit();
	philo_data = init_data_struct(argc, argv);
	get_philo_data(&philo_data);

	db_print_data();
}