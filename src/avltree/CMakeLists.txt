cmake_minimum_required(VERSION 3.0)

set(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)

project(AvlTree C)

# Recherche du projet cmake Analytics
find_package(Analytics REQUIRED)
include_directories(${ANALYTICS_INCLUDE_DIRS})
link_directories(${ANALYTICS_LIB_DIRS})

# add_executable(avl-tree avl-tree.c avl-tree.h)
add_library(avl-tree SHARED avl-tree.c avl-tree.h)
target_link_libraries(avl-tree ${ANALYTICS_LIBRARIES})

install(
	TARGETS avl-tree
	LIBRARY DESTINATION lib/${CMAKE_BUILD_TYPE} COMPONENT "Libraries"
	ARCHIVE DESTINATION lib/${CMAKE_BUILD_TYPE} COMPONENT "Libraries"
	RUNTIME DESTINATION bin/${CMAKE_BUILD_TYPE} COMPONENT "Libraries"
)

install(
	FILES avl-tree.h
	DESTINATION include
  COMPONENT "Headers"
)

# Ajout d'un fichier de configuration de type pkgconfig. Copie le 1er argument vers le 2ème. @ONLY = restreint le remplacement de variable dans avl-tree.pc.in
# à celles qui ont le format @<var>@ pour éviter les conflits avec la syntaxe CMake ${<var>}.
configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/avl-tree.pc.in
	${CMAKE_CURRENT_BINARY_DIR}/avl-tree.pc
	@ONLY
)
install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/avl-tree.pc
	DESTINATION share/pkgconfig/${CMAKE_BUILD_TYPE}
	COMPONENT "PkgConfig"
)

#  Ajout d'un fichier de configuration de type cmake
include(CMakePackageConfigHelpers)
configure_package_config_file(
	${CMAKE_CURRENT_SOURCE_DIR}/AvlTreeConfig.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/AvlTreeConfig.cmake
	INSTALL_DESTINATION cmake
)
install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/AvlTreeConfig.cmake
	DESTINATION cmake
  COMPONENT "cmake"
)

add_executable(avl-tree-analytics avl-tree-analytics.c avl-tree.h)
add_dependencies(avl-tree-analytics avl-tree)
target_link_libraries(avl-tree-analytics avl-tree)

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
  # Ajout d'un exécutable dépendant également de avl-tree.h
  add_executable(${TEST} ${SRC} avl-tree.h)
  # Précision de l'ordre de construction: le programme de test doit se faire
  # après la librairie
  add_dependencies(${TEST} avl-tree)
  # Assemblage du programme de test avec la librairie avl-tree
  target_link_libraries(${TEST} avl-tree)
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
