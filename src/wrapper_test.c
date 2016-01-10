#include <stdio.h>
#include <string.h>
#include <spsc_wrapper.h>
#include <pthread.h>
#include <assert.h>

void *producer(void *param)
{
	struct account acc;

	assert(param != NULL);

	spsc_test *s = (spsc_test *) param;

	int iterations = get_iterations_count(s);

	printf("Producer thread\n");

	for (int i = 0; i < iterations; ++i) {

		memset(acc.name, '\0', sizeof(acc.name));
		memset(acc.balance, '\0', sizeof(acc.balance));

		snprintf(acc.name, strlen("name") + 3, "name%d", i % 1000);
		strcat(acc.balance, "balance");

		while (push_item(s, &acc) == 0) ;

		inc_producer_count(s);
	}

	printf("Producer thread about to finish..\n");
}

void *consumer(void *param)
{
	struct account acc;
	assert(param != NULL);

	spsc_test *s = (spsc_test *) param;

	printf("Consumer thread\n");

	while (is_done(s) != 1) {
		while (pop_item(s, &acc) != 0) {
			inc_consumer_count(s);

			if ((get_consumer_count(s) % 100000) == 0) {
				printf("Account Name: %s\n", acc.name);
				printf("Account Balance: %s\n", acc.balance);
			}
		}
	}

	printf("Outside is_done() check\n");

	while (pop_item(s, &acc) != 0) {
		inc_consumer_count(s);

		if ((get_consumer_count(s) % 100000) == 0) {
			printf("Account Name: %s\n", acc.name);
			printf("Account Balance: %s\n", acc.balance);
		}
	}
}

int main(int argc, char *argv[])
{
	pthread_t prod_t_id, cons_t_id;
	pthread_attr_t t_attr;
	void *value;
	int ret = -1;

	spsc_test *s = create_spsc_test();

	if (s == NULL) {
		printf("Failed to create spsc_test object\n");
		return 0;
	}

	printf("spsc_queue is ");
	if (!is_lock_free(s)) {
		printf("not ");
	}
	printf("lockfree\n");

	pthread_attr_init(&t_attr);
	pthread_attr_setdetachstate(&t_attr, PTHREAD_CREATE_JOINABLE);

	ret = pthread_create(&prod_t_id, &t_attr, producer, s);
	if (ret != 0) {
		printf("Failed to run producer thread!\n");
	}

	ret = pthread_create(&cons_t_id, &t_attr, consumer, s);
	if (ret != 0) {
		printf("Failed to run consumer thread!\n");
	}

	pthread_join(prod_t_id, &value);
	printf("produced %d objects\n", get_producer_count(s));
	signal_done(s);

	pthread_join(cons_t_id, &value);
	printf("consumed %d objects\n", get_consumer_count(s));

	destroy_spsc_test(s);

	return 0;
}
