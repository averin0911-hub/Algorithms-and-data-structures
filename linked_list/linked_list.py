class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

    def get_data(self):
        return self.data
    def get_next(self):
        return self.next
    
    def set_data(self, new_data):
        self.data = new_data
    def set_next(self, new_next):
        self.next = new_next
    
    def __str__(self):
        return f'[{self.data}] -> {self.next}'


class LinkedList:
    def __init__(self):
        self.head = None

    def __str__(self):
        return str(self.head)

    def is_empty(self):
        return self.head == None

    def push_front(self, data):
        temp = Node(data)
        temp.set_next(self.head)
        self.head = temp

    def push_back(self, data):
        if self.is_empty():
            self.push_front(data)
        else:
            temp = Node(data)
            current = self.head
            while current.get_next() != None:
                current = current.get_next()
            current.set_next(temp)

    def find(self, x):
        current = self.head
        while current != None:
            if current.get_data() == x:
                return True
            current = current.get_next()
        return False

    def pop_front(self):
        if not self.is_empty():
            self.head = self.head.get_next()

    def remove(self, key):
        if self.find(key):
            previous = None
            current = self.head
            found = False
            while current != None and not found:
                if current.get_data() == key:
                    found = True
                else:
                    previous = current
                    current = current.get_next()
            if previous == None:
                self.pop_front()
            else:
                previous.set_next(current.get_next())

    def pop_back(self):
        if not self.is_empty():
            previous = None
            current = self.head
            while current.get_next() != None:
                previous = current
                current = current.get_next()
            if previous:
                previous.set_next(current.get_next())
            else:
                self.head = current.get_next()



    # Задания *********************************************************





    def task1_1(self, key):
        while (self.find(key)):
            self.remove(key)

    def task1_2(self, key, k):
        previous = None
        current = self.head
        n = 0
        while current != None:
            if n == k:
                temp = Node(key)
                temp.set_next(current)
                previous.set_next(temp)
                n = 0
            previous = current
            current = current.get_next()
            n += 1
        if n == k:
            temp = Node(key)
            temp.set_next(current)
            previous.set_next(temp)

    def task1_3(self):
        previous = None
        current = self.head
        future = self.head.get_next() if self.head != None else None

        while current != None:
            current.set_next(previous)
            previous = current
            current = future
            future = future.get_next() if future != None else None
        self.head = previous

    def task2_1(self, key):
        current = self.head
        while current != None:
            if current.get_data() == key:
                future = current.get_next()
                temp = Node(key)
                current.set_next(temp)
                temp.set_next(future)
                current = future
            else:
                current = current.get_next()

    def task2_2(self, k):
        if k == 1:
            self.head = None
        elif k > 1:
            previous = None
            current = self.head
            n = 1
            while current != None:
                if n == k:
                    current = current.get_next()
                    previous.set_next(current)
                    n = 0
                else:
                    previous = current
                    current = current.get_next()
                n += 1
    def task2_3(self):
        el = self.head
        while el != None:
            previous = el
            current = previous.get_next()
            while current != None:
                if current.get_data() == el.get_data():
                    current = current.get_next()
                    previous.set_next(current)
                else:
                    previous = current
                    current = current.get_next()
            el = el.get_next()

    def task3_1(self):
        previous = None
        current = self.head
        while current != None:
            if current.get_data() > 0:
                current = current.get_next()
                if previous == None:
                    self.head = current
                else:
                    previous.set_next(current)
            else:
                previous = current
                current = current.get_next()

    def task3_2(self, key):
        previous = None
        current = self.head
        n = 1
        while current != None:
            if n == 3:
                temp = Node(key)
                temp.set_next(current)
                previous.set_next(temp)
                n = 0
            previous = current
            current = current.get_next()
            n += 1

    def task3_3(self, k):
        start = self.head
        if start != None:
            n = 0
            while n != k:
                previous = start
                current = previous.get_next()

                if current == None:
                    break
                while current.get_next() != None:
                    previous = current
                    current = current.get_next()
                current.set_next(start)
                self.head = current
                previous.set_next(None)
                start = current
                n += 1


    def task4_1(self):
        current = self.head
        pos = LinkedList()
        neg = LinkedList()
        zero = LinkedList()
        result = LinkedList()
        while current != None:
            if current.get_data() > 0:
                pos.push_back(current.get_data())
            elif current.get_data() < 0:
                neg.push_back(current.get_data())
            else:
                zero.push_back(current.get_data())
            
            current = current.get_next()

        while not pos.is_empty():
            result.push_back(pos.head.get_data())
            pos.head = pos.head.get_next()

        while not neg.is_empty():
            result.push_back(neg.head.get_data())
            neg.head = neg.head.get_next()

        while not zero.is_empty():
            result.push_back(zero.head.get_data())
            zero.head = zero.head.get_next()


    def task4_2(self):
        begin = self.head
        previous = None
        current = begin
        if current != None:
            while current.get_next() != None:
                previous = current
                current = current.get_next()
            if previous != None and previous != begin:
                current.set_next(begin.get_next())
                previous.set_next(begin)
                begin.set_next(None)
                self.head = current
            elif previous == begin:
                temp = self.head
                self.head = current
                current.set_next(temp)
                temp.set_next(None)


    def task4_3(self):
        if not self.is_empty():
            previous = None
            current = self.head
            future = current.get_next()

            while current != None:
                if future == None:
                    break
                current.set_next(future.get_next())
                future.set_next(current)
                if previous == None:
                    self.head = future
                else:
                    previous.set_next(future)

                previous = current
                current = previous.get_next()
                future = current.get_next() if current != None else None

    def task5_1(self):
        if not self.is_empty():
            prev = None
            curr = self.head
            fut = curr.get_next()
            while curr != None:
                if curr.get_data() % 2 == 0:
                    if prev == None:
                        curr = fut
                        fut = curr.get_next() if curr != None else None
                        self.head = curr
                    else:
                        prev.set_next(fut)
                        curr = fut
                        fut = curr.get_next() if curr != None else None
                else:
                    prev = curr
                    curr = fut
                    fut = curr.get_next() if curr != None else None


    def task5_2(self, key, k):
        if not self.is_empty() and k > 0:
            curr = None
            fut = self.head
            n = 1
            if k == 1:
                temp = Node(key)
                curr = temp
                curr.set_next(fut)
                self.head = curr
            else:
                n += 1
            curr = fut
            fut = curr.get_next()
            while fut != None:
                if n == k:
                    temp = Node(key)
                    curr.set_next(temp)
                    temp.set_next(fut)
                    n = 0

                curr = fut
                fut = curr.get_next()
                n += 1

    def task5_3(self):
        if not self.is_empty():
            prev = None
            curr = self.head
            fut = curr.get_next()

            while curr != None:
                curr.set_next(prev)
                prev = curr
                curr = fut
                fut = curr.get_next() if curr != None else None
            self.head = prev



my_list = LinkedList()

ls = []
for i in ls:
    my_list.push_back(i)

print(my_list)

my_list.task5_3()
print(my_list)
