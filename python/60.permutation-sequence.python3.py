#  range != list
class Solution:
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """ 
        tmp = 1
        num = []
        pos = []
        k = k - 1
        rtl = ''
        for i in range(1,n) :
            tmp = tmp * i
            num.append(tmp)
        num = num[::-1]
        for i in range(0,n-1) :
            pos.append(int(k / num[i]))
            k = k % num[i]
        pos.append(0)
        numbers = list(range(1,n+1))
        for item in pos :
            rtl = rtl + str(numbers[item])
            del numbers[item]
        return rtl

#  from sys import argv
#  if __name__ == '__main__' :
    #  s = Solution()
    #  n = int(argv[1])
    #  k = int(argv[2])
    #  s.getPermutation(n,k)

            
