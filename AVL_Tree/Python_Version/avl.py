"""
Programmer  :   EOF
E-mail      :   jasonleaster@gmail.com
File        :   avl.py
Date        :   2015.07.25

"""
class Node() :
    def __init__(self, num):
        self.number         = num
        self.height         = 0
        self.parent         = None
        self.rightchild     = None
        self.leftchild      = None

    def height(self):
        return self.height

    def __str__(self):
        return str(self.number)



class AVL_Tree():

    """
        We initialize the AVL-tree object with two reserved data member
        @self.leaf and @self.root.
    """
    def __init__(self):
        self.leaf = Node(-1)
        self.leaf.parent     = self.leaf
        self.leaf.rightchild = self.leaf
        self.leaf.leftchild  = self.leaf

        self.root = self.leaf


    def height(self):
        return self.root.height()


    def insert_node(self, parent, node):

        rightchild = parent.rightchild
        leftchild  = parent.leftchild

        if parent is self.lear:
            parent = node
            parent.rightchild = self.leaf
            parent.leftchild  = self.leaf
        elif parent.number > node.number:
            """
                Insert @node into left sub-tree
            """
            leftchild = self.insert_node(leftchild, node)

            if leftchild.height() > rightchild.height():
                parent.height = leftchild.height() + 1
            else:
                parent.height = rightchild.height() + 1

            if abs(rightchild.heigt() - leftchild.height()) == 2:
                if   leftchild.number > node.number:
                    parent = self.single_rotation_with_right(parent)
                elif leftchild.number < node.number:
                    parent = self.double_rotation_with_right(parent)

        elif parent.number < node.number:
            """
                Insert @node into right sub-tree
            """
            rightchild = self.insert_node(rightchild, node)

            if leftchild.height() > rightchild.height():
                parent.height = leftchild.height() + 1
            else:
                parent.height = rightchild.height() + 1

            if abs(rightchild.heigt() - leftchild.height()) == 2:
                if   rightchild.number > node.number:
                    parent = self.single_rotation_with_right(parent)
                elif rightchild.number < node.number:
                    parent = self.double_rotation_with_right(parent)

        return parent


    def single_rotation_with_right(self, pivot):
        tmp_node = pivot.leftchild
        pivot.leftchild = tmp_node.rightchild
        tmp_node.rightchild = pivot

        """
            set the height of @pivot as the bigger one in the two
            sub-tree and plus 1.
        """
        if(pivot.rightchild.height() > pivot.leftchild.height()):
            pivot.height = pivot.rightchild.height() + 1
        else:
            pivot.height = pivot.leftchild.height()  + 1

        if(tmp_node.rightchild.height() > tmp_node.leftchild.height()):
            tmp_node.height = tmp_node.rightchild.height() + 1
        else:
            tmp_node.height = tmp_node.leftchild.height()  + 1

        return tmp_node

    def single_rotation_with_left (self, pivot):
        tmp_node = pivot.rigtchild
        pivot.rightchild = tmp_node.leftchild
        tmp_node.leftchild = pivot
        
        if(pivot.rightchild.height() > pivot.leftchild.height()):
            pivot.height = pivot.rightchild.height() + 1
        else:
            pivot.height = pivot.leftchild.height()  + 1

        if(tmp_node.rightchild.height() > tmp_node.leftchild.height()):
            tmp_node.height = tmp_node.rightchild.height() + 1
        else:
            tmp_node.height = tmp_node.leftchild.height()  + 1

        return tmp_node

    def double_rotation_with_right(self, pivot):
        pivot = self.single_rotation_with_right(pivot)

        return single_rotation_with_left(pivot)

    def double_rotation_with_left (self, pivot):
        pivot = self.single_rotation_with_left(pivot)

        return single_rotation_with_right(pivot)

    """
        Function @show() base on recursion.

        Here we print out the element from
        small to big according to its value.

        Firstly, we walk through the left tree.
        Once the leftchild of current node is empty,
        we print the value of the current node.
        In this situation, its value is the smallest
        one in current sub-tree.

        Next step, we walk through the rightchild.
        But we shouldn't show the value of current node
        if we find the rightchild is empty.
        Becasue don't forget that what we want is that
        print out he element from small to big.

        If we entry the rightchild, we also should walk
        through the left sub-tree of rightchild.
    """
    def show(self, tmp_node):
        if(tmp_node.leftchild is not None):
            self.show(tmp_node.leftchild)

        print(tmp_node)

        if(tmp_node.rightchild is not None):
            self.show(tmp_node.rightchild)

    def __str__(self):
        self.show(self.root)



#----------------- Code below there used for testing ------------------

array = [2, 4, 23, 15, 98, 34, 66, 75, 41, 17]

avl_tree = AVL_Tree()

for iter in array:
    avl_tree.insert_node(avl_tree.root, Node(iter))

print(avl_tree)   
