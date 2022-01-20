# Red-Black-Tree
Implémentation d'un arbre bicolore (arbre rouge-noir) en langage C
Implémentation d'un arbre AVL en langage C

# BUILD 

1 - mkdir debug tmp && cd debug && mkdir analytics avltree rbtree
2 - cd analytics/ && cmake ../../src/analytics -DCMAKE_INSTALL_PREFIX=../../tmp -DCMAKE_BUILD_TYPE=Debug && make && make install
3 - cd ../avltree && cmake ../../src/avltree -DCMAKE_INSTALL_PREFIX=../../tmp -DCMAKE_BUILD_TYPE=Debug && make && make install
4 - cd ../rbtree && cmake ../../src/rbtree -DCMAKE_INSTALL_PREFIX=../../tmp -DCMAKE_BUILD_TYPE=Debug && make && make install

# TESTS

execute "make test" to execute unit tests and valgrind tests

# ANALYTICS

Execution time for red black tree : execute ./red-black-tree-analytics

Execution time for avl tree : execute ./avl-tree-analytics
