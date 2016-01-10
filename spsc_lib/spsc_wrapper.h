#ifndef SPSC_WRAPPER_H
#define SPSC_WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif

	struct account {
		char name[20];
		char balance[14];

		/*
		   operator char*()
		   {
		   return balance;
		   }
		 */
	};

	typedef struct spsc_test spsc_test;

	spsc_test *create_spsc_test();
	void destroy_spsc_test(spsc_test * q);

	int push_item(spsc_test * const q, const struct account *const acc);
	int pop_item(spsc_test * const q, struct account *acc);

	int is_lock_free(spsc_test * const q);

	void inc_producer_count(spsc_test *);
	void inc_consumer_count(spsc_test *);
	int get_consumer_count(spsc_test *);
	int get_producer_count(spsc_test *);

	const int get_iterations_count(spsc_test * const);

#ifdef __cplusplus
}
#endif
#endif				//SPSC_WRAPPER_H
