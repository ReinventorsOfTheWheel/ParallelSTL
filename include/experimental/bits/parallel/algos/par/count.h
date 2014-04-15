#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>
#include <experimental/bits/parallel/algos/par/diffract.h>

namespace std {
namespace experimental {
namespace parallel {

  template<class InputIterator, class EqualityComparable>
    typename iterator_traits<InputIterator>::difference_type
      parallel_execution_policy::count(InputIterator first, InputIterator last, 
                                         const EqualityComparable &value) const
  {
    return detail::diffract_gather(first, last,
                                   std::count<InputIterator, EqualityComparable>,
                                   std::plus<typename iterator_traits<InputIterator>::difference_type>());
  }

} // namespace parallel
} // namespace experimental
} // namespace std
