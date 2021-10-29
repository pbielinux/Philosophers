#include "philo.h"

void	db_print_data(void)
{
	t_env	*env;
	
	env = get_philo_data(NULL);
	printf(BLU"PROGRAM DATA:\n");
	printf("\tnb_of_philo:\t %d\n"RST, env->nb_of_philo);
}