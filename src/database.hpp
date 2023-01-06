#ifndef SRC_DATABASE_HPP_
#define SRC_DATABASE_HPP_

#include "cache.hpp"

template<class Arr, typename Key>
class data_base {
public:
    bool push_item(Arr *item) {
        bool status = !(find_item_in_vector(item->data));
        
        if (status) this->data->push_back(item);
        return !status;
    }

    Arr *get_item(const Key& key) {
        Arr *item_to_return = this->fast->get_item(key);
        if (!item_to_return) {
            item_to_return = this->find_item_in_vector(key);
            this->fast->push_item(item_to_return);
        }

        return item_to_return;
    }

    void print() {
        for (Arr *item : *(this->data)) {
            item->print();
        }
    }

private:
    Arr *find_item_in_vector(const Key& key) {
        Arr *item_to_return = nullptr;
        
        for (Arr *item : *(this->data)) {
            if (item->data == key) {
                item_to_return = item;
                break;
            }
        }

        return item_to_return;
    }

public:
    ~data_base() {
        delete this->fast;
        for (Arr *item : *(this->data)) delete item;
        delete this->data;
    }

private:
    std::vector<Arr *> *data = new std::vector<Arr *>();
    cache<Arr, Key> *fast = new cache<Arr, Key>();
};

#endif  // SRC_DATABASE_HPP_