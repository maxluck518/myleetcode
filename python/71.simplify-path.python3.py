class Solution:
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        sub_path = path.split('/')
        #  print(sub_path)
        rtl_sub_path = []
        rtl_path = ''
        flag = 0
        for item in sub_path :
            if item == '..' :
                if(len(rtl_sub_path) != 0) :
                    del rtl_sub_path[-1]
            elif item == '.' : pass
            elif item == '' : flag = 1
            else :
                rtl_sub_path.append(item)
        #  print(rtl_sub_path)
        #  for item in rtl_sub_path :
            #  rtl_path = rtl_path + '/' + item
        rtl_path = '/' + '/'.join(rtl_sub_path)
        #  if flag == 1 and len(rtl_sub_path) == 0 :
            #  rtl_path = '/'
        return rtl_path

from sys import argv
if __name__ == '__main__' :
    s = Solution()
    print(s.simplifyPath(argv[1]))


