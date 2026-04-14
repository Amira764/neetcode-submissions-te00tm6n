class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        def isAnagram(s: str, t:str):
            return Counter(s) == Counter(t)
        
        output = []
        visited = [False] * len(strs)
        for i in range(len(strs)):
            if visited[i]:
                continue
            local_list = []
            local_list.append(strs[i])
            visited[i] = True
            for j in range(i+1, len(strs)):
                if not visited[j] and isAnagram(strs[i], strs[j]):
                    local_list.append(strs[j])
                    visited[j] = True
            output.append(local_list)
        return output
