#ifndef FORKS_H
# define FORKS_H

# include "types.h"

t_fork	*init_forks(int nb_forks);

bool	get_forks(t_philo *philo);

void	drop_forks(t_philo *philo);

#endif // !FORKS_H