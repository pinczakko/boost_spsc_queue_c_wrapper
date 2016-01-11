#include <assert.h>
#include "spsc_interface.hpp"

spsc_interface::spsc_interface():producer_count(0),
    consumer_count(0),
    done(false),
    iterations(10000000)
{
#ifndef NDEBUG
    connected_producer = 0;
    connected_consumer = 0;
#endif // NDEBUG
}

spsc_interface::spsc_interface(const spsc_interface &orig):iterations(orig.iterations),
    producer_count(orig.producer_count),
    consumer_count(0),
    done(false)
{
    // TODO: Copy contents of spsc_queue here!!!
}

bool spsc_interface::push_item(const struct account * const acc)
{
    struct account tmp_acc;

    assert(acc != NULL);
	assert(connected_producer == 1);

    memcpy(&tmp_acc, acc, sizeof(struct account));

    return spsc_queue.push(tmp_acc);
}


bool spsc_interface::pop_item(struct account * acc)
{
    struct account tmp_acc;
    bool retval = false;

    assert(acc != NULL);
	assert(connected_consumer == 1);

    retval = spsc_queue.pop(tmp_acc);
    if (retval == false) {
        return false;
    }

    memcpy(acc, &tmp_acc, sizeof(struct account));
    return true;
}

