#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "ANSI_COLORS.h"

void	*my_turn(void *arg)
{
	(void)arg;
	for (int i = 0; i < 8; i++)
	{
		sleep(1);
		printf(BHGRN"My Turn: %d\n", i);
	}
	return NULL;
}

void	your_turn()
{
	while (1)
	{
		sleep(2);
		printf(BHRED"Your Turn!\n");
	}
}

int	main()
{
	pthread_t	newthread; 

	pthread_create(&newthread, NULL, my_turn, NULL);
	your_turn();
	pthread_join(newthread, NULL);
}