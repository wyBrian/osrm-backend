mkdir -p build
cd build
sudo cmake .. -DCMAKE_BUILD_TYPE=Release -DENABLE_MASON=ON -DBUILD_PACKAGE=OFF
sudo cmake --build .