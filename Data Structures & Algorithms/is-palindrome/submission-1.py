class Solution:
    def isPalindrome(self, s: str) -> bool:
        alphaneumeric = filter(str.isalnum, s)
        one_string = "".join(alphaneumeric)
        lowercase = one_string.lower()
        print(lowercase)

        i = 0
        j = len(lowercase) - 1

        if len(lowercase) == 0:
            return True

        while i <= j+1:
            if lowercase[i] != lowercase[j]:
                return False
            else:
                i += 1
                j -= 1
        
        return True
        