
#include "lua_extensions_more.h"

#if __cplusplus
extern "C" {
#endif

// cjson
#include "cjson/lua_cjson.h"

// zlib
#include "zlib/lua_zlib.h"

// lpack
#include "lpack/lpack.h"

#ifndef WP8

// filesystem
#include "filesystem/lfs.h"
#endif

// lsqlite3
#include "lsqlite3/lsqlite3.h"

#include "lpeg/lpeg.h"

#include "bit/bit.h"


#include "sproto/lsproto.h"

static luaL_Reg luax_exts[] = {
    {"cjson", luaopen_cjson_safe},
    {"zlib", luaopen_zlib},
    {"pack", luaopen_pack},
#ifndef WP8
    {"lfs", luaopen_lfs},
#endif
#if CC_USE_SQLITE
    {"lsqlite3", luaopen_lsqlite3},
#endif
    {"lpeg",luaopen_lpeg},

  
    {"bit", luaopen_bit},

	{"sproto.core",luaopen_sproto_core},
    {NULL, NULL}
};

void luaopen_lua_extensions_more(lua_State *L)
{
    // load extensions
    luaL_Reg* lib = luax_exts;
    lua_getglobal(L, "package");
    lua_getfield(L, -1, "preload");
    for (; lib->func; lib++)
    {
        lua_pushcfunction(L, lib->func);
        lua_setfield(L, -2, lib->name);
    }
    lua_pop(L, 2);
}

#if __cplusplus
} // extern "C"
#endif
