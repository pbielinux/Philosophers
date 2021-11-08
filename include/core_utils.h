/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:56:17 by pbielik           #+#    #+#             */
/*   Updated: 2021/11/08 19:59:16 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_UTILS_H
# define CORE_UTILS_H

# include "types.h"

t_env	*get_philo_data(t_env *data);

void	print_usage_and_exit(void);

void	ft_exit_and_free(void);

void	ft_exit_error(t_error_code error);

int		previous(int i, int size);

#endif // !CORE_UTILS_H