#include <iostream>
#include <cassert>

#include <chrono> 
using namespace std::chrono;




// The following code calls a naive algorithm for computing a Fibonacci number.
//
// What to do:
// 1. Compile the following code and run it on an input "40" to check that it is slow.
//    You may also want to submit it to the grader to ensure that it gets the "time limit exceeded" message.
// 2. Implement the fibonacci_fast procedure.
// 3. Remove the line that prints the result of the naive algorithm, comment the lines reading the input,
//    uncomment the line with a call to test_solution, compile the program, and run it.
//    This will ensure that your efficient algorithm returns the same as the naive one for small values of n.
// 4. If test_solution() reveals a bug in your implementation, debug it, fix it, and repeat step 3.
// 5. Remove the call to test_solution, uncomment the line with a call to fibonacci_fast (and the lines reading the input),
//    and submit it to the grader.

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    // std::cout << fibonacci_naive(n - 1) + fibonacci_naive(n - 2) << std::endl;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

long long Fib(int n){
    long long Fib_Num;

    if (n <= 1){
        Fib_Num = n;
        return Fib_Num;
    }

    int Fib1 = 0;
    int Fib2 = 1; 
    int Num = 0;

    for (int i = 1; i < n; i++ ){
        Num = Fib1 + Fib2;
        Fib_Num = Num;
        Fib1 = Fib2;
        Fib2 = Num;
        // std::cout << Fib_Num << std::endl;
    }
    return Fib_Num;
}

void test_solution() {
    for (int n = 0; n < 20; ++n)
        assert(Fib(n) == fibonacci_naive(n));
}

int main() {
    int n = 0;
    std::cin >> n;
    
    auto start = high_resolution_clock::now();
    std::cout << fibonacci_naive(n) << '\n';

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    std::cout << "duration: "<< duration.count() << " nanoseconds" << "\n\n";
    // test_solution();
    // std::cout << Fib(n) << '\n';
    return 0;
}
