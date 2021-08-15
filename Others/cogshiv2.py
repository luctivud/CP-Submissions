class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Sol:
    def solvetree(cls, n, inOrder, preOrder):
        def buildTree(inOrder, preOrder, inStrt, inEnd):
            if (inStrt > inEnd):
                return None
            tNode = Node(preOrder[buildTree.preIndex])
            buildTree.preIndex += 1
            if inStrt == inEnd :
                return tNode
            inIndex = search(inOrder, inStrt, inEnd, tNode.data)
            tNode.left = buildTree(inOrder, preOrder, inStrt, inIndex-1)
            tNode.right = buildTree(inOrder, preOrder, inIndex + 1, inEnd)
            return tNode    
        def search(arr, start, end, value):
            for i in range(start, end + 1):
                if arr[i] == value:
                    return i
        buildTree.preIndex = 0
        root = buildTree(inOrder, preOrder, 0, len(inOrder)-1)

        cls.oddDep = cls.evenDep = 0
        def traverse(root, dep):
            if root.left:
                traverse(root.left, dep+1)
            root.value = inOrder[traverse.ind] 
            if dep & 1:
                cls.oddDep += root.value
            else:
                cls.evenDep += root.value
            traverse.ind += 1
            if root.right:
                traverse(root.right, dep+1)
        inOrder.sort()
        traverse.ind = 0
        traverse(root, 0)
        return cls.evenDep - cls.oddDep





obj = Sol()
# print(obj.solvetree(3, [5, 4, 6], [4, 5, 6]))
print(obj.solvetree(2, [5, 4], [4, 5]))