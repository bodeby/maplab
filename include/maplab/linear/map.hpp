// include/maplab/linear/map.hpp

#pragma once

#include <cstddef>

/*
* capacity is a power of two
* size <= capacity
* occupied buckets contain valid K/V pairs
* empty buckets have occupied == false
* hash index = hash(key) & (capacity - 1)
* probe sequence advances one bucket at a time
* lookup stops at an empty bucket
*/

namespace maplab {

template <typename K, typename V> class Map {
  public:
    void insert(const K& key, const V& value);

    V* find(const K& key);

    bool erase(const K& key);

    void reserve(std::size_t capacity);

    std::size_t size() const {
        return size_;
    }

  private:
    struct Bucket {
        K key;
        V value;
        bool occupied;
    };

    Bucket* buckets_{nullptr};
    std::size_t capacity_{0};
    std::size_t size_{0};
};

} // namespace maplab
