cmake -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" -S \ -B \cmake-build-debug
cmake --build \cmake-build-debug --target WaifuRPG -- -j 10