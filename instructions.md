This is a template guide to get raylib with c working with WASM without the hassle

## Install emscripten


```bash
# Get the emsdk repo
git clone https://github.com/emscripten-core/emsdk.git

cd emsdk

# Fetch the latest version of the emsdk (not needed the first time you clone)
git pull

# Download and install the latest SDK tools.
./emsdk install latest

# Make the "latest" SDK "active" for the current user. (writes .emscripten file)
./emsdk activate latest

# Activate PATH and other environment variables in the current terminal
source ./emsdk_env.sh
cd ..
# I personaly use fish, so for me it is :
# source ./emsdk_env.fish

```

And if you get an error about python try this:
``` bash

# Or in fish
# set -e myvar 
```

## Download the raylib src

This takes a long time...

```bash
git clone <https://github.com/raysan5/raylib.git>
```

## Build raylib

```bash
cd raylib/src
make PLATFORM=PLATFORM_WEB
cd ../..
```

## Create your project

```bash
touch main.c
# Add your source code to main.c
```

You should be able to just run it with

```bash
clang main.c -o main -lraylib && ./main
```


## Compile to WASM

```bash
 emcc main.c -o index.html -Iraylib/src -Lraylib/src -lraylib -s USE_GLFW=3 -s WASM=1 -s USE_WEBGL2=1 -sASYNCIFY 
```

## Lets see it in action
If you have python3 you can start your app with:

```bash
python3 -m http.server
```

If you have nodejs you can start your app with:

```bash
npx serve
```