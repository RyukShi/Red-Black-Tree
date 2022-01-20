cmake_minimum_required(VERSION 3.0)

set(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)

project(RedBlackTree C)

# Recherche du projet cmake Analytics
find_package(Analytics REQUIRED)
include_directories(${ANALYTICS_INCLUDE_DIRS})
link_directories(${ANALYTICS_LIB_DIRS})

# add_executable(rb-tree red-black-tree.c red-black-tree.h)
add_library(red-black-tree SHARED red-black-tree.c red-black-tree.h)
target_link_libraries(red-black-tree ${ANALYTICS_LIBRARIES})

install(
	TARGETS red-black-tree
	LIBRARY DESTINATION lib/${CMAKE_BUILD_TYPE} COMPONENT "Libraries"
	ARCHIVE DESTINATION lib/${CMAKE_BUILD_TYPE} COMPONENT "Libraries"
	RUNTIME DESTINATION bin/${CMAKE_BUILD_TYPE} COMPONENT "Libraries"
)

install(
	FILES red-black-tree.h
	DESTINATION include
  COMPONENT "Headers"
)

# Ajout d'un fichier de configuration de type pkgconfig. Copie le 1er argument vers le 2ème. @ONLY = restreint le remplacement de variable dans red-black-tree.pc.in
# à celles qui ont le format @<var>@ pour éviter les conflits avec la syntaxe CMake ${<var>}.
configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/red-black-tree.pc.in
	${CMAKE_CURRENT_BINARY_DIR}/red-black-tree.pc
	@ONLY
)
install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/red-black-tree.pc
	DESTINATION share/pkgconfig/${CMAKE_BUILD_TYPE}
	COMPONENT "PkgConfig"
)

#  Ajout d'un fichier de configuration de type cmake
include(CMakePackageConfigHelpers)
configure_package_config_file(
	${CMAKE_CURRENT_SOURCE_DIR}/RedBlackTreeConfig.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/RedBlackTreeConfig.cmake
	INSTALL_DESTINATION cmake
)
install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/RedBlackTreeConfig.cmake
	DESTINATION cmake
  COMPONENT "cmake"
)

add_executable(red-black-tree-analytics red-black-tree-analytics.c red-black-tree.h)
add_dependencies(red-black-tree-analytics red-black-tree)
target_link_libraries(red-black-tree-analytics red-black-tree)

enable_testing()

find_program(VALGRIND "valgrind")

# Récupération dans la variable FILES des fichiers de test
file(GLOB FILES "${CMAKE_CURRENT_SOURCE_DIR}/test-*.c")

# Pour tous les fichiers de test
foreach(FILENAME ${FILES})
  # Récupération dans la variable SRC du nom sans le préfixe du dossier
  get_filename_component(SRC ${FILENAME} NAME)
  # Récupération dans la variable TEST du nom sans le préfixe du dossier
  # et sans le suffixe
  get_filename_component(TEST ${FILENAME} NAME_WE)
  # Ajout d'un exécutable dépendant également de red-black-tree.h
  add_executable(${TEST} ${SRC} red-black-tree.h)
  # Précision de l'ordre de construction: le programme de test doit se faire
  # après la librairie
  add_dependencies(${TEST} red-black-tree)
  # Assemblage du programme de test avec la librairie red-black-tree
  target_link_libraries(${TEST} red-black-tree)
  if(VALGRIND)
    # Ajout d'un test en utilisant valgrind
    add_test("${TEST}[valgrind]" ${VALGRIND} --leak-check=full --quiet --error-exitcode=1 ./${TEST})
    # Ajout d'un test normal
    add_test("${TEST}[normal]" ./${TEST})
  else()
    # Ajout d'un test simple
    add_test("${TEST}" ./${TEST})
  endif()
endforeach()

set(CPACK_SOURCE_GENERATOR "ZIP")
set(CPACK_SOURCE_IGNORE_FILES "~$;${CPACK_SOURCE_IGNORE_FILES}")
include(CPack)
