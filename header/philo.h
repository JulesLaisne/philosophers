/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:21:59 by jlaisne           #+#    #+#             */
/*   Updated: 2023/05/04 16:20:56 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdint.h>

#define EPOCH_TIME_MS 0

typedef enum s_bool
{
	UNAVAILABLE,
	AVAILABLE
}	t_bool;

typedef struct s_philo
{
	struct timeval	time;
	struct s_philo	*p_left;
	struct s_philo	*p_right;
	pthread_mutex_t	mutex;
	int				id;
	int				n_time_to_die;
	int				n_time_to_eat;
	int				n_time_to_sleep;
	int				n_eat;
	t_bool			fork;
}	t_philo;

int		ft_atoi(const char *str, char *arg);
void	free_philo(t_philo *philo, pthread_t *threads);
void	*ft_calloc(size_t count, size_t size);

int		thread_join(int n_threads, pthread_t threads[]);
void	*thread_func(void *arg);
void	place_at_table(t_philo *philo, int n_threads);
void	usleep_fraction(int	time);
void	print_philo_state(t_philo *philo, char *state);

#endif