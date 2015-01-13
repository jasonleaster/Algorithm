"""
Code writer	:	EOF
Code date	:	2015.01.12
code file	:	stack.h
e-mail		:	jasonleaster@gmail.com

code purpose	:
	Stack is implemented in Python.

	If there is something wrong with my code, 
please touch me by e-mail. Thank you.

"""

class Stack() :

      S = []
      def __init__(self, arg = [0]):
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
	     self.S[0] -= 1
	  return self.S[self.S[0]] 

      def show_stack(self) :
	    print "stack status:",self.S[1 : self.S[0] + 1]
        
#------------------------------------------

input_num = [1,2,3,4,5]

stk = Stack(input_num)

print "initial status"
stk.show_stack()

stk.push(10)
stk.push(1)
stk.push(-1)
stk.push(0)

print " stk.push(10)" + \
      " stk.push(1)"  + \
      " stk.push(-1)" + \
      " stk.push(0)"

stk.show_stack()

print " stk.pop() " + \
      " stk.pop() " 

stk.pop()
stk.pop()
stk.show_stack()
