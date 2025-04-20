# Q100. Same Tree
# https://leetcode.com/problems/same-tree/

# First Solution
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        def traverse(p, q):
            if p is None and q is None:
                return True
            
            if p is None or q is None or p.val != q.val:
                return False

            return traverse(p.left, q.left) and traverse(p.right, q.right)
                    
        return traverse(p, q) 