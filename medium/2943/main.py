class Solution:
    def maximizeSquareHoleArea(self, n: int, m: int, hBars: List[int], vBars: List[int]) -> int:
        side = 1

        hcurr = 1
        wcurr = 1

        hmax = 1
        wmax = 1

        hBars.sort()
        vBars.sort()
        
        for i in range(1, len(hBars)):
            if hBars[i] - hBars[i-1] == 1:
                hcurr += 1
            else:
                hcurr = 1
            hmax = max(hmax, hcurr)

        for i in range(1, len(vBars)):
            if vBars[i] - vBars[i-1] == 1:
                wcurr += 1
            else:
                wcurr = 1
            wmax = max(wmax, wcurr)

        side = min(hmax, wmax) + 1


        return side * side;
