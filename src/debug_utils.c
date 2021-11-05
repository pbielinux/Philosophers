#include "philo.h"

static long	db_get_time_last_meal(t_timeval start, t_timeval last_meal)
{
	return ((last_meal.tv_sec / 1000 + last_meal.tv_usec * 1000) - (start.tv_sec / 1000 + start.tv_usec * 1000));
}

static char *db_get_state(int i)
{
	if (i == eating)
		return (MAG"eating"RST);
	else if (i == thinking)
		return (YEL"thinking"RST);
	else if (i == sleeping)
		return (CYN"sleeping"RST);
	else
		return (RED"dead"RST);
}

static char *db_get_fork(t_fork *fork)
{
	if (fork->is_busy)
		return (RED"lock"RST);
	else
		return (GRN"unlock"RST);
}

void	db_print_philos(void)
{
	t_env	*env;

	env = get_philo_data(NULL);
	for (int i = 0; i < env->nb_of_philo; i++)
	{
		printf(" Philo[%d]:\t%-s\t%ld\t%10s\t%10s\n",
			env->philo_tab[i].id,
			db_get_state(2),
			db_get_time_last_meal(env->timings.start_time, env->philo_tab[i].last_meal),
			db_get_fork(env->philo_tab[i].fork_left),
			db_get_fork(env->philo_tab[i].fork_right)
			);
	}
}

void	db_print_data(void)
{
	t_env	*env;
	
	env = get_philo_data(NULL);
	printf(BLU"ENV:\n");
	printf("nb_of_philo:\t %d\n", env->nb_of_philo);
	printf("time_to_eat:\t %ld\n", env->timings.time_to_eat);
	printf("time_to_sleep:\t %ld\n", env->timings.time_to_sleep);
	printf("time_to_die:\t %ld\n"RST, env->timings.time_to_die);
//	printf("\t    |  State  |   Lst Meal  |  LFork  |  RFork\n");	
}