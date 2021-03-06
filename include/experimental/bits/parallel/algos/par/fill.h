#ifndef _EXPERIMENTAL_N3554_POLICY_PARALLEL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>
#include <experimental/bits/parallel/algos/par/diffract.h>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class ForwardIterator, class T>
    void parallel_execution_policy::fill(ForwardIterator first, ForwardIterator last, const T& value) const {
      detail::diffract(first, last, std::fill<ForwardIterator, T>, value);
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
