
# CMakeLists.txt, generated gencmake.pl, on 2020/08/20 19:29:22
cmake_minimum_required( VERSION 3.0 )

# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
message(FATAL_ERROR "
   ***FATAL***: Building in source directory '${CMAKE_SOURCE_DIR}'!
   i.e. in-source builds are NOT recommended/allowed.
   Create and use a separate folder, like 'md build'; 'cd build; 'cmake .. [options]'
   Make sure any 'CMakeCache.txt' file, and any 'CMakeFiles' folder are deleted.")
endif()

# CMakeScripts or use the ones that come by default with CMake.
# set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMakeModules ${CMAKE_MODULE_PATH})

project( sudoku_pwc )

# The version number.  *** FIX ME ***
set( sudoku_pwc_MAJOR 3 )
set( sudoku_pwc_MINOR 0 )
set( sudoku_pwc_POINT 0 )
# add_definitions( -DSUDOKU_PWC_VERSION="3.0.0" )

# Allow developer to select is Dynamic or static library built
set( LIB_TYPE STATIC )  # set default static
option( BUILD_SHARED_LIB "Set ON to build shared Library (DLL)" OFF )
option( LOG_IN_OUT "Set ON to output entry and exit each servcie" OFF )

if(CMAKE_COMPILER_IS_GNUCXX)
    set( WARNING_FLAGS -Wall )
endif(CMAKE_COMPILER_IS_GNUCXX)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang") 
   set( WARNING_FLAGS "-Wall -Wno-overloaded-virtual" )
endif() 

if(WIN32 AND MSVC)
    # turn off various warnings - none needed in this compile
    set(WARNING_FLAGS "${WARNING_FLAGS} /wd4996")
    # foreach(warning 4244 4251 4267 4275 4290 4786 4305)
    #     set(WARNING_FLAGS "${WARNING_FLAGS} /wd${warning}")
    # endforeach(warning)
    # other flags: -DNOMINMAX  -D_SCL_SECURE_NO_WARNINGS -D__CRT_NONSTDC_NO_WARNINGS
    set( MSVC_FLAGS "-D_USE_MATH_DEFINES -D_CRT_SECURE_NO_WARNINGS" )
    #set( NOMINMAX 1 )
    # to distinguish between debug and release libs
    set( CMAKE_DEBUG_POSTFIX "d" )
    option( USE_STATIC_RUNTIME "Set ON to change /MD(DLL) to /MT(static)" ON )
    if (USE_STATIC_RUNTIME)
        set(CompilerFlags
            CMAKE_CXX_FLAGS
            CMAKE_CXX_FLAGS_DEBUG
            CMAKE_CXX_FLAGS_RELEASE
            CMAKE_C_FLAGS
            CMAKE_C_FLAGS_DEBUG
            CMAKE_C_FLAGS_RELEASE
            )
        foreach(CompilerFlag ${CompilerFlags})
            string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
        endforeach()    
        message(STATUS "Using /MT STATIC runtime")
    else ()
        message(STATUS "Using /MD DYNAMIC runtime")
    endif ()
else()
    # items for unix
endif()

set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${WARNING_FLAGS} ${MSVC_FLAGS} -D_REENTRANT" )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WARNING_FLAGS} ${MSVC_FLAGS} -D_REENTRANT" )
set( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${MSVC_LD_FLAGS}" )

if (LOG_IN_OUT)
add_definitions( -DLOG_IN_OUT )
endif (LOG_IN_OUT)

# configuration file, if needed
# configure_file( ${CMAKE_SOURCE_DIR}/config.h.cmake ${CMAKE_BINARY_DIR}/config.h )
# add_definitions( -DHAVE_CONFIG_H )
# include_directories( ${CMAKE_BINARY_DIR} )

if(BUILD_SHARED_LIB)
   set(LIB_TYPE SHARED)
   message(STATUS "*** Building DLL library ${LIB_TYPE}")
else()
   message(STATUS "*** Option BUILD_SHARED_LIB is OFF ${LIB_TYPE}")
endif()
# Total libs 0, exes 2
#################################################
##### LIBRARIES 0 #####
#################################################
#list(APPEND add_LIBS ${name})
# deal with install, if any...
#install( TARGETS ${name}
#    RUNTIME DESTINATION bin
#    LIBRARY DESTINATION lib
#    ARCHIVE DESTINATION lib )
#install(FILES ${${name}_HDRS} DESTINATION include)
#################################################
##### EXECUTABLE 2 #####
#################################################

# Generator EXECUTABLE from [sources\Generator],
# have 15 C/C++ sources, 15 headers
set(name Sudo-Generator)
set(dir sources/Generator)
set(${name}_SRCS
    ${dir}/brute.c
    ${dir}/brute_comp.c
    ${dir}/count_solved.c
    ${dir}/display.c
    ${dir}/display_string.c
    ${dir}/fill.c
    ${dir}/fill_digit.c
    ${dir}/in_box.c
    ${dir}/inconsistent_grid.c
    ${dir}/inconsistent_unit.c
    ${dir}/init.c
    ${dir}/list_solved.c
    ${dir}/multi_html.c
    ${dir}/save_html.c
    ${dir}/sudoku_gen.c
    )
set(${name}_HDRS
    ${dir}/brute.h
    ${dir}/brute_comp.h
    ${dir}/count_solved.h
    ${dir}/def.h
    ${dir}/display.h
    ${dir}/display_string.h
    ${dir}/fill.h
    ${dir}/fill_digit.h
    ${dir}/in_box.h
    ${dir}/inconsistent_grid.h
    ${dir}/inconsistent_unit.h
    ${dir}/init.h
    ${dir}/list_solved.h
    ${dir}/multi_html.h
    ${dir}/save_html.h
    )
add_executable( ${name} ${${name}_SRCS} ${${name}_HDRS} )
if (add_LIBS)
    target_link_libraries( ${name} ${add_LIBS} )
endif ()
if (MSVC)
    set_target_properties( ${name} PROPERTIES DEBUG_POSTFIX d )
endif ()
# deal with install, if any...
#install( TARGETS ${name} DESTINATION bin )

# Solver EXECUTABLE from [sources\Solver],
# have 51 C/C++ sources, 51 headers
set(name Sudo-Solver)
set(dir sources/Solver)
set(${name}_SRCS
    ${dir}/backtrack.c
    ${dir}/box_line.c
    ${dir}/box_line_unit.c
    ${dir}/cleanup.c
    ${dir}/cleanup_around.c
    ${dir}/cleanup_unit.c
    ${dir}/count_candidates.c
    ${dir}/count_solved.c
    ${dir}/display.c
    ${dir}/display_strats_in_clear.c
    ${dir}/display_string.c
    ${dir}/execute_strategies.c
    ${dir}/footprint.c
    ${dir}/hidden_pair.c
    ${dir}/hidden_pair_unit.c
    ${dir}/hidden_triple.c
    ${dir}/hidden_triple_unit.c
    ${dir}/inconsistent_grid.c
    ${dir}/inconsistent_unit.c
    ${dir}/init.c
    ${dir}/intersection.c
    ${dir}/keep_going.c
    ${dir}/lines.c
    ${dir}/lines_2.c
    ${dir}/lines_3.c
    ${dir}/lines_4.c
    ${dir}/naked_pair.c
    ${dir}/naked_pair_unit.c
    ${dir}/naked_quad.c
    ${dir}/naked_quad_unit.c
    ${dir}/naked_triple.c
    ${dir}/naked_triple_unit.c
    ${dir}/pairs_data.c
    ${dir}/pairs_find.c
    ${dir}/pointing_line.c
    ${dir}/pointing_line_box.c
    ${dir}/rectangle.c
    ${dir}/rectangle_cell.c
    ${dir}/rectangle_pattern.c
    ${dir}/rectangle_step.c
    ${dir}/remove_candidate.c
    ${dir}/solve.c
    ${dir}/sudoku_solver.c
    ${dir}/unique.c
    ${dir}/unique_loop.c
    ${dir}/unique_unit.c
    ${dir}/xy_chain.c
    ${dir}/xy_chain_digit.c
    ${dir}/xy_chain_step.c
    ${dir}/y_wing.c
    ${dir}/y_wing_digit.c
    )
set(${name}_HDRS
    ${dir}/backtrack.h
    ${dir}/box_line.h
    ${dir}/box_line_unit.h
    ${dir}/cleanup.h
    ${dir}/cleanup_around.h
    ${dir}/cleanup_unit.h
    ${dir}/count_candidates.h
    ${dir}/count_solved.h
    ${dir}/def.h
    ${dir}/display.h
    ${dir}/display_strats_in_clear.h
    ${dir}/display_string.h
    ${dir}/execute_strategies.h
    ${dir}/footprint.h
    ${dir}/hidden_pair.h
    ${dir}/hidden_pair_unit.h
    ${dir}/hidden_triple.h
    ${dir}/hidden_triple_unit.h
    ${dir}/inconsistent_grid.h
    ${dir}/inconsistent_unit.h
    ${dir}/init.h
    ${dir}/intersection.h
    ${dir}/keep_going.h
    ${dir}/lines.h
    ${dir}/lines_2.h
    ${dir}/lines_3.h
    ${dir}/lines_4.h
    ${dir}/naked_pair.h
    ${dir}/naked_pair_unit.h
    ${dir}/naked_quad.h
    ${dir}/naked_quad_unit.h
    ${dir}/naked_triple.h
    ${dir}/naked_triple_unit.h
    ${dir}/pairs_data.h
    ${dir}/pairs_find.h
    ${dir}/pointing_line.h
    ${dir}/pointing_line_box.h
    ${dir}/rectangle.h
    ${dir}/rectangle_cell.h
    ${dir}/rectangle_pattern.h
    ${dir}/rectangle_step.h
    ${dir}/remove_candidate.h
    ${dir}/solve.h
    ${dir}/unique.h
    ${dir}/unique_loop.h
    ${dir}/unique_unit.h
    ${dir}/xy_chain.h
    ${dir}/xy_chain_digit.h
    ${dir}/xy_chain_step.h
    ${dir}/y_wing.h
    ${dir}/y_wing_digit.h
    )
add_executable( ${name} ${${name}_SRCS} ${${name}_HDRS} )
if (add_LIBS)
    target_link_libraries( ${name} ${add_LIBS} )
endif ()
if (MSVC)
    set_target_properties( ${name} PROPERTIES DEBUG_POSTFIX d )
endif ()
# deal with install, if any...
#install( TARGETS ${name} DESTINATION bin )


# eof
