class DirectedGraph :


    class Node :

        def __init__(self, initialValue = None, initialMark = 0, *initialNeighbors) :

            self.setValue(initialValue)
            self.setMark(initialMark)

            self.__setNeighbors({ })
            self.addNeighbors(*initialNeighbors)

        #
        # Private Accessors
        #

        def __neighbors(self) :

            return self.__myNeighbors

        #
        # Private Mutators
        #

        def __setNeighbors(self, other) :

            self.__myNeighbors = other

        #
        # Public Mutators
        #

        def setValue(self, other) :

            self.__myValue = other

        def setMark(self, other) :

            self.__myMark = other

        def addNeighbors(self, *additionalNeighbors) :

            for candidateNeighbor in additionalNeighbors :
                if candidateNeighbor not in self.__neighbors() :
                    self.__neighbors()[ candidateNeighbor ] = None

        def removeNeighbors(self, *currentNeighbors) :

            for candidateNeighbor in currentNeighbors :
                if candidateNeighbor in self.__neighbors() :
                    del self.__neighbors()[ candidateNeighbor ]

        #
        # Public Accessors
        #

        def value(self) :

            return self.__myValue

        def mark(self) :

            return self.__myMark

        def neighbors(self) :

            return tuple(self.__neighbors().keys())

        def isNeighbor(self, candidate) :

            return candidate in self.__neighbors()


    from Queue03 import Queue03 as _Queue03


    ########
    ######## A Generic Depth-First Traversal
    ########
    ######## The visit function, isUnmarked predicate, and mark function are supplied as
    ########     parameters
    ######## All nodes reachable from the source are in a marked state at the conclusion of
    ########     the traversal
    ########
    ######## Pre-condition:
    ########     source is not None
    ########     For each node N in the graph, if N is reachable from source,
    ########          isUnmarked(N) = True
    ######## Post-condition:
    ########     For each node N in the graph, if N is reachable from source,
    ########          isUnmarked(N) = False
    ########

    def DFTGeneric(source, visit, isUnmarked, mark) :

        visit(source)

        mark(source)

        for neighbor in source.neighbors() :

            if isUnmarked(neighbor) :

                DirectedGraph.DFTGeneric(neighbor, visit, isUnmarked, mark)


    ########
    ######## A Generic Breadth-First Traversal
    ########
    ######## The visit function, isUnmarked predicate, and mark function are supplied as
    ########     parameters
    ######## All nodes reachable from the source are in a marked state at the conclusion of
    ########     the traversal
    ########
    ######## Pre-condition:
    ########     source is not None
    ########     For each node N in the graph, if N is reachable from source,
    ########          isUnmarked(N) = True
    ######## Post-condition:
    ########     For each node N in the graph, if N is reachable from source,
    ########          isUnmarked(N) = False
    ########

    def BFTGeneric(source, visit, isUnmarked, mark) :

            worklist = DirectedGraph._Queue03()

            mark(source)
            worklist.insert(source)

            while not worklist.isEmpty() :

                source = worklist.remove()

                visit(source)

                for neighbor in source.neighbors() :
                    if isUnmarked(neighbor) :
                        mark(neighbor)
                        worklist.insert(neighbor)


    ########
    ######## Depth-First Traversal
    ########
    ######## Pre-condition:
    ########     For each node N in the graph, if N is reachable from source, N's mark is 0
    ######## Post-condition:
    ########     For each node N in the graph, if N is reachable from source, N's mark is 0
    ########


    def DFT(source, visit) :

        if source != None :

            #
            # Visit the nodes reachable from source in depth-first order,
            # leaving the visited nodes marked with a 1
            #

            DirectedGraph.DFTGeneric(
                source,
                visit,
                lambda node : node.mark() == 0,
                lambda node : node.setMark(1)
                )

            #
            # Visit the nodes reachable from source in depth-first order,
            # leaving the visited nodes marked with a 0
            #

            DirectedGraph.DFTGeneric(
                source,
                lambda node : None,
                lambda node : node.mark() != 0,
                lambda node : node.setMark(0)
                )


    ########
    ######## Breadth-First Traversal
    ########
    ######## Pre-condition:
    ########     For each node N in the graph, if N is reachable from source, N's mark is 0
    ######## Post-condition:
    ########     For each node N in the graph, if N is reachable from source, N's mark is 0
    ########


    def BFT(source, visit) :

        if source != None :

            #
            # Visit the nodes reachable from source in breadth-first order,
            # leaving the visited nodes marked with a 1
            #

            DirectedGraph.BFTGeneric(
                source,
                visit,
                lambda node : node.mark() == 0,
                lambda node : node.setMark(1)
                )

            #
            # Visit the nodes reachable from source in depth-first order,
            # leaving the visited nodes marked with a 0
            #

            DirectedGraph.DFTGeneric(
                source,
                lambda node : None,
                lambda node : node.mark() != 0,
                lambda node : node.setMark(0)
                )


    ########
    ######## Topological-Order Traversal
    ########
    ######## Pre-condition:
    ########     For each node N in the graph, if N is reachable from source, N's mark is 0
    ######## Post-condition:
    ########     For each node N in the graph, if N is reachable from source, N's mark is 0
    ########


    ####
    #### This version of a TOT traversal aborts the traversal before any visitations are done
    #### if the graph is found to contain cycles
    ####
    #### Pre-condition:
    ####     For each node N in the graph, if N is reachable from source, N's mark is 0
    #### Post-condition:
    ####     For each node N in the graph, if N is reachable from source, N's mark is 0
    ####


    def dagTOT(source, visit) :

        if source != None :

            try :

                #
                # Mark each node with its indegree
                #

                dagTOTPhase1(source)

                #
                # Perform visits in topological order
                #

                dagTOTPhase2(source, visit)

            except :

                #
                # If a cycle was encountered, Phase 1 will have aborted, possibly leaving
                # some nodes in the graph marked with non-zero values.  So, erase any such
                # marks.
                #

                DirectedGraph.DFTGeneric(
                    source,
                    lambda node : None,
                    lambda node : node.mark() != 0,
                    lambda node : node.setMark(0)
                    )


    ####
    #### Using a modified DFT, mark each node with its indegree
    #### If a cycle is encountered, throw an exception
    ####
    #### Pre-condition:
    ####     source is not None
    ####     For each node N in the graph, if N is reachable from source, N's mark is 0
    #### Post-condition:
    ####     If the portion of the graph reachable from source is a DAG,
    ####         for each node N in the graph, if N is reachable from source, N's mark is N's
    ####             indegree
    ####     If the portion of the graph reachable from source is not a DAG,
    ####         for each node N in the graph that was reached before the cycle was
    ####         encountered, N's mark is non-zero
    ####


    def dagTOTPhase1(source) :

        #
        # NOTE:  The mark on source necessarily has the value 0 (is source is the node from
        # which Phase 1 originated) of the value 1
        #

        #
        # Set the mark on source to a negative number (indicating that the traversal is in
        # the midst of attempting to initiate the marking of source's neighbors, which may
        # cascade to attempts to initiate the marking of source's neighbor's neighbors) in a
        # way that the initial value of the mark can be recovered later
        #

        source.setMark(source.mark() - 2)

        for neighbor in source.neighbors() :

            #
            # If a neighbor of source has a negative mark, that means that the traversal is
            # still in the process of marking that neighbor's neighbors.  Since the traversal
            # could only encounter such a node if the graph contains a cycle, abort Phase 1
            #

            if neighbor.mark() < 0 :

                raise ValueError('Attempted a TOT of a digraph having cycles')

            #
            # Otherwise,
            #     increase the neighbor's mark by 1, indicating that an additional edge
            #         into that neighbor has been discovered
            #     If this is the first encounter with that neighbor, initiate marking that
            #         neighbor's neighbors

            else :

                neighbor.setMark(neighbor.mark() + 1)

                if neighbor.mark() == 1 :
                    dagTOTPhase1(neighbor)

        #
        # Set the mark on source back to its initial value (indicating that the traversal has
        # completed its attempt to initiate marking of source's neighbors)
        #

        source.setMark(source.mark() + 2)


    ####
    #### Using a modified DFT, reduce the mark on each node each time it's encountered
    #### Once a neighbor's mark has been reduced to zero, recursively continue the DFT from
    ####     that neighbor
    ####
    #### Pre-condition:
    ####     source is not None
    ####     For each node N in the graph, if N is reachable from source, N's mark is N's
    ####         indegree
    #### Post-condition:
    ####     For each node N in the graph, if N is reachable from source, N's mark is 0
    ####


    def dagTOTPhase2(source, visit) :

        visit(source)

        for neighbor in source.neighbors() :

            neighbor.setMark(neighbor.mark() - 1)

            if neighbor.mark() == 0 :
                dagTOTPhase2(neighbor, visit)


    ########
    ######## A Generic Depth-First Seacrh
    ########
    ######## The isTarget predicate, isUnmarked predicate, and mark function are
    ########     supplied as parameters
    ######## Nodes reachable from the source that were visited before the search
    ########     terminated are in a marked state at the conclusion of the search
    ########
    ######## Pre-condition:
    ########     source is not None
    ########     For each node N in the graph, if N is reachable from source,
    ########          isUnmarked(N) = True
    ######## Post-condition:
    ########     For each node N in the graph, if N is reachable from source,
    ########          isUnmarked(N) = False
    ########     If a path was found, the suffix of pathToTarget has been mutated
    ########         to contain the path
    ########
    ######## Note the way the the path is built by mutating the pathToTarget
    ########     formal parameter in a precise and careful manner.
    ########

    def DFSGeneric(source, isTarget, isUnmarked, mark, pathToTarget) :
        if isUnmarked(source) :

            mark(source)
            pathToTarget.append(source)
            targetHasBeenFound = isTarget(source)
            neighbors = source.neighbors()

            neighborsPosition = 0
            while not targetHasBeenFound and neighborsPosition < len(neighbors) :
                targetHasBeenFound \
                    = DirectedGraph.DFSGeneric(
                        neighbors[ neighborsPosition ],
                        isTarget,
                        isUnmarked,
                        mark,
                        pathToTarget
                        )
                neighborsPosition += 1

            if not targetHasBeenFound :
                pathToTarget.pop()

            return targetHasBeenFound

        else :
            return False


    ########
    ######## A Generic Breadth-First Seacrh
    ########
    ######## The isTarget predicate, isUnmarked predicate, and mark function are
    ########     supplied as parameters
    ######## Nodes reachable from the source that were visited before the search
    ########     terminated are in a marked state at the conclusion of the search
    ########
    ######## Pre-condition:
    ########     source is not None
    ########     For each node N in the graph, if N is reachable from source,
    ########          isUnmarked(N) = True
    ######## Post-condition:
    ########     For each node N in the graph, if N is reachable from source,
    ########          isUnmarked(N) = False
    ########     If a path was found, the suffix of pathToTarget has been mutated
    ########         to contain the path
    ########
    ######## Note the way the function builds up the path *in reverse*
    ######## as a pair-based structure of nodes.  The list-mutation approach use#
    ######## by the DFSGeneric function above will *not* work here.
    ########

    def BFSGeneric(source, isTarget, isUnmarked, mark, pathToTarget) :

        if isUnmarked(source) :

            worklist = DirectedGraph._Queue03()
            targetHasBeenFound = False
            reversedPathAsPairs = None

            mark(source)
            worklist.insert((source, reversedPathAsPairs))

            while not targetHasBeenFound and not worklist.isEmpty() :

                (source, reversedPathAsPairs) = worklist.remove()

                targetHasBeenFound = isTarget(source)

                reversedPathAsPairs = (source, reversedPathAsPairs)

                if not targetHasBeenFound :

                    for neighbor in source.neighbors() :
                        if isUnmarked(neighbor) :
                            mark(neighbor)
                            worklist.insert((neighbor, reversedPathAsPairs))

            if targetHasBeenFound :

                DirectedGraph.appendReversedPathAsPairsToPath(
                    reversedPathAsPairs,
                    pathToTarget
                    )

                return True

            else :
                return False

        else :

            return False


    ####
    #### Utility Function
    ####

    def appendReversedPathAsPairsToPath(reversedPathAsPairs, path) :

        if reversedPathAsPairs != None :

            DirectedGraph.appendReversedPathAsPairsToPath(reversedPathAsPairs[ 1 ], path)
            path.append(reversedPathAsPairs[ 0 ])


    ########
    ######## Depth-First Search
    ########
    ######## Returns a path (a list of nodes) from the source to the target, where an
    ######## unsuccessful search results in an empty path
    ########

    def DFS(source, isTarget) :

        path = [ ]

        if source != None :

            #
            # Traverse the portion of the graph reachable from source until either a
            # node N such that isTarget(N) == True is encountered or all the reachable
            # nodes have been visited, leaving path mutated to hold the path (if a path
            # was found) and leaving all the visited nodes marked with a 1
            #

            targetHasBeenFound \
                = DirectedGraph.DFSGeneric(
                    source,
                    isTarget,
                    lambda node : node.mark() == 0,
                    lambda node : node.setMark(1),
                    path
                    )

            #
            # Traverse the portion of the graph that was searched,
            # leaving the visited nodes marked with a 0
            #

            DirectedGraph.DFTGeneric(
                source,
                lambda node : None,
                lambda node : node.mark() != 0,
                lambda node : node.setMark(0)
                )

        return path


    ########
    ######## Breadth-First Search
    ########
    ######## Returns a path (a list of nodes) from the source to the target, where an
    ######## unsuccessful search results in an empty path
    ########

    def BFS(source, isTarget) :

        path = []

        if source != None :

            #
            # Traverse the portion of the graph reachable from source until either a
            # node N such that isTarget(N) == True is encountered or all the reachable
            # nodes have been visited, leaving path mutated to hold the path (if a path
            # was found) and leaving all the visited nodes marked with a 1
            #

            DirectedGraph.BFSGeneric(
                source,
                isTarget,
                lambda node : node.mark() == 0,
                lambda node : node.setMark(1),
                path
                )

            #
            # Traverse the portion of the graph that was searched,
            # leaving the visited nodes marked with a 0
            #

            DirectedGraph.DFTGeneric(
                source,
                lambda node : None,
                lambda node : node.mark() != 0,
                lambda node : node.setMark(0)
                )

        return path
