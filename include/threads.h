/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:56:32 by pbielik           #+#    #+#             */
/*   Updated: 2021/11/08 19:58:29 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_H
# define THREADS_H

# include "types.h"

void	ft_init_threads(t_env *env);

void	ft_join_threads(t_env *env);

#endif // !INIT_THREADS_H