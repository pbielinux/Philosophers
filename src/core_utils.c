/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:04:01 by pbielik           #+#    #+#             */
/*   Updated: 2021/11/08 19:43:33 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	previous(int i, int size)
{
	if (i == 0)
		return (size - 1);
	return (i - 1);
}

t_env	*get_philo_data(t_env *data)
{
	static t_env	*static_data = NULL;

	if (!static_data && data)
		static_data = data;
	return (static_data);
}

void	print_usage_and_exit(void)
{
	printf(HRED"Wrong arguments!\n"RST \
		"  Try to run the program with the folowing args:\n"\
		BGRN"  ./pilosophers "YEL"[nb_of_philo] [t_to_die] [t_to_eat] "\
		"[t_to_sleep] "RST"[nb_of_meals]\n");
	exit(EXIT_FAILURE);
}

void	ft_exit_and_free(void)
{
	t_env	*env;
	size_t	i;

	env = get_philo_data(NULL);
	i = -1;
	free(env->philo_threads);
	free(env->philo_tab);
	while (++i < env->nb_of_philo)
		free (env->forks[i].mutex);
	free(env->forks);
	free(env->printer_mutex);
	exit(EXIT_SUCCESS);
}

void	ft_exit_error(error_code error)
{
	if (error == THREAD_CREATION)
		printf(RED"Failed to create thread!"RST);
	else if (error == MUTEX_CREATION)
		printf(RED"Failed to create mutex!"RST);
	else if (error == THREAD_JOIN)
		printf(RED"Failed at thread join!"RST);
	else if (error == GET_TIME)
		printf(RED"Failed to get current time!"RST);
	exit(EXIT_FAILURE);
}