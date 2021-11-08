#ifndef CORE_UTILS_H
# define CORE_UTILS_H

# include "types.h"

t_env	*get_philo_data(t_env *data);

void	print_usage_and_exit(void);

void	ft_exit_and_free(void);

void	ft_exit_error(error_code error);

int		previous(int i, int size);

#endif // !CORE_UTILS_H