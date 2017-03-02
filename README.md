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
