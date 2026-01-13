class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        totalArea = 0
        height = float('-inf')
        low = 0
        ansY = 0
        for i in range(len(squares)):
            totalArea += squares[i][2] * squares[i][2]
            height = max(height, squares[i][1] + squares[i][2])

        while (height - low > 1e-5):
            ansY = (height + low)/2
            aboveArea = 0
            for i in range(len(squares)):
                if squares[i][1] > ansY:
                    aboveArea += squares[i][2] * squares[i][2]
                elif squares[i][1] + squares[i][2] > ansY:
                    aboveArea += (squares[i][1] + squares[i][2] - ansY) * squares[i][2]

            if aboveArea * 2 > totalArea:
                low = ansY
            else:
                height = ansY

        return ansY


        
