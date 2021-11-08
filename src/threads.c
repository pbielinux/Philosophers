/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:04:28 by pbielik           #+#    #+#             */
/*   Updated: 2021/11/08 19:12:06 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_threads(t_env *env)
{
	size_t	i;

	i = -1;
	while (++i < env->nb_of_philo)
	{
		if (pthread_create(&env->philo_threads[i], NULL,
				philo_routine, (void *)&env->philo_tab[i]) != 0)
			exit(EXIT_FAILURE);
	}
}

void	ft_join_threads(t_env *env)
{
	size_t	i;

	i = -1;
	while (++i < env->nb_of_philo)
		if (pthread_join(env->philo_threads[i], NULL) != 0)
			exit (EXIT_FAILURE);
}
