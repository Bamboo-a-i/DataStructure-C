#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "cjson" for configuration "Debug"
set_property(TARGET cjson APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(cjson PROPERTIES
  IMPORTED_IMPLIB_DEBUG "C:/Program Files (x86)/Project/lib/libcjson.dll.a"
  IMPORTED_LOCATION_DEBUG "C:/Program Files (x86)/Project/bin/libcjson.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS cjson )
list(APPEND _IMPORT_CHECK_FILES_FOR_cjson "C:/Program Files (x86)/Project/lib/libcjson.dll.a" "C:/Program Files (x86)/Project/bin/libcjson.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
