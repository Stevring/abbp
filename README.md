# abbp
Annex B Byte Stream parser.

## Running module in browser
```
mkdir build
cd build
emcmake cmake ../ --fresh
emmake make
emcc libhevc_parser.a -o final.html -sEXPORTED_FUNCTIONS=_hevc_parser_init -sEXPORTED_RUNTIME_METHODS=ccall,cwrap
emcc -lembind -o hevc_parser.html -Wl,--whole-archive libhevc_parser.a -L./ -lcommon -Wl,--no-whole-archive -sEXPORTED_FUNCTIONS=_malloc,_free -sALLOW_MEMORY_GROWTH=1
```

in browser
```

      Module.onRuntimeInitialized = () => {
        fetch('IMG_0635.hevc').then((res) => res.arrayBuffer())
        .then((buffer) => {
          var buf = Module._malloc(buffer.byteLength);
          console.log(buffer);
          console.log(buf);
          Module.HEAPU8.set(buffer, buf);
          let parser = new Module.HEVCParser(buf, buffer.byteLength);
          parser.parse();
          Module._free(buf);
        });
      }
```

## Running app in nodejs
```
mkdir build
cd build
emcmake cmake ../ --fresh
emmake make
node parser.js \<file\>
```

