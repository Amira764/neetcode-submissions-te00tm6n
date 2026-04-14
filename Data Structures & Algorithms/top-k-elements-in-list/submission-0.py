class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freqs = Counter(nums)
        top_k = freqs.most_common(k)
        res = []
        for element, _ in top_k:
            res.append(element)
        return res