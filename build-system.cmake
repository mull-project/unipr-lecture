function(add_test_app name mutator)
  set (sources ${ARGN})
  add_executable(${name} ${sources})
  target_compile_options(${name} PRIVATE -fembed-bitcode -Wno-literal-conversion)
  target_link_options(${name} PRIVATE -fembed-bitcode)

  add_executable(${name}_coverage ${sources})
  target_compile_options(${name}_coverage PRIVATE -fprofile-instr-generate -fcoverage-mapping -Wno-literal-conversion)
  target_link_options(${name}_coverage PRIVATE -fprofile-instr-generate -fcoverage-mapping)

  foreach(path ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
    set (IMPLICIT_HEADERS "-isystem${path} ${IMPLICIT_HEADERS}")
  endforeach()
  foreach(path ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})
    set (IMPLICIT_HEADERS "-isystem${path} ${IMPLICIT_HEADERS}")
  endforeach()

  add_custom_target(${name}_mutation
    COMMAND mull-cxx
    #    -mutators=cxx_
    # <  -> <=
    #      -mutators=cxx_boundary
    # == -> !=
    #      -mutators=cxx_comparison
    # + -> -
    #  -mutators=cxx_arithmetic
    --mutators=${mutator}
#    --ide-reporter-show-killed
    --compilation-flags="${IMPLICIT_HEADERS} -I${CMAKE_CURRENT_LIST_DIR}"
    --compdb-path=${CMAKE_BINARY_DIR}/compile_commands.json
    --strict
    --linker=${CMAKE_CXX_COMPILER}
    --linker-flags=-fsanitize=address
    $<TARGET_FILE:${name}>
    VERBATIM
  )
endfunction()