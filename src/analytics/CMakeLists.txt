cmake_minimum_required(VERSION 3.0)

project(Analytics C)

# Voir https://gitlab.kitware.com/cmake/community/-/wikis/doc/cmake/RPATH-handling
# Voir https://cmake.org/cmake/help/latest/variable/CMAKE_INSTALL_RPATH_USE_LINK_PATH.html
# Voir https://en.wikipedia.org/wiki/Rpath
# Voir https://en.wikipedia.org/wiki/Environment_variable#$LD_LIBRARY_PATH
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)

# add_executable(analytics-executable analytics.c analytics.h)
add_library(analytics SHARED analytics.c analytics.h)

install(
  TARGETS analytics
  LIBRARY DESTINATION lib/${CMAKE_BUILD_TYPE} COMPONENT "Libraries"
  ARCHIVE DESTINATION lib/${CMAKE_BUILD_TYPE} COMPONENT "Libraries"
  RUNTIME DESTINATION bin/${CMAKE_BUILD_TYPE} COMPONENT "Libraries"
)

install(
  FILES analytics.h
  DESTINATION include
  COMPONENT "Headers"
)

# Ajout d'un fichier de configuration de type pkgconfig
# Voir https://fr.wikipedia.org/wiki/Pkg-config et
# https://cmake.org/cmake/help/latest/command/configure_file.html
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/analytics.pc.in
  ${CMAKE_CURRENT_BINARY_DIR}/analytics.pc
  @ONLY
)
install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/analytics.pc
  DESTINATION share/pkgconfig/${CMAKE_BUILD_TYPE}
  COMPONENT "PkgConfig"
)

# Ajout d'un fichier de configuration de type cmake
# Voir https://cmake.org/cmake/help/latest/module/CMakePackageConfigHelpers.html
include(CMakePackageConfigHelpers)
configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/AnalyticsConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/AnalyticsConfig.cmake
  INSTALL_DESTINATION cmake
)

install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/AnalyticsConfig.cmake
  DESTINATION cmake
  COMPONENT "cmake"
)

add_executable(test-analytics test-analytics.c analytics.h)
add_dependencies(test-analytics analytics)
target_link_libraries(test-analytics analytics)

enable_testing()

add_test(test-analytics ./test-analytics)
