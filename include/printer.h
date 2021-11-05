#ifndef PRINTER_H
# define PRINTER_H

pthread_mutex_t *init_printer_mutex(void);

void	ft_print_state(t_philo *philo);

#endif // !PRINTER_H