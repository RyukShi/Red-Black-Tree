# Red-Black-Tree
Implémentation d'un arbre bicolore (arbre rouge-noir) en langage C  
Implémentation d'un arbre AVL en langage C  

## BUILD (Debug mode)

### 1 - Create directories
```sh
mkdir debug tmp && cd debug && mkdir analytics avltree rbtree
```
### 2 - Compilation
```sh
cd analytics/ && cmake ../../src/analytics -DCMAKE_INSTALL_PREFIX=../../tmp -DCMAKE_BUILD_TYPE=Debug && make && make install
```
```sh
cd ../avltree && cmake ../../src/avltree -DCMAKE_INSTALL_PREFIX=../../tmp -DCMAKE_BUILD_TYPE=Debug && make && make install
```
```sh
cd ../rbtree && cmake ../../src/rbtree -DCMAKE_INSTALL_PREFIX=../../tmp -DCMAKE_BUILD_TYPE=Debug && make && make install
```

## UNIT TESTS

Execute the command below to execute unit tests and valgrind tests
```sh
make test
```

## ANALYTICS

Execution time for red black tree execute this command
```sh
./red-black-tree-analytics
```

Execution time for avl tree execute this command
```sh
./avl-tree-analytics
```
