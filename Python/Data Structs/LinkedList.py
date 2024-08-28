"""
    Linked List (LL)

        A Data Structure that allow data-access in One Direction.

        Eg :-
        1 --> 2 --> 3 --> None

        Here '1' is the Head of the linked list. [Head = BEGINNING]
        '3' is the Tail. [Tail = END]

        Elements can be accessed in only the direction specified by the arrows.

    How does a Linked List work?

        A Linked List is made up of Nodes.
        Each Node has 2 attributes, VALUE and NEXT.
        
        VALUE stores the data. It could be an int, char, str, etc.
        NEXT stores the memory address of the Node in front. [It's a pointer 🫵]
        
        In the example LL, We have 3 Nodes.
            Node 1: VALUE = '1'     NEXT = Node 2
            Node 2: VALUE = '2'     NEXT = Node 3
            Node 3: VALUE = '3'     NEXT = None
        
        If we also store PREV [the node just behind current], We end up with a DOUBLY LINKED LIST. [A 2-way Linked List. WOOHOOO]
"""

class ListNode:

    def __init__(self, data, next=None) -> None:
        self.value = data
        self.nextNode = next


class LinkedList:

    def __init__(self, head=None) -> None:
        self.head = head
    
    
    def insert(self, node:ListNode) -> None:  
        if self.head is None:
            self.head = node
        else:
            currentNode = self.head
            while True:
                if currentNode.nextNode is None:
                    currentNode.nextNode = node
                    break
                else:
                    currentNode = currentNode.nextNode
