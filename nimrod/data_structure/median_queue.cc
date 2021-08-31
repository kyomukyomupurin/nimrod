#include <queue>

template <class T>
class median_queue {
 public:
  median_queue() {}

  void emplace(T x) {
    if (lower_.empty()) {
      lower_.emplace(x);
    } else {
      if (x >= lower_.top()) {
        upper_.emplace(x);
      } else {
        lower_.emplace(x);
      }
      if (upper_.size() > lower_.size()) {
        T t = upper_.top();
        upper_.pop();
        lower_.emplace(t);
      }
      if (lower_.size() == upper_.size() + 2) {
        T t = lower_.top();
        lower_.pop();
        upper_.emplace(t);
      }
    }
  }

  T median() const {
    if (lower_.size() == upper_.size()) {
      return (lower_.top() + upper_.top()) / 2;
    } else {
      return lower_.top();
    }
  }

 private:
  std::priority_queue<T> lower_;
  std::priority_queue<T, std::vector<T>, std::greater<T>> upper_;
};