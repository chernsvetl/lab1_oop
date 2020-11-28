#include "LinkedList.h"

LinkedList::Node::Node() {
    value = value_type();
}

LinkedList::Node::Node(value_type val) {
    value = val;
}

LinkedList::Node::Node(value_type val, LinkedList::Node* prev_other, LinkedList::Node* next_other) {
    value = val;
    prev = prev_other;
    next = next_other;
}