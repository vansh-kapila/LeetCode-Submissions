/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    int x = 0;
    vector<int>v; 
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    v=nums;
	}
	
	int peek() {
        return v[x];
	}
	
	int next() {
	    return v[x++];
	}
	
	bool hasNext() const {
	   return x<v.size();
	}
};
