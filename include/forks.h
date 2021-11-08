/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:56:20 by pbielik           #+#    #+#             */
/*   Updated: 2021/11/08 19:56:21 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORKS_H
# define FORKS_H

# include "types.h"

t_fork	*init_forks(int nb_forks);

bool	get_forks(t_philo *philo);

void	drop_forks(t_philo *philo);

#endif // !FORKS_H