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

    
    def task6_1(self):
        if self.is_empty() == False:
            prev = None
            curr = self.head
            while curr != None:
                if prev == None:
                    prev = Node(curr.get_data())
                    prev.set_next(curr)
                    self.head = prev
                    prev = curr
                    curr = prev.get_next()
                else:
                    temp = Node(curr.get_data())
                    prev.set_next(temp)
                    temp.set_next(curr)
                    prev = curr
                    curr = prev.get_next()

    def task6_1_2(self):
        curr = self.head
        res = LinkedList()
        while curr != None:
            res.push_back(curr.get_data())
            res.push_back(curr.get_data())
            curr = curr.get_next()
        self.head = res.head

    def task6_2(self, k, l):
        n = 1
        prev =None
        curr = self.head
        while n != l and curr != None:
            if k < n < l:
                if prev == None:
                    curr = curr.get_next()
                    self.head = curr
                else:
                    curr = curr.get_next()
                    prev.set_next(curr)
            else:
                prev = curr
                curr = prev.get_next()
            n += 1

    def task6_2_2(self, k, l):
        curr = self.head
        n = 1
        res = LinkedList()
        while curr != None:
            if not (k < n < l):
                res.push_back(curr.get_data())
            n += 1
            curr = curr.get_next()
        self.head = res.head


    def task6_3(self, k):
        prev = None
        curr = self.head
        if curr != None and curr.get_next() != None:
            n = 0
            while n != k:
                while curr.get_next() != None:
                    prev = curr
                    curr = prev.get_next()
                curr.set_next(self.head)
                self.head = curr
                prev.set_next(None)
                prev = None
                n += 1

    def task7_1(self):
        if not self.is_empty():
            prev = None
            curr = self.head
            while curr != None:
                if curr.get_data() % 3 == 0:
                    curr = curr.get_next()
                    if prev == None:
                        self.head = curr
                    else:
                        prev.set_next(curr)
                else:
                    prev = curr
                    curr = prev.get_next()

    def task7_1_2(self):
        curr = self.head
        res = LinkedList()
        while curr != None:
            if curr.get_data() % 3 != 0:
                res.push_back(curr.get_data())
            curr = curr.get_next()
        self.head = res.head

    def task7_2(self, key):
        prev = None
        curr = self.head
        n = 0
        while curr != None:
            if n % 4 == 0 and n != 0:
                temp = Node(key)
                prev.set_next(temp)
                temp.set_next(curr)
                n = 0
            prev = curr
            curr = prev.get_next()
            n += 1

        if n % 4 == 0 and n != 0:
            temp = Node(key)
            prev.set_next(temp)
            temp.set_next(curr)


    def task7_2_2(self, key):
        curr = self.head
        res = LinkedList()
        n = 1
        while curr != None:
            res.push_back(curr.get_data())
            if n % 4 == 0 and n != 0:
                res.push_back(key)
                n = 0
            curr = curr.get_next()
            n += 1
        self.head = res.head

    def task7_3(self, k):
        if not self.is_empty() and k > 0 and self.head.get_next() != None:
            start = self.head
            n = 0
            prev = self.head
            curr = prev.get_next()
            while curr != None:
                prev = curr
                curr = prev.get_next()
            last = prev

            while n != k:
                self.head = self.head.get_next()
                last.set_next(start)
                start.set_next(None)
                last = start
                start = self.head
                n += 1

    def task7_3_2(self, k):
        if not self.is_empty() and k > 0:
            n = 0
            while n != k:
                self.push_back(self.head.get_data())
                self.head = self.head.get_next()
                n += 1

    def task8_1(self):
        if self.is_empty() == False:
            prev = self.head
            curr = prev.get_next()
            while curr != None:
                if curr.get_data() % 2 == 0:
                    prev.set_next(curr.get_next())
                    curr.set_next(self.head)
                    self.head = curr
                    curr = prev.get_next()
                else:
                    prev = curr
                    curr = prev.get_next()

    def task8_1_2(self):
        curr = self.head
        res = LinkedList()
        while curr != None:
            if curr.get_data() % 2 == 0:
                res.push_front(curr.get_data())
            else:
                res.push_back(curr.get_data())
            curr = curr.get_next()
        self.head = res.head

    def task8_2(self, k, l):
        curr = self.head
        n = 1
        while n < l and curr != None:
            if k < n < l:
                curr.set_data(0)
            curr = curr.get_next()
            n += 1

    def task8_3(self):
        if not self.is_empty():
            curr = self.head
            min = curr.get_data()
            max = curr.get_data()
            while curr != None:
                if curr.get_data() < min:
                    min = curr.get_data()
                if curr.get_data() > max:
                    max = curr.get_data()
                curr = curr.get_next()

            if min != max:
                curr = self.head
                while curr != None:
                    if curr.get_data() == min:
                        curr.set_data(max)
                    elif curr.get_data() == max:
                        curr.set_data(min)
                    curr = curr.get_next()
    
 


my_list = LinkedList()

ls = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10]
for i in ls:
    my_list.push_back(i)

print(my_list)

my_list.task8_3()
print(my_list)
