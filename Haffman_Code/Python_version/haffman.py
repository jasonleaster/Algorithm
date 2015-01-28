"""
Code writer : EOF
Code file   : haffman.py
Code date   : 2015.01.28
e-mail      : jasonleaster@gmail.com

Code description:

    Here is a implementation of Haffman-Code
in Python.

"""

class node() :
    def __init__(self,num) :
        self.right = None
        self.left  = None
        self.key   = num

class haffman_tree():

    def __init__(self, array) :
        self.forest = []
        for i in range(0, len(array)) :
            self.forest += [node(array[i])]

        self.build()

    def small_tree(self) :
        smallest_tree = self.forest[0]
        location = 0
        for i in range(1, len(self.forest)) :
            if self.forest[i].key < smallest_tree.key :
                location = i
        return location

    def delete_root(self, x) :
        for i in range(0, len(self.forest)) :
            if x.key is self.forest[i].key :
               del self.forest[i]
               return

    def build(self) :
        while len(self.forest) is not 1 :
            small_tree_1 = self.forest[self.small_tree()]
	    self.delete_root(small_tree_1)
	    small_tree_2 = self.forest[self.small_tree()]
	    self.delete_root(small_tree_2)

	    tmp_node = node(small_tree_1.key + small_tree_2.key)
	    tmp_node.right = small_tree_1
	    tmp_node.left  = small_tree_2
	    self.forest += [tmp_node]
        self.root = self.forest[0]

        self.coding(self.root,'')

    def coding(self, node, path) :
        if node.right is None and node.left is None :
            print path, "is the haffman code of", node.key
            return
        else :
            self.coding(node.right, path + '1')
            self.coding(node.left,  path + '0')
            
#------------------------------------------------------

tree = haffman_tree(['a','b','c','d','e','f','g','h'])

