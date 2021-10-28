#ifndef INIT_DATA_H
# define INIT_DATA_H

#include "types.h"

t_philo_data	init_data_struct(int argc, char **argv);

t_fork			*init_forks(uint8_t nb_forks);

t_timings		init_timings(int argc, char **argv);

#endif // !INIT_DATA_H