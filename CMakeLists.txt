cmake_minimum_required(VERSION 3.0.8)
project(uwb_common VERSION 0.1.0)

option(SELF_TEST_ENABLE "If is standalone project? (not part of some project)" OFF)

include(CTest)
enable_testing()

if(SELF_TEST_ENABLE)
    execute_process(
        COMMAND git clone https://github.com/drivextech/dxt_common
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
    add_subdirectory(${PROJECT_SOURCE_DIR}/dxt_common EXCLUDE_FROM_ALL)
    include_directories(${PROJECT_SOURCE_DIR}/dxt_common)
endif()
unset(SELF_TEST_ENABLE CACHE)


include_directories(${PROJECT_SOURCE_DIR})

# add_library(dwt_common)
# target_link_libraries(dwt_common dxt_common)
# add_dependencies(dwt_common dxt_common)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
