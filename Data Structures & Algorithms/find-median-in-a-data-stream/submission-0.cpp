class MedianFinder {
public:
    // Max-heap for the lower half of numbers
    // By default, std::priority_queue is a max-heap
    std::priority_queue<int> max_heap_low;

    // Min-heap for the upper half of numbers
    // Use std::greater<int> to make it a min-heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap_high;

    MedianFinder() {
        // Constructor: Heaps are automatically initialized as empty.
    }

    void addNum(int num) {
        // Step 1: Add the number to the appropriate heap
        // If max_heap_low is empty or num is less than or equal to its top,
        // it belongs in the lower half. Otherwise, it belongs in the upper half.
        if (max_heap_low.empty() || num <= max_heap_low.top()) {
            max_heap_low.push(num);
        } else {
            min_heap_high.push(num);
        }

        // Step 2: Balance the heaps to maintain the size invariant
        // The goal is to keep max_heap_low's size either equal to or
        // one greater than min_heap_high's size.

        // If max_heap_low is too big, move its largest element to min_heap_high
        if (max_heap_low.size() > min_heap_high.size() + 1) {
            min_heap_high.push(max_heap_low.top());
            max_heap_low.pop();
        }
        // If min_heap_high is too big, move its smallest element to max_heap_low
        else if (min_heap_high.size() > max_heap_low.size()) {
            max_heap_low.push(min_heap_high.top());
            min_heap_high.pop();
        }
    }

    double findMedian() {
        // If both heaps have the same number of elements, it's an even count.
        // The median is the average of their top elements.
        if (max_heap_low.size() == min_heap_high.size()) {
            // Need to cast to double for floating-point division
            return (static_cast<double>(max_heap_low.top()) + min_heap_high.top()) / 2.0;
        } else {
            // If max_heap_low has one more element, it's an odd count.
            // The median is the top of the max_heap_low.
            return static_cast<double>(max_heap_low.top());
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */