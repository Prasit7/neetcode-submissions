class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        counter = {}
        counter2 = {}
        for x in s:
            if x in counter:
                counter[x]+=1
            else:
                counter[x] = 1
        
        for g in t:
            if g in counter2:
                counter2[g] += 1
            else:
                counter2[g] = 1
        
        if counter == counter2:
            return True
        else:
            return False


        