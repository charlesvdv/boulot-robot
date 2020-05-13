# boulot-robot

![CI](https://github.com/charlesvdv/eurobot-2021/workflows/CI/badge.svg)

## Building

First, at the root of the project, run to initialize the build:

```sh
cmake -S . -B build
```

Then, to build the project run: 

```sh
cmake --build build
```

If you want to run the tests, in the `build` folder, run: 

```sh
ctest
```