#include "assignment/fibonacci.hpp"

#include <cmath>    // pow, sqrt, round
#include <cstdint>  // int64_t

namespace assignment {

  int64_t fib_binet(int n) {

    if (n <= 1) {
      return n;
    }

    double double_n = static_cast<double>(n);
    double num = pow((1 + sqrt(5.0))/2.0, double_n) - pow(((1 - sqrt(5.0))/2.0), double_n);
    return static_cast<int64_t>(num / sqrt(5.0));
  }

  int64_t fib_iterative(int n) {

    if (n <= 1) {
      return n;
    }

    // буфер для хранения двух последних значения ряда Фибоначчи
    int64_t fib_prev = 0;
    int64_t fib_curr = 1;

    // Напишите здесь свой код ...
    for (int i = 1; i < n; i++) {
      int64_t next = fib_prev + fib_curr;
      fib_prev = fib_curr;
      fib_curr = next;
    }
    return fib_curr;
  }

  int64_t fib_recursive(int n) {
    if (n <= 1) {
      return n;
    }
    // Напишите здесь свой код ...
    return fib_recursive(n-1) + fib_recursive(n-2);
  }

  int64_t fib_recursive_memoization(int n, std::vector<int64_t>& cache) {

    if (n <= 1) {
      return cache[n];
    }

    if (cache[n] != -1) {
      return cache[n];
    }

    int64_t prev1 = fib_recursive_memoization(n-1, cache);
    cache[n-1] = prev1;
    int64_t prev2 = fib_recursive_memoization(n-2, cache);
    cache[n-2] = prev2;
    return prev1 + prev2;
  }

  int64_t fib_matrix(int n) {

    if (n <= 1) {
      return n;
    }

    Matrix2x2 P = {{{0, 1}, {1, 1}}};
    P = matrix_power(P, n-1);
    // Tip: используйте реализованную функцию matrix_pow
    return P[0][0] + P[1][0];
  }

}  // namespace assignment
