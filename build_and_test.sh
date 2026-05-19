#!/bin/bash
set -e

echo "==> Installing dependencies"
sudo apt-get update
sudo apt-get install -y cmake build-essential libgtest-dev

echo "==> Building Google Test from source"
cd /usr/src/gtest
sudo cmake .
sudo make
sudo cp lib/libgtest*.a /usr/lib
cd -

echo "==> Configuring project"
mkdir -p build && cd build
cmake .. -DBUILD_TESTS=ON
make -j$(nproc)

echo "==> Running tests"
ctest --output-on-failure

echo "==> Creating deb package"
cpack -G DEB

echo "==> Done. Package:"
ls -la *.deb
