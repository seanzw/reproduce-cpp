# reproduce-cpp
A toy program generates itself inspired by how a Turing Machine reproduces itself.

## How to use it
```sh
> g++ reproduce.cpp
> ./a.out > son.cpp
> g++ son.cpp
> ./a.out > grandson.cpp
> diff son.cpp grandson.cpp
```
## Idea
Consider how a Turing Machine `M` can write itself to the tape. Let `<M>` be the string representation of a Turing Machine `M`. You can think `<M>` as the source code of `M`. We first divide `M` into two submachines `A` and `B`, which work as:
```
A: Print <B>.
B: Insert "Print" at the left end of the tape;
   Copy anything behind "Print" and insert the duplicate after "Print".
```
Let's take a closer look at `M` by write down the content of the tape after each operation:
```
Tape: Empty
A:    Print <B>.
Tape: <B>
B:    Insert "Print" at the left end of the tape;
Tape: "Print" <B>
B:    Copy anything behind "Print" and insert the duplicate after "Print".
Tape: "Print" <B> <B>
```
Since `<A> = "Print" <B>`, we finally get a tape with `<A> <B>` which is essentially `<M>`.

## Practice with `C++`
Let's try this out using `C++`. We use `std::string` to represent the tape. The skeleton should be like:
```c++
#include <string>
#include <iostream>
#include <sstream>
int main() {
    // A.
    std::string tape = /* Source for B */;
    // B.
    tape = /* "Print" */ + tape + tape;
    std::cout << tape;
    return 0;
}
```
Since `A` depends on `B`, we first implement `B`. Luckily the only job left for us is to determine what `"Print"` is. It should be anything before `A` actually prints out `<B>`. Thus here it should be:
```c++
#include <string>
#include <iostream>
#include <sstream>
int main() {
    // A.
    std::string tape = 
```
Once we implemented `B`, we can write `A` by plugging in the source code of part `B`. However, simply copying `tape` won't work because we have to handle the escape characters. We need a help function to quote a given string:
```c++
std::string quote(const std::string& s) {
    std::stringstream ss;
    ss << '"';
    for (int i = 0; i < s.length(); ++i) {
        switch (s[i]) {
            case '\\': ss << "\\\\"; break;
            case '\"': ss << "\\\""; break;
            case '\'': ss << "\\\'"; break;
            case '\n': ss << "\\n"; break;
            default: ss << s[i];
        }
    }
    ss << '"';
    return ss.str();
}
```
And then change `B` to:
```c++
tape = /* "Print" */ + quote(tape) + tape;
```
Do not forget to change `A` after changing `B`. It should now works!