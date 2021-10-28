#include "philo.h"

void	db_print_data(void)
{
	t_philo_data	*data;
	
	data = get_philo_data(NULL);
	printf(BLU"PROGRAM DATA:\n");
	printf("\tnb_of_philo:\t %d\n"RST, data->nb_of_philo);
	/* printf("\tt_to_die(ms):\t %d\n", data->time_to_die);
	printf("\tt_to_eat(ms):\t %d\n", data->time_to_eat);
	printf("\tt_to_sleep(ms):\t %d\n", data->time_to_sleep);
	printf("\tnb_of_meals(ms): %d\n"RST, data->nb_meals); */
}