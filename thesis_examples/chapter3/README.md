## Build
mkdir build
cd build
cmake -DCMAKE_PREFIX_PATH=hpx_localization ..
make -jN

for a specific section, for example: 
make chapter3.section5

## Run
All examples will be in build/bin