#
# Note:
#     All the methods in this class have been defined/named as being public.  Since we
#     will only be using this class as part of other classes, clients won't be able to
#     exploit this usually unsafe public-ness.
#


class LinkedListNode :

    def __init__(self, initialHead = None, initialTail = None) :

        self.setHead(initialHead)
        self.setTail(initialTail)

    def setHead(self, other) :

        self.__myHead = other

    def setTail(self, other) :

        self.__myTail = other

    def head(self) :

        return self.__myHead

    def tail(self) :

        return self.__myTail
