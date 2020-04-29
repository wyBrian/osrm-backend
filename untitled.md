```bash
mkdir -p build
cd build
sudo cmake .. -DCMAKE_BUILD_TYPE=Release -DENABLE_MASON=ON -DBUILD_PACKAGE=OFF
sudo cmake --build .
./osrm-routed --max-viaroute-size 5000 --max-matching-size 1000 --max-table-size 3000 --algorithm mld /Users/yu.w/workspace/apollo/indonesia_data/country.osrm
```