# Runway identifiers

This program transforms runway identifiers to the opposite direction according to the specification from the pdf file

# Prerequisite

Cmake must be installed on your machine,
you can download it here https://cmake.org/download/

# How to build

Open cmd and run the following:
```
.\build.bat
```

This will download Catch2 testing framework and build two targets:
* test binary
* program itself

# How to run tests

After building, in the same terminal run:
```
.\run_tests.cmd
```

# How to run the CLI itself

After building, in the same terminal run:
```
.\run.cmd 36
.\run.cmd 36C
...
.\run.cmd 01L
```
