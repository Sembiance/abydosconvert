cmake_minimum_required (VERSION 2.6)

enable_language(C)

set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wunreachable-code -Wpedantic -Wformat=2 -std=c99 -O3 -march=native -D_GNU_SOURCE -fshort-enums -ftrapv -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wno-unused-parameter -Wno-missing-field-initializers -D_DEFAULT_SOURCE" )
set ( CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g3" )

# -fno-omit-frame-pointer -fsanitize=address

#RELEASE BUILD: cmake -DCMAKE_BUILD_TYPE=Release ..
#  DEBUG BUILD: cmake -DCMAKE_BUILD_TYPE=Debug ..

include_directories(SYSTEM /usr/include/cairo /usr/include/abydos)

set(abydosconvert_srcs
	abydosconvert.h
	abydosconvert.c
	main.c
)

add_executable(abydosconvert ${abydosconvert_srcs})
target_link_libraries(abydosconvert "-lm")
target_link_libraries(abydosconvert "-lcairo")
target_link_libraries(abydosconvert "-labydos-0.2")
