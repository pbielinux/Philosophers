#ifndef TYPES_H
# define TYPES_H

# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define UNSET -1

typedef enum e_philo_state
{
	dead,
	thinking,
	eating,
	sleeping
}	t_philo_state;

typedef struct timeval t_timeval;
typedef struct s_timings
{
	t_timeval	start_time;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	int16_t		meals_to_take;
}	t_timings;

typedef struct s_fork
{
	bool			is_busy;
	pthread_mutex_t	*mutex;
}	t_fork;

typedef struct s_philo
{
	uint8_t			id;
	t_philo_state	state;
	uint16_t		meals_taken;
	t_fork			*fork_left;
	t_fork			*fork_right;
}	t_philo;

typedef struct s_philo_data
{
	uint8_t			nb_of_philo;
	t_philo			*philo;
	pthread_t		*philo_threads;
	t_fork			*forks;
	pthread_mutex_t	*printer_mutex;
}	t_philo_data;

#endif // !TYPES_H