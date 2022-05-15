mkdir 3rdparty && cd 3rdparty
git clone https://github.com/google/googletest.git
cd ..
mkdir build && cd build
export GOOGLE_TEST_DIR=googletest
cmake -DCMAKE_INSTALL_PREFIX=task-ci .. && make && make install
