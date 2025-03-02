# ofxLibTorch (trying to make it work on Linux w/ GPU)

## 1
First, download libtorch (cpp, with ABI) somewhere. Used this version:

Download here (cxx11 ABI):
https://download.pytorch.org/libtorch/cu126/libtorch-cxx11-abi-shared-with-deps-2.6.0%2Bcu126.zip

## 2
Extracte to /home/user/some/path

## 3 VER SE PRECISA!!!!
Inside, created a .pc (pkg-config file)

```
# torch.pc

prefix=/home/user/some/path
exec_prefix=${prefix}
libdir=${exec_prefix}/lib
includedir=${prefix}/include

Name: torch
Description: The LibTorch library for PyTorch
Version: 2.6.0+cu126  # Replace with your LibTorch version
Cflags: -I${includedir} -I${includedir}/torch/csrc/api/include
Libs: -L${libdir} -ltorch -ltorch_cpu -lc10
```

adicionar às variáveis de ambiente
```
export LIBTORCH='/home/padovani/data/libtorch'
export LIBCUDA='/opt/cuda'
# export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:/opt/cuda/lib64:/home/padovani/data/libtorch/lib"
export LD_LIBRARY_PATH=$LIBTORCH/lib:$LIBCUDA/lib64:$LD_LIBRARY_PATH
export CMAKE_PREFIX_PATH=$LIBTORCH:$CMAKE_PREFIX_PATH
export PKG_CONFIG_PATH=$PKG_CONFIG_PATH:$LIBTORCH
```

atualizar cache
```
sudo ldconfig
```

conferir
```
ldconfig -p | grep libcuda 
```

## 4
rodar


-----
A ver:

1. melhor maneira de instalar libtorch e fazer tudo visível ao sistema (variáveis de ambiente, linker)

2. precisa de usar pkg-config ou não?

3. sistema de dependências e organização de makefiles para addons do oF

