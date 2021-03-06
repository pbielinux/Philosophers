/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:04:15 by pbielik           #+#    #+#             */
/*   Updated: 2021/11/08 19:26:23 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo		*init_philo(t_env *env);
static t_timings	init_timings(int argc, char **argv);

t_env	init_env_struct(int argc, char **argv)
{
	t_env	env;

	env.nb_of_philo = ft_atoi(argv[1]);
	env.forks = init_forks(env.nb_of_philo);
	env.printer_mutex = init_printer_mutex();
	env.timings = init_timings(argc, argv);
	env.philo_tab = init_philo(&env);
	env.philo_threads = malloc(sizeof(pthread_t) * env.nb_of_philo);
	omm_guard(env.philo_threads, __FILE__, __LINE__);
	return (env);
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
	timing.start_time = ft_get_timeval();
	return (timing);
}

static t_philo	*init_philo(t_env *env)
{
	t_philo	*philo_tab;
	int		i;

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
		philo_tab[i].printer_mutex = env->printer_mutex;
		philo_tab[i].timings = &env->timings;
	}
	return (philo_tab);
}
