"""
code writer	:	EOF
code date	:	2015.01.13
code file	:	Queue.py
e-mail		:	jasonleaster@gmail.com

Code description:
           Here is a implementation for ADT-Queue in Python.
"""

class queue() :
      Q = []
      ihead  = -1 # head index
      itail  = -1 # tail index

      def __init__(self, arg = [0]) :
          if len(arg) == 0 :
             arg = [0]

          self.Q = arg
          self.ihead  = 0
          self.itail  = 0

      def enqueue(self, num) :
              self.Q +=  [num]
              self.itail = len(self.Q)


      def dequeue(self) :
             if self.itail == 0 :
                print "Waring ! queue is empty NOW"
                return

             del self.Q[self.ihead]
             self.ihead  = 0
             self.itail -= 1


      def show_queue(self) :
              print self.Q

#-----------------start to test our ADT below this line-----------------

tmp = queue([1,2,3,4,5])

tmp.show_queue()

print "tmp.enqueue(100) tmp.enqueue(200)"

tmp.enqueue(100)
tmp.enqueue(200)

tmp.show_queue()

for i in range(1,9) :
   tmp.dequeue()

tmp.show_queue()
