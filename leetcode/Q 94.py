# 94. Binary Tree Inorder Traversal
# https://leetcode.com/problems/binary-tree-inorder-traversal/description/

# First Attempt
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:

        def traverse(root, result):
            if root is not None:
                traverse(root.left, result)
                result.append(root.val)
                traverse(root.right, result)
                return result
            
        if root is not None:
            return traverse(root, [])
        else:
            return []