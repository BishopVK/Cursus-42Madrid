/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precise_usleep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 21:44:44 by danjimen          #+#    #+#             */
/*   Updated: 2024/07/02 22:06:52 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <string.h>

typedef struct {
	unsigned int usec;
	pthread_mutex_t mutex;
	pthread_cond_t cond;
} precise_sleep_data_t;

void* precise_sleep_thread(void* arg) {
	precise_sleep_data_t* data = (precise_sleep_data_t*)arg;
	struct timeval start, end;
	unsigned int elapsed;

	gettimeofday(&start, NULL);

	while (elapsed < data->usec) {
		gettimeofday(&end, NULL);
		elapsed = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
		if (elapsed >= data->usec) {
			pthread_mutex_lock(&data->mutex);
			pthread_cond_signal(&data->cond);
			pthread_mutex_unlock(&data->mutex);
			break;
		}
		usleep(data->usec - elapsed);
	}

	return NULL;
}

int precise_usleep(unsigned int usec) {
	pthread_t thread;
	precise_sleep_data_t data;

	data.usec = usec;
	pthread_mutex_init(&data.mutex, NULL);
	pthread_cond_init(&data.cond, NULL);

	pthread_mutex_lock(&data.mutex);

	if (pthread_create(&thread, NULL, precise_sleep_thread, &data) != 0) {
		pthread_mutex_unlock(&data.mutex);
		pthread_mutex_destroy(&data.mutex);
		pthread_cond_destroy(&data.cond);
		return -1;
	}

	pthread_cond_wait(&data.cond, &data.mutex);
	pthread_mutex_unlock(&data.mutex);

	pthread_join(thread, NULL);

	pthread_mutex_destroy(&data.mutex);
	pthread_cond_destroy(&data.cond);

	return 0;
}

int main() {
	printf("Sleeping for 1 second...\n");
	precise_usleep(1000000);
	printf("Awake!\n");

	return 0;
}