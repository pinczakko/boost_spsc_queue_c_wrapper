#ifndef SPSC_WRAPPER_H
#define SPSC_WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif

#define QUEUE_ITEMS_COUNT	8192

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

	typedef struct spsc_interface spsc_interface;

	spsc_interface *create_spsc_interface();
	void destroy_spsc_interface(spsc_interface * q);

	int push_item(spsc_interface * const q,
		      const struct account *const acc);
	int pop_item(spsc_interface * const q, struct account *acc);

	int is_lock_free(spsc_interface * const q);

	void inc_producer_count(spsc_interface *);
	void inc_consumer_count(spsc_interface *);
	int get_consumer_count(spsc_interface *);
	int get_producer_count(spsc_interface *);

	void signal_done(spsc_interface * const);
	int is_done(spsc_interface * const);

	const int get_iterations_count(spsc_interface * const);

#ifdef NDEBUG
	void use_as_producer(spsc_interface * const s) __attribute__((unused));
	void use_as_consumer(spsc_interface * const s) __attribute__((unused));
#else
	void use_as_producer(spsc_interface * const s);
	void use_as_consumer(spsc_interface * const s);
#endif //NDEBUG

#ifdef __cplusplus
}
#endif
#endif				//SPSC_WRAPPER_H
