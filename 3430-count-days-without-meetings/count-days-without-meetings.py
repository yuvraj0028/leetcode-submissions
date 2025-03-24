class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        meetings.sort()

        n = len(meetings)
        ans = 0

        first = meetings[0][0]
        last = meetings[0][1]

        for i in range(1, n):
            curr_first = meetings[i][0]
            curr_last = meetings[i][1]

            if curr_first > last:
                ans += curr_first - last - 1

            last = max(last, curr_last)

        if first != 1:
            ans += first - 1

        if last < days:
            ans += days - last

        return ans
