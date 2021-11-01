#include "philo.h"

void	db_print_data(void)
{
	t_env	*env;
	
	env = get_philo_data(NULL);
	printf(BLU"ENV:\n");
	printf("\tnb_of_philo:\t %d\n", env->nb_of_philo);
	printf("\ttime_to_eat:\t %ld\n", env->timings.time_to_eat);
	printf("\ttime_to_sleep:\t %ld\n", env->timings.time_to_sleep);
	printf("\ttime_to_die:\t %ld\n"RST, env->timings.time_to_die);
	for (int i = 1; i < env->nb_of_philo; i++)
	{
		printf("\t\tPhilo[%d]:\t%d\n", env->philo_tab[i].id, env->philo_tab[i].state);
	}
}