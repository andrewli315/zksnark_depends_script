libsnark compile guide
###
```
$ mkdir depends
$ git clone https://github.com/scipr-lab/libsnark
# construct a CMakeLists.txt as follow
$ cd libsnark 
$ mkdir build && cd build && cmake ..
```

### CMakeLists.txt in /{path for zksnark}/depends
```
add_subdirectory(libsnark)
```

### install
```
# in /{path for zksnark}/depends/build
$ make 
$ make check
```

### CMakeLists.txt for your source code
```
cmake_minimum_required(VERSION 2.8)

project()

```


### build your source code
```
mkdir build && cd build && cmake ..
make 
make check

```
