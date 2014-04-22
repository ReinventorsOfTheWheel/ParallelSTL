#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <experimental/algorithm>
#else
#include <algorithm>
#endif

TEST(all_of, True) {
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v{1,2,3,4,5,6,7,8,9};

  // everything is less than 10
  EXPECT_TRUE(all_of(
#ifdef EXECUTION_POLICY
                     EXECUTION_POLICY,
#endif
                     begin(v), end(v),
                     [](const int &i){ return i < 10; }));
}

TEST(all_of, False) {
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  vector<int> v{1,2,3,4,5,6,7,8,9};

  // not everything is 1
  EXPECT_FALSE(all_of(
#ifdef EXECUTION_POLICY
                      EXECUTION_POLICY,
#endif
                      begin(v), end(v),
                      [](const int &i){ return i == 1; }));
}

TEST(all_of, Empty) {
  using namespace std; 
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  vector<int> v;
  
  // empty range should return true regardless of the predicate
  EXPECT_TRUE(all_of(
#ifdef EXECUTION_POLICY
                     EXECUTION_POLICY,
#endif
                     begin(v), end(v),
                     [](const int &i){ return false; }));
}

