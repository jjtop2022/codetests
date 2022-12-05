#
# A Linked-List-Based Queue Class
#
# This version uses a linked list with a header node
#


from LinkedListNode import *


class Queue03 :

    #
    # Protected Class Attributes
    #

        _ourErrorReturnItem = None

    #
    # Private Accessors
    #

        def __firstNode(self) :

            return self.__myFirstNode

        def __lastNode(self) :

            return self.__myLastNode

    #
    # Private Mutators
    #

        def __setFirstNode(self, other) :

            self.__myFirstNode = other

        def __setLastNode(self, other) :

            self.__myLastNode = other

    #
    # Protected Mutators
    #

        def _setError(self, other) :

            self.__myLastOperationCausedError = other

    #
    # Constructor
    #

        def __init__(self) :

            self._setError(False)
            self.__setFirstNode(LinkedListNode())
            self.__setLastNode(self.__firstNode())

    #
    # Public Accessors
    #

        def error(self) :

            return self.__myLastOperationCausedError

        def isEmpty(self) :

            return self.__firstNode().tail() == None

        def isFull(self) :

            return False

        def toString(self) :

            result = [ '<<Queue03: front ' ]

            node = self.__firstNode().tail()

            while node != None :

                result.append('[')
                result.append(str(node.head()))
                result.append('] ')

                node = node.tail()

            result.append('rear, error = ')
            result.append(str(self.error()))
            result.append('>>')

            return ''.join(result)

        def front(self) :

            self._setError(self.isEmpty())

            if self.error() :

                return Queue03._ourErrorReturnItem

            else :

                return self.__firstNode().tail().head()

    #
    # Public Mutators
    #

        def insert(self, additionalItem) :

            self._setError(self.isFull())

            if not self.error() :

                self.__lastNode().setTail(LinkedListNode(additionalItem, None))

                self.__setLastNode(self.__lastNode().tail())

        def remove(self) :

            self._setError(self.isEmpty())

            if self.error() :

                return Queue03._ourErrorReturnItem

            else :

                formerFrontItem = self.front()

                self.__firstNode().setTail(self.__firstNode().tail().tail())

                if self.isEmpty() :
                    self.__setLastNode(self.__firstNode())

                return formerFrontItem

        def assign(self, other) :

            if self is not other :

                self.__init__()

                otherNode = other.__firstNode().tail()

                while otherNode != None :

                    self.insert(otherNode.head())

                    otherNode = otherNode.tail()
