#include "spsc_test.hpp"

spsc_test::spsc_test():producer_count(0),
    consumer_count(0),
    done(false),
    iterations(1000000)
{

}

spsc_test::spsc_test(const spsc_test &orig):iterations(orig.iterations),
    producer_count(orig.producer_count),
    consumer_count(0),
    done(false)
{
    // TODO: Copy contents of spsc_queue here!!!
}

bool spsc_test::push_item(const struct account * const acc)
{
    struct account tmp_acc;

    assert(acc != NULL);

    memcpy(&tmp_acc, acc, sizeof(struct account));

    return spsc_queue.push(tmp_acc);
}


bool spsc_test::pop_item(struct account * acc)
{
    struct account tmp_acc;
    bool retval = false;

    assert(acc != NULL);

    retval = spsc_queue.pop(tmp_acc);
    if (retval == false) {
        return false;
    }

    memcpy(acc, &tmp_acc, sizeof(struct account));
    return true;
}

