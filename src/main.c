#include "philo.h"

static int	check_args(t_philo *philo)
{
	if (philo->n_philo <= 0)
	{
		printf("number_of_philosophers must be superior to 1.\n");
		return (1);
	}
	return (0);
}

static int	init_arguments(int argc, char **argv, t_philo *philo)
{
	philo->n_eat = -1;
	philo->n_philo = ft_atoi(argv[1], "number_of_philosophers");
	philo->n_time_to_die = ft_atoi(argv[2], "time_to_die");
	philo->n_time_to_eat = ft_atoi(argv[3], "time_to_eat");
	philo->n_time_to_sleep = ft_atoi(argv[4], "time_to_sleep");
	if (argc == 6)
		philo->n_eat = ft_atoi(argv[5], "number_of_times_each_philosopher_must_eat");
	if (check_args(philo) == 1)
		return (1);
	printf("%d\n%d\n%d\n%d\n%d\n", philo->n_philo, philo->n_time_to_die, philo->n_time_to_eat, philo->n_time_to_sleep, philo->n_eat);
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc == 5 || argc == 6)
	{
		if (init_arguments(argc, argv, &philo) == 1)
			exit(1);
	}
	else
	{
		printf("Arguments taken by philo: number_of_philosophers, \
			time_to_die, time_to_eat, time_to_sleep, \
				[number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	return (0);
}
