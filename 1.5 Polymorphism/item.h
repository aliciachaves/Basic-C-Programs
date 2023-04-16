#ifndef PILHAPOLIMORFICA_ITEM_H
#define PILHAPOLIMORFICA_ITEM_H

#include <map>
#include <iostream>

class Item {

private:
    int _key, _val;
    std::map<int, int> mapitem;

public:
    Item() {
    }

    Item(int key, int val) {
        _key = key;
        _val = val;
    }

    friend bool operator>(const Item &i1, const Item &i2) {
        if (i1._val > i2._val) {
            return true;
        } else {
            return false;
        }
    }

    friend std::ostream &operator<<(std::ostream &out, const Item &i) {
        out << "(<" << i._key << ">,<" << i._val << ">)";
        return out;
    }

};


#endif
