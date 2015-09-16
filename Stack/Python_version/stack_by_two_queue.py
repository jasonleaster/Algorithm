class Stack():
    def __init__(self, arg = []):
        self.Q1 = arg
        self.Q2 = []

    def stack_empty(self):
        if len(self.Q1) == 0 and len(self.Q2) == 0:
            return True
        else:
            return False

    def push(self, x):
        if self.stack_empty() is True:
            self.Q1.append(x)
        elif len(self.Q1) != 0:
            self.Q1.append(x)
        else:
            self.Q2.append(x)

    def pop(self):

        val = None

        if self.stack_empty() == True:
            print "underflow"

        elif len(self.Q1) != 0:
            while len(self.Q1) != 0:
                if len(self.Q1) == 1:
                    val = self.Q1[0]
                else:
                    self.Q2.append(self.Q1[0])

                self.Q1.remove(self.Q1[0])
                
        else:
            while len(self.Q2) != 0:
                if len(self.Q2) == 1:
                    val = self.Q2[0]
                else:
                    self.Q1.append(self.Q2[0])

                self.Q2.remove(self.Q2[0])


        return val

    def show_stack(self):
        print "Queue 1 :", self.Q1
        print "Queue 2 :", self.Q2
            
#-----------------------
input_num = ['a', 'b', 'c']

stk = Stack(input_num)

stk.pop()
stk.show_stack()
stk.pop()
stk.show_stack()
stk.push('d')
stk.show_stack()
stk.pop()
stk.show_stack()
