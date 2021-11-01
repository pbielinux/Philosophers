#include "philo.h"

int	previous(int i, int size)
{
	if (i == 0)
		return (size - 1);
	return (i - 1);
}

int	next(int i, int size)
{
	if (i == size - 1)
		return (0);
	return (i + 1);
}

t_env	*get_philo_data(t_env *data)
{
	static t_env *static_data = NULL;

	if (!static_data && data)
		static_data = data;
	return (static_data);
}

void	print_usage_and_exit(void)
{
	printf(HRED"Wrong arguments!\n"RST\
		"  Try to run the program with the folowing args:\n"\
		BGRN"  ./pilosophers "YEL"[nb_of_philo] [t_to_die] [t_to_eat] "\
		"[t_to_sleep] "RST"[nb_of_meals]\n");
	exit(EXIT_FAILURE);
}