/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:56:29 by pbielik           #+#    #+#             */
/*   Updated: 2021/11/08 19:57:03 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_H
# define PRINTER_H

pthread_mutex_t	*init_printer_mutex(void);

void			ft_print_state(t_philo *philo);

#endif // !PRINTER_H