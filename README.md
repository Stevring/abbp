# abbp
Annex B Byte Stream parser.

## Running module in browser
```
mkdir build
cd build
emcmake cmake ../ --fresh
emmake make
emcc libhevc_parser.a -o final.html -sEXPORTED_FUNCTIONS=_hevc_parser_init -sEXPORTED_RUNTIME_METHODS=ccall,cwrap
```

in browser
```
hevc_parser_init = Module.cwrap('hevc_parser_init', null, ['string'])
hevc_parser_init('test')
```

## Running app in nodejs
```
mkdir build
cd build
emcmake cmake ../ --fresh
emmake make
node parser.js \<file\>
```

