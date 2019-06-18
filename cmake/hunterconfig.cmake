
hunter_config(folly
        # GIT_SUBMODULE "folly"
        URL "https://github.com/YOU-i-Labs/folly/archive/2018.10.22.00-youi2.tar.gz"
        VERSION "2018.10.22.00-youi2"
        SHA1 "0585e93ae1d32bfd93e1fd9765d765f6160668cd"
        CMAKE_ARGS BUILD_SHARED_LIBS=OFF FOLLY_POD_CONFIGURATION=ON)

hunter_config(double-conversion
        VERSION "3.1.4"
        CMAKE_ARGS BUILD_SHARED_LIBS=OFF)

hunter_config(glog
        #GIT_SUBMODULE "glog"
       URL "https://github.com/YOU-i-Labs/glog/archive/v0.3.5-youi3.zip"
       VERSION "0.3.5-youi3"
       SHA1 "6a61b6df37b6baa54679951ec5024b11c224f855"
        CMAKE_ARGS WITH_GFLAGS=OFF BUILD_TESTING=OFF BUILD_SHARED_LIBS=OFF)
