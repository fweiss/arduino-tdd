current googletest build uses bazel

download bazel bbinary install for mac os

don't need cmake or bazel, just run directly;

``g++ -std=c++11 -stdlib=libc++ -DGTEST_USE_OWN_TR1_TUPLE=1 -Igoogletest/include -Igoogletest -c googletest/src/gtest-all.cc``

https://stackoverflow.com/questions/15852631/how-to-install-gtest-on-mac-os-x-with-homebrew

``g++ -std=c++11 -stdlib=libc++ -DGTEST_USE_OWN_TR1_TUPLE=1 -Igooglemock/include -Igooglemock -Igoogletest/include -c googlemock/src/gmock-all.cc``

Note that the define resolves the old problems with gtest-port.h

you can use the .o or create an archive:

``ar -rv libgmock.a gmock-all.o``

in googlemock/include/gmock/gmock-matchers.h

need to add a (bool) cast to true ca 3956
