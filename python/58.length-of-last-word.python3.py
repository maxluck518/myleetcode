from sys import argv
class Solution:
    def lengthOfLastWord(self, s):
        return len(s.rstrip(' ').split(' ')[-1])
if __name__ == '__main__':
    sl = Solution()
    print(sl.lengthOfLastWord(argv[1]))

