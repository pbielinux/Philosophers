/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:04:09 by pbielik           #+#    #+#             */
/*   Updated: 2021/11/08 19:14:51 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	db_get_time_last_meal(t_timeval curr_time, t_timeval last_meal)
{
	return ((curr_time.tv_sec / 1000 + curr_time.tv_usec * 1000)
		- (last_meal.tv_sec / 1000 + last_meal.tv_usec * 1000));
}

static char	*db_get_state(int i)
{
	if (i == eating)
		return (MAG" eating "RST);
	else if (i == thinking)
		return (YEL"thinking"RST);
	else if (i == sleeping)
		return (CYN"sleeping"RST);
	else
		return (RED"--dead--"RST);
}

static char	*db_get_fork(t_fork *fork)
{
	if (fork->is_busy)
		return (RED" lock "RST);
	else
		return (GRN"unlock"RST);
}

void	db_print_philos(void)
{
	t_env		*env;
	t_timeval	curr_time;
	size_t		i;

	curr_time = ft_get_timeval();
	env = get_philo_data(NULL);
	printf("---------------------------------------------------------------\n");
	printf("\t    |   State   |   Meals   |   Lst Meal   |  LFork | RFork |\n");
	i = -1;
	while (++i < env->nb_of_philo)
	{
		printf(" Philo[%d]:\t%s\t%d\t%10ld\t%10s\t%10s\n",
			env->philo_tab[i].id,
			db_get_state(env->philo_tab[i].state),
			env->philo_tab[i].meals_taken,
			db_get_time_last_meal(curr_time, env->philo_tab[i].last_meal),
			db_get_fork(env->philo_tab[i].fork_left),
			db_get_fork(env->philo_tab[i].fork_right)
			);
	}
	printf("---------------------------------------------------------------\n");
}

void	db_print_data(void)
{
	t_env	*env;

	env = get_philo_data(NULL);
	printf(BLU"ENV:\n");
	printf("nb_of_philo:\t %d\n", env->nb_of_philo);
	printf("time_to_eat:\t %ld\n", env->timings.time_to_eat);
	printf("time_to_sleep:\t %ld\n", env->timings.time_to_sleep);
	printf("time_to_die:\t %ld\n", env->timings.time_to_die);
	if (env->timings.meals_to_take >= 0)
		printf("meals_to_take:\t %d\n"RST, env->timings.meals_to_take);
	else
		printf("meals_to_take:\t %s\n\n"RST, "UNSET");
}
