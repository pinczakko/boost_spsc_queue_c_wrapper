#ifndef SPSC_INTERFACE_HPP
#define SPSC_INTERFACE_HPP

#include <boost/thread/thread.hpp>
#include <boost/lockfree/spsc_queue.hpp>

#include <boost/atomic.hpp>

#ifndef  SPSC_WRAPPER_H
#include "spsc_wrapper.h"
#endif //SPSC_WRAPPER_H 

class spsc_interface {
public:
    explicit spsc_interface();
    explicit spsc_interface(const spsc_interface &);
    ~spsc_interface() {};

    bool push_item(const struct account * const acc);
    bool pop_item(struct account * acc);

    const int get_iterations_count()
    {
        return iterations;
    }
    void inc_producer_count()
    {
        producer_count++;
    }
    void inc_consumer_count()
    {
        consumer_count++;
    }
    int get_consumer_count()
    {
        return consumer_count;
    }
    int  get_producer_count()
    {
        return producer_count;
    }
    void signal_done()
    {
        done = true;
    }
    bool is_done()
    {
        return done;
    }

    bool is_lock_free()
    {
        return spsc_queue.is_lock_free();
    }

#ifdef NDEBUG
    static inline void inc_connected_producer(){}
    static inline void inc_connected_consumer(){}
#else
    inline void inc_connected_producer(){ connected_producer++; }
    inline void inc_connected_consumer(){ connected_consumer++; }
#endif // NDEBUG

private:
    int producer_count;
    boost::atomic_int consumer_count;

    boost::lockfree::spsc_queue<struct account,
              boost::lockfree::capacity<QUEUE_ITEMS_COUNT>> spsc_queue;

    const int iterations;
    boost::atomic<bool> done;

#ifndef NDEBUG
    boost::atomic_int connected_producer;
    boost::atomic_int connected_consumer;
#endif // NDEBUG

};

#endif //SPSC_INTERFACE_HPP
