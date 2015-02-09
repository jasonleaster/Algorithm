"""
Code writer : EOF
Code date   : 2015.02.08
Code file   : Queue_by_two_stack.py
e-mail      : jasonleaster@163.com

Code description :
    How to implement a queue by two stack.
"""

class Stack() :

      S = []
      def __init__(self, arg = []):
          self.S = [len(arg)] + arg

      def stack_empty(self) :
          if self.S[0] == 0 :
             return True
          else :
             return False

      def push(self,x) :

          self.S[0] += 1

          if len(self.S) > self.S[0] :
             self.S[self.S[0]] = x
          else :
                self.S = self.S + [x]

          return self.S

      def pop(self) :
          if self.stack_empty() == True :
             print "underflow"
          else :
                temp = self.S[0]
                self.S[0] -= 1
                return self.S[temp] 

      def show_stack(self) :
          print "stack status:",self.S[1 : self.S[0] + 1]

#---------------------------------------------------------------

class Queue() :

    def __init__(self, argv = []) :
        self.s_1 = Stack()
        self.s_2 = Stack()

        for i in range(0, len(argv)) :
            self.s_1.push(argv[i])

    def is_empty(self) :
        if  self.s_1.stack_empty() is True and \
            self.s_2.stack_empty() is True :
            return True
        else :
            return False

    def enqueue(self, num) :
        self.s_1.push(num)

    def dequeue(self) :
        if self.s_2.stack_empty() is True :
            while self.s_1.stack_empty() is False :
                self.s_2.push(self.s_1.pop())

        if self.is_empty() is False :
            return self.s_2.pop()

#---------------------------------------------------------------

"""
Code below this is writed for testing :)
"""


Q = Queue([1,2,3,4,5])

Q.enqueue(100)

while Q.is_empty() is False :
    print Q.dequeue(),

    



