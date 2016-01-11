#include "spsc_interface.hpp"
#include "spsc_wrapper.h"

#ifdef __cplusplus
extern "C" {
#endif

spsc_interface * create_spsc_interface()
{
    return new spsc_interface();
}

void destroy_spsc_interface(spsc_interface * q)
{
    delete q;
}

int push_item(spsc_interface * const q, const struct account * const acc)
{
    return q->push_item(acc);
}

int pop_item(spsc_interface * const q, struct account * acc)
{
    return q->pop_item(acc);
}

int is_lock_free(spsc_interface * const q)
{
    return q->is_lock_free();
}

void inc_producer_count(spsc_interface * q)
{
    q->inc_producer_count();
}

void inc_consumer_count(spsc_interface * q)
{
    q->inc_consumer_count();
}

int get_consumer_count(spsc_interface * q)
{
    return q->get_consumer_count();
}

int  get_producer_count(spsc_interface * q)
{
    return q->get_producer_count();
}

const int get_iterations_count(spsc_interface * const q)
{
    return q->get_iterations_count();
}

void signal_done(spsc_interface * const q)
{
    q->signal_done();
}

int is_done(spsc_interface * const q)
{
    return q->is_done();
}

#ifdef NDEBUG
void use_as_consumer(spsc_interface * const q) {}
void use_as_producer(spsc_interface * const q) {}
#else
void use_as_consumer(spsc_interface * const q)
{
    q->inc_connected_consumer();
}

void use_as_producer(spsc_interface * const q)
{
    q->inc_connected_producer();
}
#endif //NDEBUG

#ifdef __cplusplus
}
#endif

