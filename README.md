# abbp
Annex B Byte Stream parser.

## Running module in browser
```
mkdir build
cd build
emcmake cmake ../ --fresh
emmake make
emcc libhevc_parser.a -o final.html -sEXPORTED_FUNCTIONS=_hevc_parser_init -sEXPORTED_RUNTIME_METHODS=ccall,cwrap
emcc -lembind -o hevc_parser.html -Wl,--whole-archive libhevc_parser.a -L./ -lcommon -Wl,--no-whole-archive
```

in browser
```
let hevc_buffer;fetch('test.hevc').then((res) => res.arrayBuffer()).then((buffer) => hevc_buffer = buffer);
```

## Running app in nodejs
```
mkdir build
cd build
emcmake cmake ../ --fresh
emmake make
node parser.js \<file\>
```

