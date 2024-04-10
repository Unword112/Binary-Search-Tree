all: main.o BinarySearchTree.o ../BinaryTreeNode/BinaryTreeNode.o
	g++ main.o BinarySearchTree.o ../BinaryTreeNode/BinaryTreeNode.o -o bst

main.o: main.cpp
	g++ -c main.cpp -o main.o

BinarySearchTree.o: BinarySearchTree.cpp
	g++ -c BinarySearchTree.cpp -o BinarySearchTree.o

../BinaryTreeNode/BinaryTreeNode.o: ../BinaryTreeNode/BinaryTreeNode.cpp
	g++ -c ../BinaryTreeNode/BinaryTreeNode.cpp -o ../BinaryTreeNode/BinaryTreeNode.o

clean:
	rm -f *.o bst