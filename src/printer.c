#include "philo.h"

pthread_mutex_t *init_printer_mutex(void)
{
	pthread_mutex_t	*printer_mutex;

	printer_mutex = malloc(sizeof(pthread_mutex_t));
	omm_guard(printer_mutex, __FILE__, __LINE__);
	if (pthread_mutex_init(printer_mutex, NULL) != 0)
		exit(EXIT_FAILURE);
	return (printer_mutex);
}