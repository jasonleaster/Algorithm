"""
Code writer : EOF
Code date   : 2015.01.29
Code file   : rbt.py
e-mail      : jasonleaster@163.com

Code description :

    Here is a implementation of red-black-tree in Python.
If you find something wrong with my code, please touch me
by e-mail. Thank you!

"""

class node() :
    def __init__(self, num, color) :
        self.right  = None
        self.left   = None
        self.parent = None
        self.color  = color
        self.key    = num

class Red_Black_Tree() :
    def __init__(self, array) :
        self.nil  = node(0, 'black')
        self.root = self.nil

        for i in range(0,len(array)) :
            self.rb_insert(array[i])


    def rb_search(node, num) :
        if node.key > num :
            return rb_search(node.left, num);
        elif node.key < num :
            return rb_search(node.right, num);
        else :
            return node

    def tree_mininum(self, x) :
        while x.left != self.nil :
            x = x.left
        return x

    def tree_successor(self, x) :
        if x.right != self.nil :
            return self.tree_mininum(x.right)
       
        y = x.parent
        while y != self.nil and x == y.right :
            x = y
            y = y.parent
        return y    

    def left_rotate(self, x) :
        y = x.right
        x.right = y.left

        if y.left is not self.nil :
            y.left.parent = x

        if x.parent is self.nil :
           self.root = y
        elif x is x.parent.left :
             x.parent.left = y
        else :
             x.parent.right = y

        y.left = x
        x.parent = y

    def right_rotate(self, x) :
        y = x.left

        if y.right is self.nil :
            y.right.parent = x
        if x.parent is self.nil :
            self.root = y
        elif x is x.parent.left :
             x.parent.left = y
        else :
             x.parent.right = y

        y.right = x
        x.parent = y


    def rb_insert(self, num) :
        z = node(num, 'red')
        z.right  = self.nil
        z.left   = self.nil
        z.parent = self.nil

        y = self.nil
        x = self.root

        while x != self.nil :
            y = x
            if z.key < x.key :
                x = x.left
            else :
                x = x.right

        z.parent = y

        if y is self.nil :
            self.root = z
        elif z.key < y.key :
            y.left = z
        else :
            y.right = z

        z.left  = self.nil
        z.right = self.nil
        z.color = 'red'
        self.rb_insert_fixup(z)


    def rb_insert_fixup(self, z) :
        while z.parent.color is 'red' :
            if z.parent is z.parent.parent.left :
               y = z.parent.parent.right # @y is the uncle of @z
               if y.color is 'red' :     # $case 1
                   z.parent.color  = 'black'
                   y.color         = 'black'
                   z.parent.parent = 'red'
                   z = z.parent.parent
               else : # here is the color of uncle-node @y is 'black'
                   if z is z.parent.right : # $case 2
                       z = z.parent
                       self.left_rotate(z)
                   z.parent.color = 'black' # $case 3
                   z.parent.parent.color = 'red'
                   self.right_rotate(z.parent.parent)
            else : # In this situation, p[z] == right[p[p[z]]]
                 y = z.parent.parent.left
                 if y.color is 'red' :
                     z.parent.color  = 'black'
                     y.color         = 'black'
                     z.parent.parent = 'red'
                     z = z.parent.parent
                 else :
                     if z is z.parent.left :
                         z = z.parent
                         self.right_rotate(z)
                     z.parent.color = 'black'
                     z.parent.parent.color = 'red'
                     self.left_rotate(z.parent.parent)

        self.root.color = 'black'


    def rb_delete(self, num) :
        z = self.rb_search(self.root, num)
        if z.left != self.nil or z.right != self.nil :
            y = z
        else :
            y = self.tree_successor(z)

        if y.self != self.nil :
            x = y.left
        else :
            x = y.right

        x.parent = y.parent

        if y.parent is self.nil :
            self.root = x
        elif y.parent.left is y :
            y.parent.left  = x
        else :
            y.parent.right = x

        if y != z :
            z.key    = y.key
            z.right  = y.right
            z.left   = y.left
            z.parent = y.parent
            z.color  = y.color

        if y.color is 'black' :
            rb_delete_fixup(self, x)

        del z


    def rb_delete_fixup(self, x) :
        while x != self.root and x.color is 'black' :

            if x.parent.left is x :
                w = x.parent.right
                if w.color is 'red' :
                    w.color = 'black'
                    self.left_rotate(self, x.parent)
                    w = x.parent.right

                if w.left.color is 'black' and w.right.color is 'black' :
                    w.color = 'red'
                    x = x.parent
                elif w.right.color is 'black' :
                    w.left.color = 'black'
                    w.color = 'red'
                    self.right_rotate(self, w)
                    w = x.parent.right

                w.color        = x.parent.color
                x.parent.color = 'black'
                w.right.color  = 'black'
                self.right_rotate(self, x.parent)
                x = self.root

            else : # x.parent.right == x
                w = x.parent.left
                if w.color is 'red' :
                    w.color = 'black'
                    self.right_rotate(self, x.parent)
                    w = x.parent.left

                if w.left.color is 'black' and w.right.color is 'black' :
                    w.color = 'red'
                    x = x.parent
                elif w.left.color is 'black' :
                    w.right.color = 'black'
                    w.color = 'red'
                    self.left_rotate(self, w)
                    w = x.parent.left

        x.color = 'black'

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

            line   = [  ' ' * left_pos + label + 
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


#-----------  for testing ------------------------------

array = [1,2,4,5,7,8,11,14,15]

my_little_tree = Red_Black_Tree(array)

print my_little_tree
