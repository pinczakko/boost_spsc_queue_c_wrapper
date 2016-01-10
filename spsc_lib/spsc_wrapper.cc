#include "spsc_test.hpp"
#include "spsc_wrapper.h"

#ifdef __cplusplus
extern "C" {
#endif

spsc_test * create_spsc_test()
{
    return new spsc_test();
}

void destroy_spsc_test(spsc_test * q)
{
    delete q;
}

int push_item(spsc_test * const q, const struct account * const acc)
{
    return q->push_item(acc);
}

int pop_item(spsc_test * const q, struct account * acc)
{
    return q->pop_item(acc);
}

int is_lock_free(spsc_test * const q)
{
    return q->is_lock_free();
}

void inc_producer_count(spsc_test * q)
{
    q->inc_producer_count();
}

void inc_consumer_count(spsc_test * q)
{
    q->inc_consumer_count();
}

int get_consumer_count(spsc_test * q)
{
    return q->get_consumer_count();
}

int  get_producer_count(spsc_test * q)
{
    return q->get_producer_count();
}

const int get_iterations_count(spsc_test * const q)
{
    return q->get_iterations_count();
}

void signal_done(spsc_test * const q)
{
    q->signal_done();
}

int is_done(spsc_test * const q)
{
    return q->is_done();
}

#ifdef __cplusplus
}
#endif

