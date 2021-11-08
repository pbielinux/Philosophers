/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:55:55 by pbielik           #+#    #+#             */
/*   Updated: 2021/11/08 19:55:56 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *s)
{
	int		sign;
	int		r;
	int		flag;

	r = 0;
	sign = 1;
	while (ft_isspace(*s))
		s++;
	flag = 0;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		flag++;
		s++;
	}
	if (flag > 1)
		return (0);
	while (*s >= '0' && *s <= '9')
	{
		r = r * 10 + *s - '0';
		s++;
	}
	return (r * sign);
}

void	*omm_guard(void *ptr, char *file, int number)
{
	if (ptr == NULL)
	{
		fprintf(stderr, "%s:%d Out of Memory", file, number);
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

int	ft_isspace(int c)
{
	if (c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}
