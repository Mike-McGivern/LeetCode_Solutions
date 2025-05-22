#class Solution(object):
 #   def partitionString(self, s):
class Solution:
    def partitionString(self, s):
        res, v = 1, 0
        for c in s:
            i = ord(c) - ord('a')
            if (v >> i) & 1:
                v = 0
                res += 1
            v |= 1 << i
        return res
  #      """
   #     :type s: str
    #    :rtype: int
     #   """
        
