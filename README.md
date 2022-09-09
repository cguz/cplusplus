# C++ 11 / 17 / 20

<a href="https://isocpp.org"><img src="https://raw.githubusercontent.com/cguz/cguz/main/assets/cplusplus.svg" alt="C++" title="C++" height="24px" hspace="5px" /></a>

Continuously learning the C++ language. 

## Courses

* [Modern C++ Concurrency in Depth (C++17/20)](https://www.udemy.com/course/modern-cpp-concurrency-in-depth/) : 35% Complete
* [Learn Multithreading in C++](https://www.udemy.com/course/cplusplus-multithreading) : 0 % Complete
* [Design Patterns in Modern C++](https://www.udemy.com/course/patterns-cplusplus/) : 70 % Complete
* [Learn Advanced Modern C++](https://www.udemy.com/course/learn-intermediate-modern-c/) : 60% Complete

## Code

In the folder [src](https://github.com/cguz/cplusplus/tree/main/src) you can find the implementented code of each course.


## Features

### C++ standard

- [ostringstream](https://cplusplus.com/reference/sstream/ostringstream/) oss

	- it is used as cout: oss << "example";
	- retrieve the text: oss.str()

### C++ 11

- [thread](https://en.cppreference.com/w/cpp/thread/thread)

	- join : waits for the thread to finish its execution
	- detach : permits the thread to execute independently from the thread handle
	- joinable : checks whether the thread is joinable, i.e. potentially running in parallel context
	- get_id : returns the id of the thread 
	- hardware_concurrency : returns the number of concurrent threads supported by the implementation


- [mutex](https://en.cppreference.com/w/cpp/thread/mutex)

	- lock_guard: is a mutex wrapper that provides a convenient RAII-style mechanism for owning a mutex for the duration of a scoped block.
	
	- [shared_ptr](https://en.cppreference.com/w/cpp/memory/shared_ptr) :  smart pointer that retains shared ownership of an object through a pointer. The object is destroyed and its memory deallocated when either of the following happens:

		* the last remaining shared_ptr owning the object is destroyed;
		* the last remaining shared_ptr owning the object is assigned another pointer via operator= or reset().

	- [unique_lock](https://en.cppreference.com/w/cpp/thread/unique_lock) : general-purpose mutex ownership wrapper.

		* lock (p1, p2)

- [condition_variable](https://en.cppreference.com/w/cpp/thread/condition_variable)

- [future](https://en.cppreference.com/w/cpp/thread/future): it provides a mechanism to access the result of asynchronous operations. 

	- std::future<int> answer = std::async(method); ... answer.get();
	- async policy (async, deferred)


### C++ 17 

### C++ 20

- [accumulate](https://en.cppreference.com/w/cpp/algorithm/accumulate) : Computes an operation of some given elements.

## Design Patterns in Modern C++

Following the Gamma Categorization, we have the following classification:

- Creational Patterns: deal with the creation
	- Builder
- Structural Patterns: deal with the structure, using interface and good API design
- Behavioral Patterns: no central theme. 

## Useful information

* [C++ compiler support](https://en.cppreference.com/w/cpp/compiler_support)
* [Compiler explorer](https://godbolt.org/)
* [Git repository of Modern C++ Concurrency in Depth course](https://github.com/kasunindikaliyanage/cpp_concurrency_masterclass)

