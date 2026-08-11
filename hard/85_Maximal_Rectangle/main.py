class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        h = len(matrix)
        w = len(matrix[0])
        continuousH = [0 for _ in range(w)]
        maxArea = float('-inf')

        for i in range(h):
            for j in range(w):
                if matrix[i][j] == '1':
                    continuousH[j] += 1
                else:
                    continuousH[j] = 0

            for start in range(w):
                minH = float('inf')
                maxW = float('-inf')
                for end in range(start, w):
                    minH = min(minH, continuousH[end])
                    maxW = end - start + 1
                    maxArea = max(maxArea, minH*maxW)

        return maxArea


        
