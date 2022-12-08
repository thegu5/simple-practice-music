# remember to actually set these..
export SPLAT_DIR=/home/gu5/splat
export TOOLCHAIN_REPO=/home/gu5/Documents/clang-msvc-sdk

export HOST_ARCH=x86
export MSVC_BASE=$SPLAT_DIR/crt
export WINSDK_BASE=$SPLAT_DIR/sdk
# TODO: get this from the thing..
export WINSDK_VER=10.0.20348
# change this to your llvm version!!!
export LLVM_VER=14
export CLANG_VER=$LLVM_VER

# you can also use `-G Ninja` here
cmake \
  -DCMAKE_TOOLCHAIN_FILE=$TOOLCHAIN_REPO/clang-cl-msvc.cmake \
  -DCMAKE_BUILD_TYPE=Release -B build
  
cmake --build build --config Release
