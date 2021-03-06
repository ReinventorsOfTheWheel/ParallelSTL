#ifndef _EXPERIMENTAL_N3554_POLICY_PARALLEL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>
#include <experimental/bits/parallel/algos/par/diffract.h>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class OutputIterator, class Size, class Generator>
    OutputIterator parallel_execution_policy::generate_n(OutputIterator first, Size n, Generator gen) const 
  {
    detail::diffract(first, first + n, std::generate_n<OutputIterator, Size, Generator>);
    return n > 0 ? first + n : first;
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
