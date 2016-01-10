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

	typedef struct spsc_interface spsc_interface;

	spsc_interface *create_spsc_interface();
	void destroy_spsc_interface(spsc_interface * q);

	int push_item(spsc_interface * const q, const struct account *const acc);
	int pop_item(spsc_interface * const q, struct account *acc);

	int is_lock_free(spsc_interface * const q);

	void inc_producer_count(spsc_interface *);
	void inc_consumer_count(spsc_interface *);
	int get_consumer_count(spsc_interface *);
	int get_producer_count(spsc_interface *);

	void signal_done(spsc_interface * const);
	int is_done(spsc_interface * const);

	const int get_iterations_count(spsc_interface * const);

#ifdef __cplusplus
}
#endif
#endif				//SPSC_WRAPPER_H
