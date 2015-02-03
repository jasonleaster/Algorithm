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
into the tree is just only one but no more than two times.

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
          z = self.search(self.root, num)
          if z.left == None or z.right == None :
              y = z
          else :
              y = self.tree_successor(z)

          if y.left != None :
              x = y.left
          else :
              x = y.right

          if x != None :
              x.parent = y.parent
          if y.parent == None :
              self.root = x
          elif y == y.parent.left :
              y.parent.left = x
          else :
              y.parent.right = x

          if y != z :
              # copy y's satelllite data into z
              z.number = y.number

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

      def tree_predecessor(self, x) :
          if x.left != None :
              return self.tree_maxinum(x.left)

          y = x.parent
          while y != None and x == y.left :
              x = y.left
              y = y.parent

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

      def __str__(self):

          def recurse(node) :
               if node is None:
                   return [], 0, 0
               else :
                   left_lines, left_pos, left_width = recurse(node.left)
                   right_lines, right_pos, right_width = recurse(node.right)

		       label = str(node.number)

		       middle = max(right_pos + left_width - left_pos +1, len(label), 2)
		       pos    = left_pos + middle//2
		       width  = left_pos + middle + right_width - right_pos

                       while len(left_lines) < len(right_lines) :
                           left_lines.append(' ' * left_width)
                       while len(right_lines) < len(left_lines) :
                           right_lines.append(' ' * right_width)

		       line   = [' ' * left_pos + label + ' ' * (right_width-right_pos + 1),
		             ' ' * left_pos + '/' + 
                                 ' ' * (middle-2) + '\\' +
		             ' ' * (right_width - right_pos)
                                ] + \
                                [
		        	    left_line + 
		        	    ' ' * (width - left_width - right_width) +
		        	    right_line 
		        	    for left_line, right_line 
		        	    in zip(left_lines, right_lines)
                                ]

		          if node is self.root :
		              return line
		          else :
		              return line, pos, width

          if self.root is None :
               return '<Empty tree>'

          output = recurse(self.root)
          for i in range(1, len(output)-2) :
              output[0] += '\n' + output[i]

          return output[0]+'\n'

class new_node() :

      def __init__(self, num = -1) :
          self.number = num
          self.right  = None
          self.left   = None
          self.parent = None

#--------------testing code----------------
A = [20,4,6,3,2,1,7,8,9,23,24,21,89,34]
my_bst = BST()

for i in range(0,len(A)-1) :
    my_bst.insert(A[i])

print "original tree"
print my_bst

my_bst.delete(1)

print "after deleting 1"
print my_bst

my_bst.delete(20)

print "after deleting 20"
print my_bst

