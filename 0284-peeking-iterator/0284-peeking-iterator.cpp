// C++ Iterator interface reference:
// class Iterator {
//     struct Data;
//     Data* data;
//     Iterator(const vector<int>& nums);
//     Iterator(const Iterator& iter);
//     virtual ~Iterator();
//     int next();
//     bool hasNext();
// };

class PeekingIterator : public Iterator {
private:
    int peeked;
    bool hasPeeked;
    
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums), hasPeeked(false) {}
    
    int peek() {
        if (!hasPeeked) {
            peeked = Iterator::next();
            hasPeeked = true;
        }
        return peeked;
    }
    
    int next() {
        if (hasPeeked) {
            hasPeeked = false;
            return peeked;
        }
        return Iterator::next();
    }
    
    bool hasNext() {
        return hasPeeked || Iterator::hasNext();
    }
};