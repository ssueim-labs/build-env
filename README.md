# build-env
Personal build environment for cross-compile

# required
* Visual Studio Community 2015 ( msvc 14.0 )
* CMake 3.11.1 ( [download](https://cmake.org/download/) )
* Boost-1.66 ( [download](https://sourceforge.net/projects/boost/files/boost-binaries/1.66.0/) )
* cygwin 2.10.0 ( [download](https://www.cygwin.com) )

# git clone
~~~
git clone https://github.com/ssueim-labs/build-env.git
~~~

# build on windows
~~~
cd build-env/build
cmake ..
~~~
check .sln files for build

# build on cygwin
~~~
cd build-env/build
cmake ..
make
~~~
