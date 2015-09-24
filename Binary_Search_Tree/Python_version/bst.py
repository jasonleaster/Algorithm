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
class TreeNode() :
    def __init__(self, num = -1) :
      self.val = num
      self.right  = None
      self.left   = None


class BST() :
    def __init__(self) :
        self.root   = None

    def insert(self, num) :
        if self.root == None :
            self.root = TreeNode(num)
        else :
            tmp_node = self.root
            par_node = None # parent of the inserting node

            #Just for searching the location where could be inserted
            while tmp_node != None :
                if tmp_node.val > num :
                    par_node = tmp_node
                    tmp_node = tmp_node.left
                else :
                    par_node = tmp_node
                    tmp_node = tmp_node.right

            # After while loop, we found that location which's parent
            # is @par_node
            if par_node.val > num :
                par_node.left  = TreeNode(num)
                par_node.left.right  = None
                par_node.left.left   = None
                return par_node.left
            else :
                par_node.right = TreeNode(num)
                par_node.right.right  = None
                par_node.right.left   = None
                return par_node.right


    def search(self, node, num) :
        if node.val == num  or node == None:
            return node
        elif node.val > num :
            return self.search(node.left, num)
        elif node.val < num :
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
            z.val = y.val

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
      print " node ",node.val,

      if node.right != None :
         print " right child ", node.right.val,
      else :
         print "None",
      if node.left != None :
         print " left child ", node.left.val
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

                label = str(node.val)
                middle = max(right_pos + left_width - left_pos +1,
                        len(label), 2)
                pos    = left_pos + middle//2
                width  = left_pos + middle + right_width - right_pos

                while len(left_lines) < len(right_lines) :
                    left_lines.append(' ' * left_width)
                while len(right_lines) < len(left_lines) :
                    right_lines.append(' ' * right_width)

                line   = [' ' * left_pos + label + 
                          ' ' * (right_width-right_pos + 1),
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



    """
        There are four different types of iterate function
    of Binary Search Tree. @pre_traveller, @mid_traveller,
    @suf_traveller

    Recursive definition
    """
    def pre_traveller(self, node):
        if node == None :
            return None

        print node.val
        self.pre_traveller(node.left)
        self.pre_traveller(node.right)

    def mid_traveller(self, node):
        if node == None:
            return None

        self.mid_traveller(node.left)
        print node.val
        self.mid_traveller(node.right)

    def suf_traveller(self, node):
        if node == None:
            return None

        self.suf_traveller(node.left)
        self.suf_traveller(node.right)
        print node.val


    """
    Iterately implementation

    Given a binary tree, return the preorder traversal of 
    its nodes' values.
    """
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root is None:
            return []

        stack = [root]
        ret = []
        
        while len(stack) != 0:
            node = stack.pop()
            ret.append(node.val)
            if node.right is not None:
                stack.append(node.right)
            if node.left is not None:
                stack.append(node.left)
                
        return ret

    """
    Given a binary tree, return the inorder traversal 
    of its nodes' values.
    """
    def inorderTraversal(self, root):
        res, stack = [], []
        while True:
            while root:
                stack.append(root)
                root = root.left
            if not stack:
                return res
            node = stack.pop()
            res.append(node.val)
            root = node.right

    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        res   = []
        stack = [root]
        
        while len(stack):
            node = stack.pop()
            if node:
                res.append(node.val)
                stack.append(node.left)
                stack.append(node.right)
                
        return res[::-1]

    """
    Given a binary tree, return the level order traversal of 
    its nodes' values. (ie, from left to right, level by level).
    """
    def levelOrder(self, node):
        if node is None:
            return []

        stack = [node]
        length = len(stack)
        ret = []
        j = 0

        while length != 0:
            ret.append([])
            for i in range(0, length):
                
                ret[j].append(stack[i].val)
                if stack[i].left != None:

                    stack.append(stack[i].left)
                if stack[i].right != None:
                    stack.append(stack[i].right)

            for i in range(0, length):
                stack.remove(stack[0])

            length = len(stack)
            j += 1

        return ret

    def isValidBST(self, root):
        A = []
        A = self.mid_traveller(self.root)

        for i in range(0, len(A)):
            if A[i-1] >= A[i]:
                return False

        return True


    """
    Given a binary tree, find its maxinum depth.

    type root: TreeNode
    rtype: int
    """
    def maxDepth(self, root):
        if root is None:
            return 0
        return max(self.maxDepth(root.left), \
                self.maxDepth(root.right)) + 1


    """
    Given two binary trees, write a function 
    to check if they are equal or not.

    Two binary trees are considered equal if they
    are structurally identical and the nodes have the same value.
    """
    def isSameTree(self, p, q):
        if p is None and q is None:
            return True
        if p is None or q is None:
            return False

        if p.val == q.val:
            b1 = self.isSameTree(p.right, q.right)
            b2 = self.isSameTree(p.left , q.left)
            if b1 and b2:
                return True
            else:
                return False
        else:
            return False
            
    def invertTree(self, root):
        if root is None:
            return
        
        root.left, root.right = root.right, root.left
        self.invertTree(root.child)
        self.invertTree(root.child)
        return node

    """
    Given a binary search tree (BST), 
    find the lowest common ancestor (LCA) of 
    two given nodes in the BST.
    """
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if p.val < q.val:
            lowBound = p
            upBound = q
        else:
            lowBound = q
            upBound = p
            
        return self.helper_lowestCommonAncestor(root, lowBound, upBound)
        
    def helper_lowestCommonAncestor(self, root,  low, up):
        if root.val >= low.val and root.val <= up.val:
            return root
        else:
            if root.val > low.val:
                commonAncestor = self.helper(root.left, low, up)
            else:
                commonAncestor = self.helper(root.right, low, up)
                
        return commonAncestor

    """
    Given a binary tree, determine if it is height-balanced.

    For this problem, a height-balanced binary tree is defined 
    as a binary tree in which the depth of the two subtrees of 
    every node never differ by more than 1.
    """
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root is None:
            return True
        
        b1 = self.isBalanced(root.right)
        b2 = self.isBalanced(root.left)
       
        if b1 is True and b2 is True:
            if abs(self.height(root.right) - self.height(root.left)) <= 1:
                return True
                
        return False
    
    def height(self, root):
        if root is None:
            return 0
            
        return max(self.height(root.right), self.height(root.left)) + 1

    """
    Given a binary tree, check whether it is a mirror of 
    itself (ie, symmetric around its center).
    """
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root is None:
            return True
        else:
            return self.helperIsSymmetric(root.right, root.left)
            
        
    def helperIsSymmetric(self, p, q):
        if p is None and q is None:
            return True
        if p is None or q is None:
            return False
        
        return p.val == q.val and self.helperIsSymmetric(p.right, q.left) \
                              and self.helperIsSymmetric(p.left, q.right)


    """
    Given a binary tree, find its minimum depth.

    The minimum depth is the number of nodes along the 
    shortest path from the root node down to the nearest leaf node.
    """
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        
        if None in [root.left, root.right]:
            return max(self.minDepth(root.left), \
                    self.minDepth(root.right)) + 1
        else:
            return min(self.minDepth(root.left), \
                    self.minDepth(root.right)) + 1
             

    """
    Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

    Consider f_i:

    choose 1 as the root, we have 0 node for the left tree, i-1 for the right;
    choose 2 as the root, we have 1 node for the left tree, i-2 for the right;
    ...
    choose i as the root, we have i-1 nodes for the left tree, 0 for the right.
    Therefore, the recursive solution is fi = \sum{j=0}^{i-1} fj f{i-j-1}
    """
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        table = [0 for i in range(0, n+1)]
        table[0] = 1
        
        for i in range(1, n+1):
            counter = 0
            for j in range(0, i):
                counter += table[j] * table[i - j - 1]
                
            table[i] = counter
            
        return table[n]

    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        return self.helperSortedArrayToBST(nums, 0, len(nums)-1)
    
    def helperSortedArrayToBST(self, nums, start, end):
        if start > end:
            return None
            
        middle = int((start + end)/2)
        
        root = TreeNode(nums[middle])
        root.left  = self.helper(nums, start, middle-1) 
        root.right = self.helper(nums, middle + 1, end)
        
        return root

    """
    Given a binary tree, flatten it to a linked list in-place.
    """
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        if not root:
            return root
            
        if root.right is None and root.left is None:
            return root
            
        right = root.right
        left  = root.left
        end   = root
        
        if left:
            root.left = None
            root.right = left
            end = self.flatten(left)
            
        if right:
            end.right = right
            end = self.flatten(right)
            
        return end

    """
    Given a singly linked list where elements are 
    sorted in ascending order, convert it to a height balanced BST.
    """
    def sortedListToBST(self, head):
        current, length = head, 0

        # get length of list
        while current:
            current = current.next
            length += 1

        # use class variable to store head so that 
        # it can be modified by sortedListToBSTHelper
        self.node = head
        return self.sortedListToBSTHelper(0, length-1)

    def sortedListToBSTHelper(self, start, end):
        if start > end:
            return None

        middle = (start + end) / 2
        left = self.sortedListToBSTHelper(start, middle-1)
        parent = TreeNode(self.node.val)
        parent.left = left
        self.node = self.node.next
        parent.right = self.sortedListToBSTHelper(middle+1, end)

        return parent

    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if root == None or root == p or root == q:
            return root
        
        Parent1 = self.lowestCommonAncestor(root.left, p, q)
        Parent2 = self.lowestCommonAncestor(root.right,p, q)
        
        if Parent1 and Parent2:
            return root
        else:
            if Parent1:
                return Parent1
            else:
                return Parent2

    """
    Given inorder and postorder traversal of a tree, 
    construct the binary tree.

    Note:
    You may assume that duplicates do not exist in the tree.
    """
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        if len(inorder) == 0 or len(postorder) == 0:
            return None
        
        index = inorder.index(postorder.pop())
        root = TreeNode(inorder[index])
        
        # You HAVE TO build right sub-tree first, 
        # otherwise you will get wrong answer
        # because you poped the last element of @postorder before here.
        root.right = self.buildTree(inorder[index+1:], postorder)
        root.left  = self.buildTree(inorder[0:index] , postorder)
        
        return root


    """
    Given preorder and inorder traversal of a tree,
    construct the binary tree.

    Note:
    You may assume that duplicates do not exist in the tree.
    """
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if len(preorder) == 0 or len(inorder) == 0:
            return None
            
        index = inorder.index(preorder.pop(0))
        root = TreeNode(inorder[index])

        #attention here, not index-1, but index
        root.left = self.buildTree(preorder, inorder[0:index]) 
        root.right = self.buildTree(preorder, inorder[index+1:])
        
        return root





#--------------testing code----------------
#A = [20,4,6,3,2,1,7,8,9,23,24,21,89,34]
#A = [4,2,7,1,3,6,9]
A = [10, 6, 14, 4, 8, 12, 16]
my_bst = BST()

for i in range(0,len(A)) :
    my_bst.insert(A[i])

print "original tree"
print my_bst

"""
my_bst.delete(1)

print "after deleting 1"
print my_bst

my_bst.delete(20)

print "after deleting 20"
print my_bst
"""
"""
print "show the invertTree"
my_bst.invertTree(my_bst.root)
print my_bst
"""
"""
#my_bst.show(my_bst.root)
print "pre_traveller"
my_bst.pre_traveller(my_bst.root)
print "mid_traveller"
my_bst.mid_traveller(my_bst.root)
print "suf_traveller"
my_bst.suf_traveller(my_bst.root)
"""

print my_bst.levelOrder(my_bst.root)
