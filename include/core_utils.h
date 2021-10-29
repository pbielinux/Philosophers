#ifndef CORE_UTILS_H
# define CORE_UTILS_H

# include "types.h"

void			print_usage_and_exit(void);

t_env	*get_philo_data(t_env *data);

int	next(int i, int size);

int	previous(int i, int size);

#endif // !CORE_UTILS_H