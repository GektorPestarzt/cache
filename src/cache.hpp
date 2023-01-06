#ifndef SRC_CACHE_HPP_
#define SRC_CACHE_HPP_

#include "hashtable.hpp"
#include <queue>

#define MAX_ITEMS 20

template<class Arr, typename Key>
class cache {
public:
    Arr *get_item(const Key& word) {
        Arr *item_to_return = this->hashtable->get_item(word);
        return item_to_return;
    }

    bool push_item(Arr *item) {
        bool status = this->hashtable->push_item(item);

        if (!status) {
            if (this->queue->size() == MAX_ITEMS) {
                Arr *old_item = this->queue->front();
                this->hashtable->erase(old_item->data);
                queue->pop();
            }

            queue->push(item);
        }

        return status;
    }

public:
    cache() {
        this->hashtable = new hash_table<Arr, Key>();
        this->queue = new std::queue<Arr *>();
    }

    ~cache() {
        delete this->hashtable;
        delete this->queue;
    }

private:
    hash_table<Arr, Key> *hashtable;
    std::queue<Arr *> *queue;
};

#endif  // SRC_CACHE_HPP_