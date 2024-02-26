# abbp
Annex B Byte Stream parser.

mkdir build
cd build
emcmake ../
emmake install
emcc libhevc_parser.a -o final.html -sEXPORTED_FUNCTIONS=_hevc_parser_init -sEXPORTED_RUNTIME_METHODS=ccall,cwrap

in broser
hevc_parser_init = Module.cwrap('hevc_parser_init', null, ['string'])
hevc_parser_init('test')
