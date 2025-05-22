class Solution:
    def reverse(self, x: int) -> int:
        if x == 0 or x < -2**31 or x > 2**31 - 1 :
            return 0
        
        listX = [digit for digit in str(x)]
        revX = listX[::-1]
        size = len(revX)
        print(revX)
        if revX[size - 1] == "-":
                temp = revX[0]
                revX[0] = "-"
                for ele in range(1, size - 1):
                    temp2 = revX[ele]
                    revX[ele] = temp
                    temp = temp2
                    print(temp)
                print(revX)
                if revX[size - 1] == "-":
                    revX[size - 1] = temp
        if int("".join(map(str,revX)))  < -2**31 or int("".join(map(str,revX))) > 2**31 - 1:
            return 0 
        if revX[size - 1] == "0":
            revX.pop()      
        return int("".join(map(str, revX)))
