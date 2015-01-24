"""
Code writer : EOF
Code date   : 2015.01.16
Code file   : bst.py
e-mail      : jasonleaster@gmail.com

Code description:
        Here is a implementation for Binary search tree(BST)
which is coded by Python.

ATTENTION: Binary search tree do not allow the inputed data 
which have the same value! Make sure that every data you insert
into the tree is just only one.

        If there is something wrong with my code, please touch
me by e-mail. Thank you!
"""

class BST() :

      def __init__(self) :
          self.root   = None


      def insert(self, num) :
          if self.root == None :
              self.root = new_node(num)
          else :
              tmp_node = self.root
              par_node = None

              #Just for searching the location where could be inserted
              while tmp_node != None :
                    if tmp_node.number > num :
		       par_node = tmp_node
                       tmp_node = tmp_node.left
                    else :
                       par_node = tmp_node
                       tmp_node = tmp_node.right

              # After while loop, we found that location which's parent
              # is @par_node
              if par_node.number > num :
                  par_node.left  = new_node(num)
                  par_node.left.parent = par_node
                  par_node.left.right  = None
                  par_node.left.left   = None
                  return par_node.left
              else :
                  par_node.right = new_node(num)
                  par_node.right.parent = par_node
                  par_node.right.right  = None
                  par_node.right.left   = None
                  return par_node.right


      def search(self, node, num) :
          if node.number == num  or node == None:
              return node
          elif node.number > num :
              return self.search(node.left, num)
          elif node.number < num :
              return self.search(node.right, num)


      def delete(self, num) :
          tmp_node = self.search(self.root, num)

          if tmp_node == None :
              print "There isn't any node which's value is %d" % num

          if tmp_node.left == None and tmp_node.right == None :
             if tmp_node.parent.number > tmp_node.number :
                  tmp_node.parent.left  = None
             elif tmp_node.parent.number < tmp_node.number :
                  tmp_node.parent.right = None
             del tmp_node 

          elif tmp_node.left == None and tmp_node.right != None :
             if tmp_node.parent.number > tmp_node.number :
                 tmp_node.parent.left  = tmp_node.right
             elif tmp_node.parent.number < tmp_node.number :
                 tmp_node.parent.right = tmp_node.right

             tmp_node.right.parent = tmp_node.parent
             del tmp_node 
          
          elif tmp_node.left != None and tmp_node.right == None :
             if tmp_node.parent.number > tmp_node.number :
                 tmp_node.parent.left  = tmp_node.left
             elif tmp_node.parent.number < tmp_node.number :
                 tmp_node.parent.right = tmp_node.left

             tmp_node.left.parent = tmp_node.parent
             del tmp_node 

          elif tmp_node.left != None and tmp_node.right != None :
              scsr = self.tree_successor(tmp_node) # @scsr is successor of node @tmp_node

              if scsr != None and scsr.right != None :
                 scsr.parent.left = scsr.right
                 scsr.right.parent = scsr.parent

              if tmp_node.parent != None :
                  if tmp_node.parent.right == tmp_node :
                      tmp_node.parent.right = scsr
                  elif tmp_node.parent.left  == tmp_node :
                      tmp_node.parent.left  = scsr
              else : # the node we are trying to delete is root
                  scsr.left = tmp_node.left
                  scsr.parent = tmp_node.parent
                  del tmp_node
                  return 

              scsr.parent = tmp_node.parent
              scsr.right  = tmp_node.right
              scsr.left   = tmp_node.left
              del tmp_node 


      def tree_mininum(self, x) :
          while x.left != None :
              x = x.left
          return x


      def tree_maxinum(self, x) :
          while x.right != None :
              x = x.right
          return x

      def tree_successor(self, x) :
          if x.right != None :
              return self.tree_mininum(x.right)
         
          y = x.parent
          while y != None and x == y.right :
              x = y
              y = y.parent
          return y    

      def show(self, node) :
          if node == None :
              return None
          self.show(node.left)
          print " node ",node.number,

          if node.right != None :
             print " right child ", node.right.number,
          else :
             print "None",
          if node.left != None :
             print " left child ", node.left.number
          else :
             print "None"
          self.show(node.right)

class new_node() :

      def __init__(self, num = -1) :
          self.number = num
          self.right  = None
          self.left   = None
          self.parent = None

#--------------testing code----------------
A = [5,4,6,3,2,1,7,8,9]
my_bst = BST()

for i in range(0,len(A)-1) :
    my_bst.insert(A[i])

print "original tree"
my_bst.show(my_bst.root)
print 

'''my_bst.delete(5)
print "after deleting 5"
my_bst.show(my_bst.root)'''

