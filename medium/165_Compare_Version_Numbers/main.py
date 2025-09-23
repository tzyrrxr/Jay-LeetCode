class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        n1 = version1.split('.')
        n2 = version2.split('.')
        l1 = len(n1)
        l2 = len(n2)
        if (l1 < l2):
            index = l2
        else: 
            index = l1

        for i in range(index):
            if (i >= l1):
                c1 = 0
            else:
                c1 = int(n1[i])

            if (i >= l2):
                c2 = 0
            else:
                c2 = int(n2[i])

            if (c1 > c2):
                return 1
            elif (c1 < c2):
                return -1

        return 0
        
