#!/bin/bash

mkdir -p build
cd build
emcmake cmake ../
emmake make
emcc -lembind -o hevc_parser.html --shell-file ../app/web_app/template.html -Wl,--whole-archive libhevc_parser.a -L./ -lcommon -Wl,--no-whole-archive -sEXPORTED_FUNCTIONS=_malloc,_free -sALLOW_MEMORY_GROWTH=1