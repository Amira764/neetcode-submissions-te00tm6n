class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ""
        for s in strs:
            res += s
            res += "ط"
        return res

    def decode(self, s: str) -> List[str]:
        buffer = ""
        res = []
        for char in s:
            if char=="ط":
                res.append(buffer)
                buffer = ""
            else:
                buffer += char 
        return res       
