#!/bin/bash

mkdir -p build
cd build

if [ "$1" == "wasm" ]
then
emcmake cmake ../ -D ENV=$1
emmake make
emcc -lembind -o hevc_parser.html --shell-file ../app/web_app/template.html -Wl,--whole-archive libhevc_parser.a -L./ -lcommon -Wl,--no-whole-archive -sEXPORTED_FUNCTIONS=_malloc,_free -sALLOW_MEMORY_GROWTH=1
else
cmake ../ -D ENV=$1
make
fi

