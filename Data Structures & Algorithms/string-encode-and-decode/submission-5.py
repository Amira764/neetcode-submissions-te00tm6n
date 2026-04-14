class Solution:

    def encode(self, strs: List[str]) -> str:
        if len(strs)==0:
            return 'nothing'
        return "-".join(strs)
    def decode(self, s: str) -> List[str]:
        if s == 'nothing':
            return []
        return s.split('-')