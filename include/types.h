/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:56:37 by pbielik           #+#    #+#             */
/*   Updated: 2021/11/08 19:59:06 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define UNSET -1

typedef enum e_error_code
{
	THREAD_CREATION,
	MUTEX_CREATION,
	THREAD_JOIN,
	GET_TIME
}	t_error_code;

typedef enum e_philo_state
{
	forks_taken,
	eating,
	sleeping,
	thinking,
	dead
}	t_philo_state;

typedef struct timeval	t_timeval;
typedef struct s_timings
{
	t_timeval	start_time;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	int			meals_to_take;
}	t_timings;

typedef struct s_fork
{
	bool			is_busy;
	pthread_mutex_t	*mutex;
}	t_fork;

typedef struct s_philo
{
	int				id;
	t_philo_state	state;
	int				meals_taken;
	t_timeval		last_meal;
	t_fork			*fork_left;
	t_fork			*fork_right;
	pthread_mutex_t	*printer_mutex;
	t_timings		*timings;
}	t_philo;

typedef struct s_environment
{
	uint8_t			nb_of_philo;
	t_timings		timings;
	t_philo			*philo_tab;
	pthread_t		*philo_threads;
	t_fork			*forks;
	pthread_mutex_t	*printer_mutex;
}	t_env;

#endif // !TYPES_H