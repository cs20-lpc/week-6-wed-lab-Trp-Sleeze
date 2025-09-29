#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * Function prototypes (keep these)
*******************************************************************************/
unsigned fact(unsigned);
unsigned fib(unsigned);
unsigned mult(unsigned, unsigned);
unsigned power(unsigned, unsigned);
unsigned product(unsigned, unsigned);

/*******************************************************************************
 * main (already set up for the tests)
*******************************************************************************/
int main() {
    cout << "6 * 123000 = " << mult(6, 123000) << endl;
    cout << "3 ^ 10 = " << power(3, 10) << endl;
    cout << "8 * 9 * ... * 15 = " << product(8, 15) << endl;
    cout << "10! = " << fact(10) << endl;
    cout << "50th Fibonacci number is " << fib(50) << endl;
    return 0;
}

/*******************************************************************************
 * Tail-recursive implementations
*******************************************************************************/

// factorial n!
static unsigned factHelper(unsigned n, unsigned acc) {
    if (n <= 1) return acc;
    return factHelper(n - 1, acc * n);
}
unsigned fact(unsigned n) {
    return factHelper(n, 1);
}

// fibonacci n (linear tail recursion)
static unsigned fibHelper(unsigned n, unsigned a, unsigned b) {
    if (n == 0) return a;
    if (n == 1) return b;
    return fibHelper(n - 1, b, a + b);
}
unsigned fib(unsigned n) {
    return fibHelper(n, 0, 1);
}

// multiplication x * y (tail recursion with log depth)
static unsigned multHelper(unsigned x, unsigned y, unsigned acc) {
    if (y == 0) return acc;
    if (y & 1u) acc += x;           // add one x if y is odd
    return multHelper(x << 1, y >> 1, acc); // double x, halve y
}
unsigned mult(unsigned x, unsigned y) {
    return multHelper(x, y, 0);
}

// power x ^ y (tail recursion with log depth)
static unsigned powerHelper(unsigned x, unsigned y, unsigned acc) {
    if (y == 0) return acc;
    if (y & 1u) acc *= x;           // fold one x into acc when y is odd
    return powerHelper(x * x, y >> 1, acc); // square base, halve exponent
}
unsigned power(unsigned x, unsigned y) {
    return powerHelper(x, y, 1);
}

// product x * (x+1) * ... * y
static unsigned productHelper(unsigned x, unsigned y, unsigned acc) {
    if (x > y) return acc;
    return productHelper(x + 1, y, acc * x);
}
unsigned product(unsigned x, unsigned y) {
    return productHelper(x, y, 1);
}
