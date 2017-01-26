#include "philosophers.h"

#include <unistd.h>

void			*start_timer(void *null)
{
	(void)null;
	usleep(SECONDS(TIMEOUT));
	g_timeout = 1;
	return (0);
}

void			launch_timer(void)
{
	pthread_t	timer;

	pthread_create(&timer, 0, start_timer, 0);
	pthread_detach(timer);
}