/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:04:21 by pbielik           #+#    #+#             */
/*   Updated: 2021/11/08 19:18:42 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc < 5 || argc > 6)
		print_usage_and_exit();
	env = init_env_struct(argc, argv);
	get_philo_data(&env);
	ft_init_threads(&env);
	ft_join_threads(&env);
	ft_exit_and_free();
}
